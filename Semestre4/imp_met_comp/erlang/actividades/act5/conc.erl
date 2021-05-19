-module(conc).
-export([prueba_hola/2, prueba_hola/0, hola/0, hola/1]).


hola() -> 
    io:fwrite("~w~n", [0]),
    hola(0).
hola(C) ->
    receive
        {hola, P} ->
            P ! {reply, C+1},
            hola(C+1)
    end.

prueba_hola() ->
    H = spawn(?MODULE, hola,[]),
    prueba_hola (10, H).

 prueba_hola(N, H) when N > 0 ->
    H ! {hola, self()},
    receive
        {reply, C} ->
            io:format("Recibido ~w~n", [C]),
            prueba_hola(N-1, H)
    end;
prueba_hola(_, _) ->
    io:format("Mi trabajo esta hecho\n").