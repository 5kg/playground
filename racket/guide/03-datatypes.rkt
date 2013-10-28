#lang racket

; = Booleans =
(boolean? #f) ; #t
(boolean? #T) ; #t
(if 1 #t #f)  ; #t
(boolean? 1)  ; #f

; = Numbers =
; Exact numbers
42
1/6
1-i

; Inexact numbers
3.14
-3.14i

; Prefixes
0.5    ; 0.5↲                                                                    
#e0.5  ; 1/2↲                                                                    
#i1/2  ; 0.5
#b11   ; 3
#o777  ; 511
#xffff ; 65535
#b1.1  ; 1.5

; Exact <-> Inexact
(exact? (+ 1 1))   ; #t
(exact? (+ 1.1 1)) ; #f
(inexact->exact 0.5) ; 1/2
(exact->inexact 1/2) ; 0.5

; Predictors
(integer? 1)    ; #t
(integer? 6/3)  ; #t
(rational? 1)   ; #t
(rational? 1/3) ; #t
(real? 1)       ; #t
(real? 1/3)     ; #t
(real? 0.1)     ; #t
(real? 1+2i)    ; #f
(complex? 1)    ; #t
(complex? 1+2i) ; #t
(number? 1+2i)  ; #t

; Comparisons
(= 1 1.0)    ; #t
(eqv? 1 1.0) ; #f
(= 1/10 0.1) ; #f, approximation error

; = Characters =
; Constants
#\A
#\λ
#\u03BB
#\space
#\newline

; Procedures
(integer->char 65)  ; #\A
(char->integer #\A) ; 65
(display #\A)       ; A

(char-alphabetic? #\A)       ; #t
(char-numeric? #\0)          ; #t
(char-whitespace? #\newline) ; #t
(char-downcase #\A)          ; #\a

(char=? #\A #\a)    ; #f
(char-ci=? #\A #\a) ; #t

; = Strings =
(display "λ\"Apple\"\u03BB\n") ; λ"Apple"λ
(define s (make-string 5 #\.))
(string-set! s 0 #\!)          ; "!...."
(string-ref s 0)               ; #\.
(string<? "apple" "Banana")    ; #f
(string-ci<? "apple" "Banana") ; #t

; = Bytes =
#"Apple"
(byte? 0)   ; #t
(byte? 256) ; #f

(bytes-ref #"Apple" 0)       ; 65
(define b (make-bytes 3 65)) ; #"AAA"
(bytes-set! b 0 0)           ; #"\0AA"
(display #"AAA")             ; AAA
(display "\316\273")         ; Î»
(display #"\316\273")        ; λ

(bytes->string/utf-8 #"\316\273")   ; "λ"
(bytes->string/latin-1 #"\316\273") ; "Î»"

; = Symbols =
'a
(symbol? 'a) ; #t

(eq? 'a 'a)                   ; #t
(eq? 'a (string->symbol "a")) ; #t
(eq? 'a 'A)                   ; #f
(eq? 'a #ci'A)                ; #t

(string->symbol "a, b")         ; '|a, b|
(eq? '1 '|1|)                   ; #f
(eq? (string->symbol "1") '|1|) ; #t

(write '|a, b|)   ; |a, b|
(display '|a, b|) ; a, b

; Uninterned symbols
(define sym (gensym)) ; 'g29224
(eq? 'g29224 sym)     ; #f
(eq? sym sym)         ; #t
(eq? 'a (string->uninterned-symbol "a")) ; #f

; = Keywords =
(keyword? '#:apple) ; #t
(keyword? 'apple)   ; #f
(string->keyword "apple") ; '#:apple

(define (foo #:hd hd #:tl tl)
  (string-append hd tl))
(foo #:tl "b" #:hd "a") ; "ab"