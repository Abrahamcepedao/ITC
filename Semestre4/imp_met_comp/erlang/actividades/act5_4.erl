%Lucas Idigoras - A00827751
%Abraham Cepeda - 
-module(act5_4).
-export([mapea/2,compon/2,agregaAlFinal/1]).


compon(F,G) ->
  fun(X) -> F(G(X)) end.

agregaAlFinal(E) ->
  fun(Lista) -> Lista ++ [E] end.

