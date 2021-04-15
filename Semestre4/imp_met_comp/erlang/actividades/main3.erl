-module(main3).
-export([clima/1, cuadrante/2, mayor/3, sumapar/4]).



clima(T) ->
  if 
    T =< 0 -> 'Congelado';
    (T > 0) and (T =< 10) -> 'Helado';
    (T > 10) and (T =< 20) -> 'Frio';
    (T > 20) and (T =< 30) -> 'Normal';
    (T > 30) and (T =< 40) -> 'Caliente';
    (T > 40) -> 'Hirviendo'
    end.

cuadrante(X,Y) ->
  if 
    (X == 0) and (Y == 0) -> 'origen';
    (X > 0) and (Y > 0) -> 'primer cuadrante';
    (X > 0) and (Y < 0) -> 'segundo cuadrante';
    (X < 0) and (Y < 0) -> 'tercer cuadrante';
    (X < 0) and (Y > 0) -> 'cuarto cuadrante';
    (X == 0) and (Y > 0) -> 'sobre el eje y positivo';
    (X == 0) and (Y < 0) -> 'sobre el eje y negativo';
    (X > 0) and (Y == 0) -> 'sobre el eje x positivo';
    (X < 0) and (Y == 0) -> 'sobre el eje x negativo'
    end.


mayor(A,B,C) ->
  if
    (A >= B) and (A >= C) -> A;
    (B >= A) and (B >= C) -> B;
    (C >= A) and (C >= B) -> C
    end.

sumapar(D,E,F,G) ->
  if
    (D rem 2 == 0) and (E rem 2 == 0) and (F rem 2 == 0) and (G rem 2 == 0) -> (D + E + F + G);
    (D rem 2 == 0) and (E rem 2 == 0) and (F rem 2 == 0)-> (D + E + F);
    (D rem 2 == 0) and (E rem 2 == 0) and (G rem 2 == 0)-> (D + E + G);
    (E rem 2 == 0) and (F rem 2 == 0)and (G rem 2 == 0)-> (E + F + G);
    (D rem 2 == 0) and (E rem 2 == 0) -> D + E;
    (D rem 2 == 0) and (F rem 2 == 0) -> D + F;
    (D rem 2 == 0) and (G rem 2 == 0) -> D + G;
    (E rem 2 == 0) and (F rem 2 == 0)-> E + F;
    (E rem 2 == 0) and (G rem 2 == 0)-> E + G;
    (F rem 2 == 0)and (G rem 2 == 0)-> F + G;
    (E rem 2 == 0) -> E;
    (F rem 2 == 0) -> F;
    (G rem 2 == 0)-> G;
    (D rem 2 == 0) -> D;
    (D rem 2 /= 0) and (E rem 2 /= 0) and (F rem 2 /= 0) and (G rem 2 /= 0) -> 0
    end.


    



    


