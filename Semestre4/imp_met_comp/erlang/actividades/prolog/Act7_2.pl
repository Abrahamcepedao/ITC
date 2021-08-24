/*% Act 7.2 Programación lógica avanzada en Prolog */
/*% Lucas idigoras - A00827751 */
/*% Abraham Cepeda - A00827666*/

/* <-----fgeneral----->*/
raiz(A,B,C,X) :-
    X is B*B-4*A*C.

fgeneral(A,B,C,X1,X2) :-
    raiz(A,B,C,X),
    S is sqrt(U),
    X1 is (-B-S)/(2*A),
    X2 is (-B+S)/(2*A).


fgeneral(A,B,C,X1,X2) :-
    underRoot(A,B,C,U),
    SU is sqrt(U),
    X1 is (-B-SU)/(2*A),
    X2 is (-B+SU)/(2*A).

/* <-----comprime----->*/
comprime([],[]).
comprime([X],[X]).
comprime([X,X | L1],L2) :-
    comprime([X|L1], L2).
comprime([X,Y | L1], [X | L2]) :-
    X \= Y,
    comprime([Y | L1], L2).


/* <-----multiplo----->*/
multiplo(N,M):- 
    Cont is 1,
    auxiliar(N, M, Cont).

auxiliar(N,M,Cont):-
    N1 is N * Cont,
    N1 =< M, ! , 
    write(N1), write(" "),
    Cont1 is Cont + 1,
    auxiliar(N,M,Cont1).

auxiliar(_,_,_).


/* <-----duplica----->*/
duplica([],[]).
duplica([[X]|T], [[X,X]|Y]) :-
    duplica(T,Y). 
duplica([H|T],[H,H|Y]) :-
    duplica(T,Y). 


/* <------hojas------->*/
hojas([],0).
hojas([_|L],N) :-
    hojas(L,N1),
    N is N1 + 1.