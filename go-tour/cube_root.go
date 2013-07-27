package main

import (
    "fmt"
    "math/cmplx"
)

func Cbrt(x complex128) complex128 {
    const eps = 1e-6
    z := x
    for d := 1.0i; cmplx.Abs(d) > eps; {
        d = (z*z*z-x)/(3*z*z)
        z -= d
    }
    return z
}

func main() {
    fmt.Println(Cbrt(2))
}
