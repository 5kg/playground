(define (+ a b)
  (if (= a 0)
      b
      (inc (+ (dec a) b))))
;Recursive

(define (+ a b)
  (if (= a 0)
      b
      (+ (dec a) (inc b))))
;Iterative
