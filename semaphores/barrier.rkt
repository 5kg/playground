#lang racket

(define n 100)

(define mutex (make-semaphore 1))
(define all-done (make-semaphore 0))

(define count 0)

(define (barrier n)
  ; increment count
  (semaphore-wait mutex)
  (set! count (+ count 1))
  (semaphore-post mutex)
  ; if count equals number of threads, let go
  (when (= count n)
      (semaphore-post all-done))
  ; turnstile to avoid deadlock
  (semaphore-wait all-done)
  (semaphore-post all-done))

(define (job id)
  (thunk
   (printf "Thread ~a part A~n" id)
   (barrier n)
   (printf "Thread ~a part B~n" id)))

(set! count 0)

(define thread-list
  (for/list ([i n])
    (thread (job i))))

(for-each (lambda (th) (thread-wait th)) thread-list)
