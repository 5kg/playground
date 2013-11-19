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