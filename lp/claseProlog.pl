conc(A,B,C):- A=[],C=B.
conc(A,B,C):- A=[X|Z],
			conc(Z,B,Y),
			C=[X|Y].	