% Actividad 5.4 Programación de funciones de orden superior en Erlang
% Lucas Idigoras - A00827751
% Abraham Cepeda - A00827666
-module(ej4).
-export([filtra/2, mapea/2, compon/2,agregaAlFinal/1]).

% 1. ----------Ffltra-----------
filtra(F, A) -> [X || X <- A, F(X)].

% 2. ----------mapea-----------
mapea(_, []) -> [];
mapea(F, [H|T]) -> [F(H)|mapea(F, T)].

compon(F,G) ->
  fun(X) -> F(G(X)) end.

agregaAlFinal(E) ->
  fun(Lista) -> Lista ++ [E] end.
 