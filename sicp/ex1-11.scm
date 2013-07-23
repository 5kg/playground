(define (f n)
  (if (< n 3)
      n
      (+ (f (- n 1))
         (* 2 (f (- n 2)))
         (* 3 (f (- n 3))))))

(define (f n)
  (define (f-iter count a b c)
    (if (> count n)
        a
        (f-iter (+ count 1)
                (+ a
                   (* 2 b)
                   (* 3 c))
                a
                b)))
  (if (< n 3)
      n
      (f-iter 3 2 1 0)))
