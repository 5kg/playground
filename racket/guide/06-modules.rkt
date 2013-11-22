#lang racket

; import module
(require "06-modules/part1.rkt") ; I am module 'part1'
(require "06-modules/part1.rkt") ; <nothing here>, instantiate only once

(test) ; call imported functions
; (test-private) <= unbound identifier in module in: test-private

; import collection
(require racket/date racket/base setup/dirs)

(find-collects-dir)        ; main collection directory
(find-user-collects-dir)   ; user-specific collection directory
(get-collects-search-dirs) ; complete search path

; 'module' form
(module part2 racket
  (provide test2)
  (display "I am module 'part2'")
  (define (test2)
    (display "Call function provided by 'part2' module")))

(require 'part2) ; I am module 'part2'
(test2)          ; Call function provided by 'part2' module

; submodules
(module part3 racket
  (display "I am module 'part3'")
  (define (private-f)
        (display "I am a private function in 'part3'"))
  (module part4 racket
    ; (private-f) <= private-f: unbound identifier in module in: private-f
    (display "I am module 'part4'")))

(require 'part3) ; I am module 'part3', <part4 is not instantiated>
(require (submod 'part3 part4)) ; I am module 'part4'

; module*
(module part5 racket
  (define (private-f)
    (display "I am a private function in 'part5'"))
  (module* part5-extra #f
    (display "I am module 'part5-extra'")
    (provide private-f)))

(require (submod 'part5 part5-extra)) ; I am module 'part5-extra'
(private-f) ; I am a private function in 'part5'

; module+
(module part6 racket
  (define (foo) (display "foo"))
  (module+ test (foo))
  (define (bar) (display "bar"))
  (module+ test (bar))
  (define (baz) (display "baz"))
  (module+ test (baz)))

(require (submod 'part6 test)) ; foobarbaz

; submod
(module part7 racket
  (display "I am module 'part7'")
  (module* part7-1 racket
    (require (submod ".."))
    (display "I am module 'part7-1'"))
  (module* part7-2 racket
    (module part7-2-1 racket
      (display "I am module 'part7-2-1'"))
    (require (submod ".." part7-1))
    (require (submod "." part7-2-1))
    (display "I am module 'part7-2'")))

(require (submod 'part7 part7-2)) ; I am module 'part7' I am module 'part7-1' I am module 'part7-2-1' I am module 'part7-2'

; more on require
(module part8 racket
  (provide a b c)
  (define a #t)
  (define b #t)
  (define c #t))

(require (only-in 'part8 a))
a ; #t

(require (only-in 'part8 [a aa]))
aa ; #t

(require (except-in 'part8 a b))
c ; #t

(require (rename-in 'part8 [c cc]))
cc ; #t

(require (prefix-in part8- 'part8))
part8-c ; #t

(require (prefix-in part8: (except-in 'part8 c)))
part8:a ; #t

; more on provide
(module part9 racket
  (provide (struct-out pos))
  (provide (rename-out (pos pos1)))
  (provide (except-out (all-defined-out) pos))
  (provide (prefix-out part9: (all-defined-out)))

  (module sub racket
    (provide part9:sub:foo)
    (define part9:sub:foo #t))
  (require (submod "." sub))
  (provide (all-from-out 'sub))

  (struct pos (x y)))

(require 'part9)
part9:pos
part9:sub:foo

; assignment
(module part10 racket
  (provide counter increment!)
  (define counter 0)
  (define (increment!) (set! counter (+ 1 counter))))

(require 'part10)
counter ; 0
(increment!)
counter ; 1
; (set! counter 2) <=  set!: cannot mutate module-required identifier in: counter
