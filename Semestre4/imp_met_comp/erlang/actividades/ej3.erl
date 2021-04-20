-module(ej3).
-import(lists, [min/1, append/2, nth/2, nthtail/2]).
-export([menor/1, palindromo/1, negativos/1, profundidad/1]).

%<-----------menor----------->
menor(A) ->
    io:fwrite("~w~n", [min(A)]).


%<-----------palindromo----------->
palindromo(N) -> palindromo_aux(N, 1, [0]).

palindromo_aux_dec(0, A) ->
    io:fwrite("~w~n", [append(A, [0])]);
palindromo_aux_dec(C, A) when C > 0 ->
    palindromo_aux_dec(C-1, append(A, [C])).

palindromo_aux(N,N,A) -> palindromo_aux_dec(N-1, append(A, [N, N]));
palindromo_aux(N, C, A) when C < N ->
    palindromo_aux(N, C+1, append(A,[C])).


%<-----------Negativos----------->
negativos(A) -> negativos_aux([], A, 1).

negativos_aux(B, [], C) ->
    io:fwrite("~w~n", [B]);
negativos_aux(B, A, C) -> 
    X = nth(C, A),
    if
        (X < 0) -> negativos_aux(append(B, [X]), nthtail(C, A), C);
        (X >= 0) -> negativos_aux(B, nthtail(C, A), C)
    end.


%<-----------Profundidad----------->
profundidad(A) -> io:fwrite("~w~n", [A]).

%profundidad_aux(A, C)