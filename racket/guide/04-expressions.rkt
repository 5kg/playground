#lang racket
; = Binding =
; Lexical scoping
(define var 1)
(define (foo) var)
(let ([var 2]) (foo)) ; 1

; Shadowing
;(define cons "cons")
;(define define "define")
;(let [(cons "local cons ")]
;  (string-append cons define)) ; "local cons define"

; = Procedure application =
; Evaluation Order and Arity
(define (one)
  (display "one ")
  1)
(define (two)
  (display "two ")
  2)
(define (three)
  (display "three")
  3)
(define (bar a b [c #f])
  (display "bar"))

(bar (one) (two) (three)) ; one two three bar
(bar (one) (two)) ; one two bar

;Keyword Arguments
(define (f str #:hd hd #:tl tl)
  (string-append hd str tl))
(f "two" #:hd "one-" #:tl "-three") ; "one-two-three"
(f #:hd "one-" #:tl "-three" "two") ; "one-two-three"
(f #:hd "one-" "two" #:tl "-three") ; "one-two-three"

; Apply
(define (avg lst)
  (/ (apply + lst) (length lst)))
(avg '(1 2 3))                    ; 2
(apply + 1 2 3 '(4 5))            ; 15
(keyword-apply f
               '(#:hd #:tl)
               '("one-" "-three")
               '("two"))          ; "one-two-three"

; = Lambda =
; Rest Argument
((lambda (x) x) 1) ; 1
((lambda x x) 1)   ; '(1)
((lambda x x) 1 2) ; '(1 2)

(define abs-sum
  (lambda x (apply +
                   (map abs x))))
(abs-sum -1 1 1)   ; 3

(define map-sum
  (lambda (fn . args)
    (apply + (map fn args))))
(map-sum abs -1 1 1) ; 3

; Optional Arguments
(define inc
  (lambda (v [off 1])
    (+ v off)))
(inc 1)   ; 2
(inc 1 2) ; 3

; Keyword Arguments
(define kf
  (lambda (a #:b b #:c [c "c"])
    (list a b c)))
(kf "a" #:b "b" #:c "c") ; '("a" "b" "c")
(kf "a" #:b "b")         ; '("a" "b" "c")

(define rest-keywords
  (make-keyword-procedure
   (lambda (kws kw-args . rest)
     (list kws kw-args rest))))
(rest-keywords 1 2 3)               ; '(() () (1 2 3))
(rest-keywords 1 #:two 2 #:three 3) ; '((#:three #:two) (3 2) (1))

; case-lambda
(define inc-case
  (case-lambda
    [(v) (+ v 1)]
    [(v off) (+ v off)]))
(inc-case 1)   ; 2
(inc-case 1 2) ; 3

(define case-λ-test
  (case-lambda
    [(a b) (display "Case 1")]
    [(a . rest) (display "Case 2")]))
(case-λ-test 1)     ; Case 2
(case-λ-test 1 2)   ; Case 1
(case-λ-test 1 2 3) ; Case 2