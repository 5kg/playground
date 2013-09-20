#lang racket

(define thread-A-done (make-semaphore 0))
(define thread-B-done (make-semaphore 0))

(define thread-A
  (thread
   (thunk
    (display "A1")
    (semaphore-post thread-A-done)
    (semaphore-wait thread-B-done)
    (display "A2"))))

(define thread-B
  (thread
   (thunk
    (display "B1")
    (semaphore-post thread-B-done)
    (semaphore-wait thread-A-done)
    (display "B2"))))

(thread-wait thread-A)
(thread-wait thread-B)
(newline)
