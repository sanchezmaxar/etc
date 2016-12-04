#lang racket
(require test-engine/racket-tests)
(require racket/bool)

(define-struct sum (izq der))
(define-struct mul (izq der))
(define-struct conj (izq der))
(define-struct disy (izq der))
(define-struct igual (izq der))
(define-struct diff (izq der))
(define-struct mayq (izq der))
(define-struct menq (izq der))
(define-struct mayqi (izq der))
(define-struct menqi (izq der))
(define-struct orx (izq der))
(define-struct no (un))
(define-struct div (num den))
(define-struct pot (base exp))
;evaluar 
;recibe una expresion
;regresa el valor de la expresion o una cadena si no se puede evaluar
(define (evaluar en )
	(if (algunSimbolo en )
		"No se puede evaluar"
		(evaluar2 en)
		))
;evaluar2
;recibe una expresion evaluable
;regresa su valor
(define (evaluar2 en)
  (cond
    [(number? en) en ]
    [(boolean? en ) en]
    [(sum? en)(+ (evaluar (sum-izq en))
                   (evaluar (sum-der en)))]
    [(mul? en) (* (evaluar (mul-izq en))
                   (evaluar (mul-der en)))]
    [(div? en) (/ (evaluar (div-num en ) )
                   (evaluar (div-den en)))]
    [(pot? en) (evaluar (pote (evaluar (pot-base en )) 
                    (evaluar (pot-exp en))))]
    [(conj? en) (and (evaluar (conj-izq en ))
    				(evaluar (conj-der en )))]
    [(disy? en) (or (evaluar (disy-izq en ))
    				(evaluar (disy-der en )))]
   	[(igual? en) (eq? (evaluar (igual-izq en ))
    				(evaluar (igual-der en )))]
   	[(diff? en) (\= (evaluar (diff-izq en ))
    				(evaluar (diff-der en )))]
   	[(mayq? en) (> (evaluar (mayq-izq en ))
    				(evaluar (mayq-der en )))]
   	[(menq? en) (< (evaluar (menq-izq en ))
    				(evaluar (menq-der en )))]
   	[(mayqi? en) (>= (evaluar (mayqi-izq en ))
    				(evaluar (mayqi-der en )))]
   	[(menqi? en) (<= (evaluar (menqi-izq en ))
    				(evaluar (menqi-der en )))]
   	[(orx? en) (xor (evaluar (orx-izq en ))
    				(evaluar (orx-der en )))]
   	[(no? en) (not (evaluar (no-un en )))]
   	
   	)
)
;algunSimbolo
;recibe un expresion 
;regresa true si la expresion tiene un simbolo si no false
(define (algunSimbolo expresion )
	(cond 
		[(sum? expresion) (or (algunSimbolo (sum-izq expresion))(algunSimbolo (sum-der expresion)))]
		[(mul? expresion) (or (algunSimbolo (mul-izq expresion))(algunSimbolo (mul-der expresion)))]
    [(div? expresion) (or (algunSimbolo (div-num expresion) ) (algunSimbolo (div-den expresion)))]
    [(pot? expresion) (or (algunSimbolo (pot-base expresion)) (algunSimbolo(pot-exp expresion)))]
    [(conj? expresion)(or (algunSimbolo (conj-izq expresion)) (algunSimbolo (conj-izq expresion)))]
    [(disy? expresion)(or (algunSimbolo (disy-izq expresion)) (algunSimbolo (disy-izq expresion)))]
    [(igual? expresion)(or (algunSimbolo (igual-izq expresion)) (algunSimbolo (igual-izq expresion)))]
    [(diff? expresion)(or (algunSimbolo (diff-izq expresion)) (algunSimbolo (diff-izq expresion)))]
    [(mayq? expresion)(or (algunSimbolo (mayq-izq expresion)) (algunSimbolo (mayq-izq expresion)))]
    [(menq? expresion)(or (algunSimbolo (menq-izq expresion)) (algunSimbolo (menq-izq expresion)))]
    [(mayqi? expresion)(or (algunSimbolo (mayqi-izq expresion)) (algunSimbolo (mayqi-izq expresion)))]
    [(menqi? expresion)(or (algunSimbolo (menqi-izq expresion)) (algunSimbolo (menqi-izq expresion)))]
    [(orx? expresion)(or (algunSimbolo (orx-izq expresion)) (algunSimbolo (orx-izq expresion)))]
    [(no? expresion)(or (algunSimbolo (no-un expresion)))]
		[(symbol? expresion) true ]
		[else false ]
		)
	)


