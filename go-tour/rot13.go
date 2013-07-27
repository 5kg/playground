package main

import (
    "io"
    "os"
    "strings"
    "unicode"
)

type rot13Reader struct {
    r io.Reader
}

func (rot13 rot13Reader) Read(p []byte) (n int, err error) {
    n, err = rot13.r.Read(p)
    if err == nil {
        for i, v := range p {
            if unicode.IsLower(rune(v)) {
            	p[i] = (v - 'a' + 13) % 26 + 'a'
            }
            if unicode.IsUpper(rune(v)) {
            	p[i] = (v - 'A' + 13) % 26 + 'A'
            }
        }
    }
    return
}

func main() {
    s := strings.NewReader(
        "Lbh penpxrq gur pbqr!")
    r := rot13Reader{s}
    io.Copy(os.Stdout, &r)
}
