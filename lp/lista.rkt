#lang racket

(require test-engine/racket-tests)

;len
;recibe una lista y el inicio del contador de largo de la lista este debe ser cero 
;regresa el numero de elementos

(define (len lista )
	(cond 
		[(empty? lista ) 0]
		[(cons? lista) (+ 1 (len (rest lista)))]
		[else -1]
		)
	)		
;selector
;recibe una lista y un entero
;regresa el elemento que este en el indice i 
(define (sel lista n)
	(cond
		[(empty? lista ) 'empty]
		[(zero? n) (first lista)]
		[(cons? lista)(sel (rest lista ) (- n 1))]
		[else  (display "no es una lista\n")]
		)
	)
;max
;recibe una lista 
;regresa el elemento mayor de dicha lista
(define (maxt lista )(maxi (rest lista) (first lista)))
(define (maxi lista n)
	(if (equal? lista empty )
		n
		(if (> (first lista) n)
			(maxi (rest lista) (first lista))
			(maxi (rest lista) n)
			)
		)
	)
;rev
;recibe una lista
;regresa la lista invertida
(define (rev lista )
	(if (equal? (rest lista) empty )
		(list (first lista))
		(append (rev (rest lista)) (list (first lista)))
		)
	)

(define L1 empty)
(define L2 (cons 1 empty))
(define L3 (cons 1 (cons 2 empty)))

;Definir una lista de 1 a 9
(define L4 (cons 1 (cons 2 (cons 3 (cons 4 (cons 5 (cons 6 (cons 7 (cons 8 (cons 9 (cons 0 empty)))))))))))
;(define L4 (list 1 2 3 4 5 6 7 8 9 0))
;disc 
;recibe 3 numeros que describen una eq de segundo grado 
;regresa el dicriminante
(define (disc a b c)
	(chi (- (sqr b) (* 4 a c )) a b c)
	)
;chi
;recibe el discriminante y los a b c de la eq de segundo grado
;regresa el valor de las raices

(define (chi dis a b c)
	(cond 
		[(zero? dis) (/ (- b ) (* 2 a))]
		[(> dis 0) (list (/ (+ (- b ) (sqrt dis)) ( * 2 a ) ) (/ (- (- b ) (sqrt dis )) ( * 2 a ) ) )]
		[else 'complejos]
		)
	)
;suma_i
;recibe un numero i positivo
;regresa la suma de los numeros positivos hasta i
(define (suma_i i )
	(if (zero? i )
		0
		(+ i (suma_i (sub1 i) ))
		)
	)
(sel (list 1 2 3 4) 5 )
(len empty)
(sel 2 2)
(check-expect (len L1) 0)
(check-expect (len L3) 2)
(check-expect (len L4) 10)
(check-expect (len 0) -1)
(disc 3 2 2/12)
(suma_i 5 )
(test)