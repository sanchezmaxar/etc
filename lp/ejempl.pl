%ejempl.pl
%consult(ejem)
%hechos
le_gusta(fulano, agua ).
le_gusta(fulano,cerveza).
le_gusta(fulano, refresco).
le_gusta(fulano, leche).
hombre(pedro).
mujer(luz).
mujer(maria).
hombre(paco).
hombre(luisII).
progenitor(pedro,luisII).
progenitor(pedro,paco).
progenitor(pedro, maria).
progenitor(luz,luisII).
progenitor(luz,paco).
progenitor(luz,maria).
progenitor(roberto,luz).
progenitor(diana,luz).
progenitor(luis,pedro).
progenitor(andrea,pedro).
hombre(beto).
progenitor(maria,beto).
%progenitor(jose,beto).
progenitor(luis,tono).
hombre(tono).

%Reglas
madre(X,Y):- mujer(X),progenitor(X,Y).
padre(X,Y):- hombre(X),progenitor(X,Y).
hijo(X,Y):- hombre(X),progenitor(Y,X).
hija(X,Y):- mujer(X),progenitor(Y,X).
abuelo(X,Y):-hombre(X),progenitor(X,Z),progenitor(Z,Y).
nieto(X,Y):- hombre(X),progenitor(Z,X),progenitor(Y,Z).
hermano(X,Y):-hombre(X),progenitor(Z,X),progenitor(Z,Y).
tio(X,Y):- hombre(X),progenitor(Z,Y),progenitor(M,Z),progenitor(M,X), not(X == Z).