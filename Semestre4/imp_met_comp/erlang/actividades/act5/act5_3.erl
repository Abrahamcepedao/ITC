
%lucas Idigoras - A00827751
%Abraham Cepeda - 
-module (act5_3).
-export([profundidad/1, simetrico/1, elimina/2]).

%--------------profundidad------------------------------%
profundidad([P|R]) when  is_list(P) -> max(profundidad(P) + 1,  profundidad(R));
profundidad([_|R]) ->  profundidad(R);
profundidad([]) -> 0.


%--------------simetrico------------%
simetrico(0) -> [];
simetrico(X) -> [a,simetrico(X-1),a].





%--------------elimina------------------------------%
elimina(X,B) -> elimina_aux(X, B).