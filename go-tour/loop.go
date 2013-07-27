package main

import (
    "fmt"
)

func Sqrt(x float64) float64 {
    const eps = 1e-6
    z := x
    for d := 1.0; d > eps; {
        d = (z*z-x)/(2*z)
        z -= d
    }
    return z
}

func main() {
    fmt.Println(Sqrt(2))
}
