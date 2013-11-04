#lang racket

(define barrier%
  (class object%
    (init n)

    (define num-threads n)
    (define count 0)
    (define mutex (make-semaphore 1))
    (define all-done (make-semaphore 0))
    (define all-reset (make-semaphore 1))

    (super-new)

    (define/public (wait)
      (semaphore-wait mutex)
      ; increment count
      (set! count (+ count 1))
      ; if count equals number of threads, lock all-reset, signal all-done
      (when (= count num-threads)
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
      (semaphore-post all-reset))))

(define barrier (new barrier% [n 100]))

(define (job id)
  (thunk
   (printf "Thread ~a part A~n" id)
   (send barrier wait)
   (printf "Thread ~a part B~n" id)
   (send barrier wait)
   (printf "Thread ~a part C~n" id)))

(define thread-list
  (for/list ([i 100])
    (thread (job i))))

(for-each (lambda (th) (thread-wait th)) thread-list)
