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
(string-append "a" "b" "c") ; "abc"
(number? 1)                 ; #t
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

;List
(list "a" "b" "c" "d")
(list 1 "abc")

;List operations
(define alist
  (list 1 2 3))
(length alist)          ; 3
(list-ref alist 0)      ; 1
(append alist (list 4)) ; '(1 2 3 4)
(reverse alist)         ; '(3 2 1)
(member 1 alist)        ; '(1 2 3)
(member 0 alist)        ; #f
(car alist)             ; 1
(cdr alist)             ; '(2 3)
(empty? alist)          ; #f
(cons (car alist)
      (cdr alist))      ; '(1 2 3)
(cons 1 (cons 2 empty)) ; '(1 2)

;Map, filter, fold
(map (lambda (x) (* 2 x)) alist)                ; '(2 4 6)
(andmap even? alist)                            ; #f
(ormap even? alist)                             ; #t
(filter even? alist)                            ; '(2)
(foldl (lambda (elem sum) (+ sum elem))0 alist) ; 6

;List iteration
(define (my-length l)
  (if (empty? l)
      0
      (+ 1 (my-length (cdr l)))))
(define (my-map f l)
  (if (empty? l)
      l
      (cons (f (car l)) (my-map f (cdr l)))))

;Tail recursion
(define (length-iter l)
  (define (aux l acc)
    (if (empty? l)
        acc
        (aux (cdr l) (+ acc 1))))
  (aux l 0))
(define (map-iter f l)
  (define (aux l acc)
    (if (empty? l)
        (reverse acc)
        (aux (cdr l) (cons (f (car l)) acc))))
  (aux l empty))

;Pair
(cons 1 2)
(pair? (cons 1 2)) ; #t
(pair? (list 1 2)) ; #t

;Quote
;Turn a sequence of characters into lists, symbols, and constants
(quote (1 2 3))
'(1 2 3)
(quote i-am-an-identifier) ; 'i-am-an-identifier
(car (quote (a b)))        ; 'a
(quote 42)                 ; 42
(quote "string")           ; "string"
(car ''test)               ; 'quote

;Infix notation
'(1 . < . 2)
(1 . < . 2)
