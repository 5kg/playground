(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))
; First evaluate the 'if' statement to obtain the operator, then apply the operator to operands.
