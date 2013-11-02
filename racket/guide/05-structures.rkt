#lang racket

(struct point (x y))
; constructor
(define p (point 1 2))
; predicator
(point? p) ; #t
(point? 0) ; #f
; accessor
(point-x p) ; 1
(point-y p) ; 2

; Functional update
(define p1 (struct-copy point p [x 0]))
(define p2 (struct-copy point p))

; Subtypes
(struct 3d-point point (z))
(3d-point? p) ; #f

(define pxyz (3d-point 1 2 3))
(point? pxyz)     ; #t
(point-x pxyz)    ; 1
(3d-point-z pxyz) ; 3
; (3d-point-x pxyz) <- error

; Transparent structure
(struct posn (x y) #:transparent)
(struct? (point 1 2)) ; #f
(struct? (posn 1 2))  ; #t

; Comparisons
(equal? (posn 1 1) (posn 1 1))   ; #t
(equal? (point 1 1) (point 1 1)) ; #f

(struct pt (x y)
  #:methods
  gen:equal+hash
  [(define (equal-proc a b recur) (and (recur (pt-x a) (pt-x b))
                       (recur (pt-y a) (pt-y b))))
   (define (hash-proc a recur) (+ (recur (pt-x a))
                   (* 3 (recur (pt-y a)))))
   (define (hash2-proc a recur) (+ (recur (pt-x a))
                   (recur (pt-y a))))])
(equal? (pt 1 1) (pt 1 1)) ; #t
(define h (make-hash))
(hash-set! h (pt 1 1) 0)
(hash-set! h (pt 0 0) 1)
(hash-ref h (pt 0 0))      ; 1

; Structure generativity
(define (struct-gen)
  (struct elem (x) #:transparent)
  (elem 0))
(equal? (struct-gen) (struct-gen))     ; #f

(struct elem (x) #:transparent)
(define (struct-gen-n)
  (elem 0))
(equal? (struct-gen-n) (struct-gen-n)) ; #t

; Prefab structures
#s(prefab-p 1 1) ; '#s(point 1 1)

(struct prefab-p (x y) #:prefab)
(prefab-p 1 1)                 ; '#s(prefab-p 1 1)
(prefab-p? #s(prefab-p 1 1))   ; #t
(prefab-p? #s(prefab-p 1 1 1)) ; #f
(prefab-p-x #s(prefab-p 1 1))  ; 1
(prefab-p-y #s(prefab-p 1 1))  ; 1

(struct prefab-p-3d prefab-p (z) #:prefab)
(prefab-p-3d 1 2 3) ; '#s((prefab-p-3d prefab-p 2) 1 2 3)

(struct mutable-prefab-p ([x #:mutable] [y #:mutable]) #:prefab)
(mutable-prefab-p 1 2) ; '#s((mutable-prefab-p #(0 1)) 1 2)

(struct building (rooms [location #:mutable]) #:prefab)
(struct house building ([occupied #:auto]) #:prefab
    #:auto-value 'no)
(house 5 'factory) ; '#s((house (1 no) building 2 #(1)) 5 factory no)

; Mutable structures
(struct mp (x y) #:mutable)
(define mp0 (mp 0 0))
(set-mp-x! mp0 1)

(struct mpy (x [y #:mutable]))
(define mp1 (mpy 0 0))
; (set-mpy-x! mp1 1) -> error
(set-mpy-y! mp1 1)

; Automatic fields
(struct autop (x y [z #:auto]) #:transparent)
; (autop 1 1 1) <- error
(autop 1 2)  ; (autop 1 2 #f)
(struct autopp (x y [z #:auto]) #:transparent #:auto-value 0)
(autopp 1 2) ; (autopp 1 2 0)