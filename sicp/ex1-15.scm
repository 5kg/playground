(define (cube x) (* x x x))

(define (p x) (display "1") (- (* 3 x) (* 4 (cube x))))

(define (sine angle)
  (if (not (> angle 0.1))
    angle
    (p (sine (/ angle 3.0)))))

; (a) 5 times.
; (b) Time O(log n)
;     Space O(log3 n)
