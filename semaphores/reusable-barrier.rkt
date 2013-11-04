#lang racket

(define n 100)

(define mutex (make-semaphore 1))
(define all-done (make-semaphore 0))
(define all-reset (make-semaphore 1))

(define count 0)

(define (barrier n)
  (semaphore-wait mutex)
  ; increment count
  (set! count (+ count 1))
  ; if count equals number of threads, lock all-reset, signal all-done
  (when (= count n)
      (semaphore-wait all-reset)
      (semaphore-post all-done))
  (semaphore-post mutex)

  ; turnstile to avoid deadlock
  (semaphore-wait all-done)
  (semaphore-post all-done)

  (semaphore-wait mutex)
  ; decrement count
  (set! count (- count 1))
  ; if count equals 0, lock all-done, signal all-reset
  (when (= count 0)
    (semaphore-wait all-done)
    (semaphore-post all-reset))
  (semaphore-post mutex)

  ; turnstile to avoid deadlock
  (semaphore-wait all-reset)
  (semaphore-post all-reset))

(define (job id)
  (thunk
   (printf "Thread ~a part A~n" id)
   (barrier n)
   (printf "Thread ~a part B~n" id)
   (barrier n)
   (printf "Thread ~a part C~n" id)))

(set! count 0)

(define thread-list
  (for/list ([i n])
    (thread (job i))))

(for-each (lambda (th) (thread-wait th)) thread-list)