;(evaluar (make-sum (make-mul 3 3) (make-mul 4 4))) -> 25
(check-expect (evaluar 5) 5)
(check-expect (evaluar (make-sum 3 5)) 8) 
(check-expect (evaluar (make-sum (make-mul 3 3) (make-mul 4 4))) 25)
(test)


(check-expect (evaluar 5) 5)
(check-expect (evaluar 'x) "No se puede evaluar")
(check-expect (evaluar (make-sum 3 5)) 8)
(check-expect (evaluar (make-mul 3 5)) 15)
(check-expect (evaluar (make-sum 3 'z)) "No se puede evaluar")
(check-expect (evaluar (make-mul 'x 'y)) "No se puede evaluar")
(check-expect (evaluar (make-conj #t #t )) #t)
(evaluar (make-no #f))
(evaluar (make-orx #f #t))
; (test)

;subst 
;recibe una expresion un simbolo y un numero o booleano
; regresa la expresion con los simbolos sustituidos
(define (subst exp simb n)
	(cond 
		[(number? exp ) exp]
		[(boolean? exp) exp]
		[(symbol? exp) (if (eq? exp simb) n exp)]
		[(sum? exp) (make-sum (subst (sum-izq exp) simb n) (subst (sum-der exp) simb n))]
		[(mul? exp) (make-mul (subst (mul-izq exp) simb n) (subst (mul-der exp) simb n))]
    [(div? exp ) (make-div (subst (div-num exp) simb n ) (subst (div-den exp ) simb n))]
    [(pot? exp) (make-pot (subst (pot-base exp ) simb n) (subst (pot-exp exp ) simb n))]
		[(conj? exp) (make-conj (subst (conj-izq exp) simb n) (subst (conj-der exp) simb n))]
		[(disy? exp) (make-disy (subst (disy-izq exp) simb n) (subst (disy-der exp) simb n))]
		[(igual? exp) (make-igual (subst (igual-izq exp) simb n) (subst (igual-der exp) simb n))]
		[(diff? exp) (make-diff (subst (diff-izq exp) simb n) (subst (diff-der exp) simb n))]
		[(mayq? exp) (make-mayq (subst (mayq-izq exp) simb n) (subst (mayq-der exp) simb n))]
		[(menq? exp) (make-menq (subst (menq-izq exp) simb n) (subst (menq-der exp) simb n))]
		[(mayqi? exp) (make-mayqi (subst (mayqi-izq exp) simb n) (subst (mayqi-der exp) simb n))]
		[(menqi? exp) (make-menqi (subst (menqi-izq exp) simb n) (subst (menqi-der exp) simb n))]
		[(orx? exp) (make-orx (subst (orx-izq exp) simb n) (subst (orx-der exp) simb n))]
		[(no? exp) (make-no (subst (no-un exp) simb n)) ]
		[else exp]
		)

)

; pote
; recibe una base y un exponente
; regresa la base elevada al exponente
(define (pote base exp)
    (if (zero? exp)
      1
      (make-mul base (pote base (- exp 1)))
    )
)
(evaluar (no #t))
; (check-expect (subst 5 'x 2) 5)(test)
; (check-expect (subst 'x 'x 2) 2)
; ; (check-expect (subst (make-sum 3 5) 'x 2) (make-sum 3 5))
; (check-expect (evaluar(subst (make-sum 3 5) 'x 2)) (evaluar(make-sum 3 5)))
; (make-sum 3 5)
; (subst (make-sum 3 5) 'x 2)
(check-expect (subst (make-sum (make-mul 3 'x) (make-mul 4 'x)) 'x 2)
              (make-sum (make-mul 3 2) (make-mul 4 2)))
; ; (check-expect (subst (make-sum (make-mul 'x 'y) (make-mul 'x 'z)) 'x 2)
;               (make-sum (make-mul 2 'y) (make-mul 2 'z)))
(check-expect (evaluar (subst (make-sum (make-mul 3 'x) (make-mul 4 'x)) 'x 2))
              (evaluar(make-sum (make-mul 3 2) (make-mul 4 2))))
; (check-expect (evaluar (subst (make-sum (make-mul 'x 'y) (make-mul 'x 'z)) 'x 2))
;               (evaluar(make-sum (make-mul 2 'y) (make-mul 2 'z))))
; (test)
; (evaluar(subst (subst (make-mul 'x 'y) 'x 5) 'y 10)) 
(evaluar (subst (subst (make-div 'x 'y) 'x 5) 'y 10))
; (test)
; (/ 3 5)
(evaluar (subst (subst (make-disy (make-orx 'x 'y ) #f) 'x #t) 'y #f))
(evaluar (make-pot 19 1))
(test)