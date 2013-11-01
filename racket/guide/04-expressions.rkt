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

; = Define =
(define (func a [b "b"] #:c [c "c"] . rest)
  (list a b c rest))
(func "a")                       ; ("a" "b" "c" ())
(func "a" "bb")                  ; ("a" "bb" "c" ())
(func "a" "bb" "d" "e")          ; '("a" "bb" "c" ("d" "e"))
(func "a" "bb" "d" "e" #:c "cc") ; '("a" "bb" "cc" ("d" "e"))

; Curried Function
(define (add c)
  (lambda (x) (+ x c)))
(define add-1 (add 1))
(add-1 2) ; 3

(define ((add-curry c) x)
  (+ x c))
(define add-2 (add-curry 2))
(add-2 1) ; 3

; Multiple Values and define-values
(define (rat-multiply a1 b1 a2 b2)
  (values (* a1 a2) (* b1 b2)))
(rat-multiply 2 5 1 3) ; 2 \n 15
(define-values (n d) (rat-multiply 2 5 1 3))
(list n d)             ; '(2 15)

; Internal Definitions
(define (internal-def)
  (define x 1)
  (display x)
  (define y (+ x 1))
  (define z y)
  (display z))
(internal-def) ; 12

; = Local Binding =
; Parallel Binding: let
(let [(x 1)
      (y 2)]
  (list x y)) ; '(1 2)

(define avar "outside")
(let [(avar "inside")
      (v avar)]
  v) ; "outside"

; Sequential Binding: let*
(let* [(avar "inside")
      (v avar)]
  v) ; "inside"

(let* [(a "i am a")
      (b a)]
  b) ; "i am a"

(let* [(a 1)
      (a 2)]
  a) ; 2

; a let* form is equivalent to nested let forms
(equal?
 (let* ([a 1]
        [b (+ a 1)])
   (list a b))
 (let ([a 1])
   (let ([b (+ a 1)])
   (list a b)))) ; #t

; Recursive Binding: letrec
(letrec
    ([odd? (lambda (x) (if (= x 0) #f (even? (- x 1))))]
     [even? (lambda (x) (if (= x 0) #t (odd? (- x 1))))])
  (list (odd? 5) (even? 5) (odd? 4))) ; '(#t #f #f)

(letrec ([x y]
         [y 1])
  (list x y)) ; '(#<undefined> 1)

; Named let
(define (map-iter f lst)
  (let loop ([acc null] [lst lst])
    (if (null? lst)
        acc
        (loop (cons (f (car lst)) acc)
              (cdr lst)))))
(map-iter even? '(1 2 3 4 5)) ; '(#f #t #f #t #f)

(define (map-iter-letrec f lst)
  (letrec ([loop (lambda (acc lst)
                   (if (null? lst)
                       acc
                       (loop (cons (f (car lst)) acc)
                             (cdr lst))))])
    (loop null lst)))
(map-iter-letrec even? '(1 2 3 4 5)) ; '(#f #t #f #t #f)

; Multiple Values: let-values, let*-values, letrec-values
(let-values ([(a b c) (values 1 2 3)])
  (list a b c)) ; '(1 2 3)
(let*-values ([(a b) (values 1 2)]
              [(c) (+ a b)])
  (list a b c)) ; '(1 2 3)

; = Conditionals =
(and #f (display "!!!")) ; #<void>
(or #t (display "!!!")) ; #<void>

; Tail-recursion
(define (contains? lst elem)
  (and (not (null? lst))
       (or (equal? elem (car lst))
           (contains? (cdr lst) elem))))
(contains? '(1 2 3 4) 4) ; #t
(contains? '(1 2 3 4) 0) ; #f

(define (contains?-cond lst elem)
  (cond [(null? lst) #f]
        [(equal? (car lst) elem) #t]
        [else (contains?-cond (cdr lst) elem)]))

(contains?-cond '(1 2 3 4) 4) ; #t
(contains?-cond '(1 2 3 4) 0) ; #f

(define (odd-cond lst)
  (cond
    [(member 1 lst) => (lambda (lst) (apply + lst))]
    [(member 2 lst)]
    [(member 3 lst) "three"]))
(odd-cond '(2 1 3)) ; 4
(odd-cond '(2 3))   ; '(2 3)
(odd-cond '(3))     ; "three"

; = Sequencing =
((lambda ()
   (begin
     (display "3")
     (display "2")
     (display "1")
     (display "go")))) ; 321go

; Implicit begin
(define (ready-set-go v)
  (cond [(= v 0)
         (display "Ready?")
         (display "Set")
         (display "Go!")]))
(ready-set-go 0) ; Ready?SetGo!

; Splicing
(let ([a 0])
  (begin
    (define b (+ 1 a))
    (define c (+ 1 b)))
  (list a b c)) ; (0 1 2)

; begin0
(define (i++ i)
  (begin0
    (unbox i)
    (set-box! i (+ 1 (unbox i)))))
(define (++i i)
  (begin
    (set-box! i (+ 1 (unbox i)))
    (unbox i)))

(define ival (box 0))
(begin (display (unbox ival))
       (display (i++ ival))
       (display (++i ival))
       (display (unbox ival))) ; 0022

; when, unless
(define (for-each-when f lst)
  (when (not (empty? lst))
    (f (car lst))
    (for-each f (cdr lst))))
(define (for-each-unless f lst)
  (unless (empty? lst)
    (f (car lst))
    (for-each f (cdr lst))))
(for-each-when display '(1 2 3))   ; 123
(for-each-unless display '(1 2 3)) ; 123

; = Assignment: set! =
(define coin 0)
(define (flip)
  (set! coin (- 1 coin)))
coin (flip) coin (flip) coin ; 0 1 0

(define x 'x)
(define y 'y)
(set!-values (x y) (values y x))
(list x y) ; '(y x)

; = Quoting =
; Mainly used for symbols and lists, which have other meanings when not quoted.
(quote ((1 2 3) #("a" b) . the-end)) ; '((1 2 3) #("a" b) . the-end)
'((1 2 3) #("a" b) . the-end)        ; '((1 2 3) #("a" b) . the-end)
(quote (quote (quote me)))           ; '''me

; = Quasiquoting =
(quasiquote (1 2 (unquote (+ 1 2)) (unquote (- 5 1)))) ; '(1 2 3 4)

(define (matryoshka depth)
  (if (zero? depth)
      0
      (quasiquote ((unquote depth) (unquote (matryoshka (- depth 1)))))))
(matryoshka 10) ; '(10 (9 (8 (7 (6 (5 (4 (3 (2 (1 0))))))))))

(define (num->var n) (string->symbol (format "x~a" n)))

(define (build-sum-exp n)
  (nested-lets n (nested-sum n)))

(define (nested-lets n body)
  (if (zero? n)
      body
      (quasiquote (let ([(unquote (num->var n)) (unquote n)])
                    (unquote (nested-lets (- n 1) body))))))

(define (nested-sum n)
  (if (= n 1)
      (num->var 1)
      (quasiquote (+ (unquote (num->var n))
                     (unquote (nested-sum (- n 1)))))))

(build-sum-exp 3) ; '(let ((x3 3)) (let ((x2 2)) (let ((x1 1)) (+ x3 (+ x2 x1)))))
(eval (build-sum-exp 100) (make-base-namespace)) ; 5050

; unquote-splicing
(quasiquote (1 2 (unquote-splicing (list (+ 1 2) (- 5 1))))) ; '(1 2 3 4)
(define (silly n)
  (if (zero? n)
      '(0)
      (quasiquote ((unquote n) (unquote-splicing (silly (- n 1)))))))
(silly 10) ; '(10 9 8 7 6 5 4 3 2 1 0)

(define (build-sum-exp-new n)
  (build-lets n (quasiquote
                 (+ (unquote-splicing (build-list n (λ (x) (num->var (+ x 1)))))))))

(define (build-lets n body)
  (quasiquote (let (unquote
                    (build-list n
                                (λ (x) (quasiquote [(unquote (num->var (+ x 1)))
                                                    (unquote (+ x 1))]))))
              (unquote body))))

(build-sum-exp-new 3) ; '(let ((x1 1) (x2 2) (x3 3)) (+ x1 x2 x3))
(eval (build-sum-exp-new 100) (make-base-namespace)) ; 5050

; Shorthand notation
`(1 2 ,(+ 2 1) ,(+ 0 4))        ; '(1 2 3 4)
`(1 2 ,@(list (+ 1 2) (+ 0 4))) ; '(1 2 3 4)

; Nested Quasiquoting
(quasiquote (1 2 (quasiquote (unquote (+ 1 2)))))           ; '(1 2 `,(+ 1 2))
(quasiquote (1 2 (unquote (quasiquote (unquote (+ 1 2)))))) ; '(1 2 3)
(quasiquote (1 2 (quasiquote (unquote (unquote (+ 1 2)))))) ; '(1 2 `,3)
(quasiquote (1 2
               (quasiquote
                ((unquote (+ 1 2))
                 (unquote (unquote (- 5 1)))))))            ; '(1 2 `(,(+ 1 2) ,4))
; = Simple Dispatch: case =
(let ([v (random 6)])
    (printf "~a\n" v)
    (case v
      [(0) 'zero]
      [(1) 'one]
      [(2) 'two]
      [(3 4 5) 'many]))

; = Dynamic Binding: parameterize =
(define color (make-parameter "red"))
(color)                            ; "red"
(parameterize ([color "green"])
  (list
   (color)
   (parameterize
       ([color "blue"]) (color)))) ; '("green" "blue")
(color)                            ; "red"

; A parameterize form adjusts the value of a parameter during the
; whole time that the parameterize body is evaluated.
(define (get-color)
  (color))
(parameterize ([color "black"])
  (get-color))   ; "black"

(let ([local-color
       (parameterize ([color "black"])
         (lambda () (color)))])
  (local-color)) ; "red"

(color "brown")
(color)          ; "brown"

(parameterize ([color "red"])
  (list
   (color)
   (begin
     (color "black")
     (color))))  ; '("red" "black")
(color)          ; "brown"

; Parameters are thread-safe.