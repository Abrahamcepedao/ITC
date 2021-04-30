% Actividad 5.5 Programación con BIFs de orden superior en Erlang
% Lucas Idigoras - A00827751
% Abraham Cepeda - A00827666
-module(ej5).
-import(lists,[nth/2, delete/2]). 
-export([trans/1, hay_pares/1, impares/1, empareja/1]).


% <--------trans--------->
% tome primer elemento de cada subarray (head) y lo vuelve a hacer con el resto hasta que se acaban los elementos
trans([[]|_]) -> [];
trans(M) -> [lists:map(fun hd/1, M) | trans(lists:map(fun tl/1, M))].
 
% <--------hay pares--------->
hay_pares(M) -> aux_hay_pares(M, nth(1, M)).

aux_hay_pares(M,  []) -> 
    NUM = length([X || X <- M, X < 1]),
    if
        (NUM == 0) -> false;
        (M /= []) ->
            ELEM = nth(1, M),
            M_AUX = delete(ELEM, M),
            aux_hay_pares(M_AUX, nth(1, M_AUX))
    end;
aux_hay_pares(M, A) -> 
    NUM = nth(1, A),
    A_AUX = delete(NUM, A),
    if
        (NUM rem 2 == 0) -> true;
        (NUM rem 2 /= 0) -> aux_hay_pares(M, A_AUX)
    end.


% <--------impares--------->
impares(M) -> 
    ELEM = nth(1, M),
    M_AUX = delete(ELEM, M),
    [[X || X <- ELEM, X rem 2 /= 0]] ++ aux_impares(M_AUX).

aux_impares([]) -> [];
aux_impares(M) -> 
    ELEM = nth(1, M),
    M_AUX = delete(ELEM, M),
    [[X || X <- ELEM, X rem 2 /= 0]] ++ aux_impares(M_AUX).


% <--------Empareja---------> 
%empareja(M) -> [aux_empareja(M, nth(1, M), 1)].
empareja(M) -> 
    N = length(M),
    [{nth(1, M), nth(1, M)}] ++ aux_empareja(M, N, nth(1, M), 1, 2).


aux_empareja(_, N, E, N, N) -> [{E, E}];
aux_empareja(M, N, E, C1, N) when C1 < N ->
    [{E, nth(N,M)}] ++ aux_empareja(M, N, nth(C1+1, M), C1+1, 1);
aux_empareja(M, N, E, C1, C2 ) when C2 < N ->
    [{E, nth(C2,M)}] ++ aux_empareja(M, N, nth(C1, M), C1, C2+1).