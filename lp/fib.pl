fib (0,1).
fib(1,1).
fib(s(s(X))):- 
	Y is Fib(X),
	Z is Fib(s(X)).
s(X):-
	X+1.