#lang racket

; export bindings
(provide test)

; instantiated by require form in the top-level
(display "I am module 'part1'")

(define (test)
  (display "Call function provided by 'part1' module"))

(define (test-private)
  (display "Call function not provided by 'part1' module"))