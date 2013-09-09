#lang racket

;Numbers
1
1/2
1+2i
3.14

;Boolean
#t
#f

;String
"Hello World"
"Benjamin \"Bugsy\" Siegel"
"λx:(μα.α→α).xx"

;Definition
(define v 42)
(define (f x)
  (+ x 1))
(define (g s)
  (printf "append a newline character\n")
  (string-append s "\n"))

;Identifier
(define pass/fail 0)
(define john-jacob-jingleheimer-schmidt 0)
(define a-b-c+1-2-3 0)

;Function call
(string-append "a" "b" "c")
(number? 1)
(define (double v)
  ((if (string? v) string-append +) v v))

;Conditional
;if
(define (odd? i)
  (if (= 1 (remainder i 2))
      "yes"
      "no"))
;and
(define (positive-even? i)
  (if (and (number? i)
           (>= i 0)
           (equal? 2 (remainder i 2)))
      "yes"
      "no"))
;cond
(define (sign i)
  (cond
    [(< i 0) "negative"]
    [(>= i 0) "positive"]
    [else "huh? tertium non datur"]))

;Lambda
(lambda (x) (+ x 1))

;Lexical scope
(define (inc i)
  (lambda (x) (+ x i)))
(define inc-1
  (inc 1))
(define inc-2
  (inc 2))

;Nested definition
(define (x+y x y)
  (define op +)
  (op x y))

;Let
(define (x-y x y)
  (let ([op -])
    (op x y)))

;Let*
(define (x*y x y)
  (let* ([op *]
         [rst (op x y)])
    rst))
