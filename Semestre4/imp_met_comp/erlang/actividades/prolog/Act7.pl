/*% Act 7.1 Programacion basica prolog */
/*% Lucas idigoras - A00827751 */
/*% Abraham Cepeda - A00827666*/

padre(esteban, lucas).
padre(ricardo, esteban).
padre(ricardo, mariel).
padre(ricardo, ignacio).
padre(ignacio, elena).
padre(ignacio, agustin).
padre(ignacio, elena).
padre(ignacioo, abraham).
padre(ignacioo, jimena).
padre(maria, daniela).
padre(maria, natalia).
padre(juan, paola).
padre(maricarmen, andres).
padre(abrahamm, ignacioo).
padre(abrahamm, juan).
padre(abrahamm, maria).
padre(abrahamm, maricarmen).

hijo(X,Y) :-  padre(Y, X).
abuelo(X,Z) :- padre(X,U), padre(U,Z).
nieto(L,R) :- padre(R,E), padre(E,L).
hermano(A,T) :- padre(I,A), padre(I,T), A \== T.
tio(M, L):- padre(R, M), padre(R,E), padre(E, L), M \== E.
sobrino(A,E) :- padre(R,E), padre(R,I), padre(I,A), I\== E.
primo(L, A):- padre(E, L), padre(I, A), padre(R,E), padre(R,I), L \== A, E \== I.


top(X1,Y1) :- p(X1,Y1).
top(X2,X2) :- s(X2).
p(X3,Y2) :- q(X3), r(Y2).
p(X4,Y3) :- s(X4), r(Y3).
q(a).
q(b).
r(c).
r(d).
s(e).