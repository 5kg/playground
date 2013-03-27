(define (p) (p))

(define (test x y)
  (if (= x 0)
      x
      y))

(test 0 (p))

;The infinite recursion function 'p' will not be evaluated if using normal-order.
