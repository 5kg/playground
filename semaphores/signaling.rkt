#lang racket

(define thread-A-done (make-semaphore 0))

(define thread-A
  (thread
   (thunk
    (display "Hello")
    (semaphore-post thread-A-done))))

(define thread-B
  (thread
   (thunk
    (semaphore-wait thread-A-done)
    (display "World"))))

(thread-wait thread-A)
(thread-wait thread-B)
(newline)