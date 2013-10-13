#lang racket

(define n 100)

(define mutex (make-semaphore 1))

(define count 0)

(define (critical-section)
  (set! count (+ count 1)))

(define inc-count
  (thunk
   (semaphore-wait mutex)
   (critical-section)
   (semaphore-post mutex)))

(define thread-list
  (for/list ([i n])
    (thread inc-count)))

(for-each (lambda (th) (thread-wait th)) thread-list)

(display count)
(newline)