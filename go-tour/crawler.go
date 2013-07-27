package main

import (
    "fmt"
)

type Fetcher interface {
    // Fetch returns the body of URL and
    // a slice of URLs found on that page.
    Fetch(url string) (body string, urls []string, err error)
}

type Record struct {
    Url string
    Depth int
}

// Crawl uses fetcher to recursively crawl
// pages starting with url, to a maximum of depth.
func Crawl(url string, depth int, fetcher Fetcher) {
    visited := make(map[string] bool)
    num := 0
    done := make(chan bool)
    ch := make(chan Record)
    go func() { ch <- Record{ url, 0 } }()
    for {
        // This is to channel ch
        d := done
        if len(ch) > 0 {
            d = nil
        }
        select {
        case rec := <- ch:
            if !visited[rec.Url] {
                visited[rec.Url] = true
                num++
                go func(url string, depth int) {
                    body, urls, err := fetcher.Fetch(url)
                    if err != nil {
                        fmt.Println(err)
                        done <- true
                        return
                    }
                    fmt.Printf("found: %s %q\n", url, body)
                    for _, u := range urls {
                        ch <- Record{ u, depth + 1 }
                    }
                    done <- true
                } (rec.Url, rec.Depth)
            }
        case <- d:
            num--
            if num == 0 {
                return
            }
        }
    }
}

func main() {
    Crawl("http://golang.org/", 4, fetcher)
}

// fakeFetcher is Fetcher that returns canned results.
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
    body string
    urls []string
}

func (f *fakeFetcher) Fetch(url string) (string, []string, error) {
    if res, ok := (*f)[url]; ok {
        return res.body, res.urls, nil
    }
    return "", nil, fmt.Errorf("not found: %s", url)
}

// fetcher is a populated fakeFetcher.
var fetcher = &fakeFetcher{
    "http://golang.org/": &fakeResult{
        "The Go Programming Language",
        []string{
            "http://golang.org/pkg/",
            "http://golang.org/cmd/",
        },
    },
    "http://golang.org/pkg/": &fakeResult{
        "Packages",
        []string{
            "http://golang.org/",
            "http://golang.org/cmd/",
            "http://golang.org/pkg/fmt/",
            "http://golang.org/pkg/os/",
        },
    },
    "http://golang.org/pkg/fmt/": &fakeResult{
        "Package fmt",
        []string{
            "http://golang.org/",
            "http://golang.org/pkg/",
        },
    },
    "http://golang.org/pkg/os/": &fakeResult{
        "Package os",
        []string{
            "http://golang.org/",
            "http://golang.org/pkg/",
        },
    },
}
