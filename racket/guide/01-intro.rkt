#lang racket

;number
42

;string
"Hello World"

;function call
(substring "the boy out of the country" 4 7)

;function definition
(define (extract str)
    (substring str 4 7))
