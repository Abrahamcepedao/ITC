% Soluciones a los ejercicios de programación concurrente en Erlang
-module(conc).
-export([hola/0, prueba_hola/0, calcula/0, prueba_calcula/0,
    inicio/0, ejecuta/3, despliega/1, termina/0, cliente/0, prueba_servidor/0]).
-author('Santiago Conant').

% (1) Implementa el proceso hola en Erlang que acepta un mensaje
%   {hola, P}, donde P se asume que es un pid. Para cada mensaje, el
%   proceso manda {reply, C} a P (donde C es un contador).
hola() -> hola(0).
hola(C) -> receive
               {hola, P} -> NC = C + 1,
			                P ! {reply, NC},
							hola(NC)
			end.

%Programa de prueba.
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
    io:format("Mi trabajo está hecho~n").

% (2) Implementa el proceso calcula que maneja los siguientes mensajes: 
%	{suma, X, Y}	calcula la suma de X y Y
%	{multiplica, X, Y}	calcula el producto de X y Y
%	{ultimo, P}	manda un mensaje de la forma {resultado, L} al proceso P. 
%               L debe ser el último valor calculado.
%	{total, P}	manda un mensaje de la forma {resultado, S} al proceso P. 
%               S debe ser la suma de todos los valores calculados. 
%	termina		avisa y termina de ejecutarse.
calcula() -> calcula(0,0).
calcula(L, S) ->
   receive
       {suma, X, Y} -> 
           Suma = X + Y,
           calcula(Suma, S + Suma);
	   {multiplica, X, Y} -> 
           Producto = X * Y,
           calcula(Producto, S + Producto);
	   {ultimo, P} -> 
           P ! {resultado, L},
           calcula(L, S);
	   {total, P} -> 
           P ! {resultado, S},
           calcula(L, S);
        termina -> 
            io:format("Termina servidor~n", [])
   end.
					   
% recibe un resultado
recibe_resultado() -> 
   receive
      {resultado, R} -> R
   end.

% Programa de prueba.   
prueba_calcula() ->
   Cpid = spawn(?MODULE, calcula, []),
   Dpid = self(),
   io:format("suma 1 + 2~n"),
   Cpid ! {suma, 1, 2},
   Cpid ! {ultimo, Dpid},
   io:format("ultimo ~w~n", [recibe_resultado()]),
   io:format("suma 3 + 4~n"),
   Cpid ! {suma, 3, 4},
   Cpid ! {ultimo, Dpid},
   io:format("ultimo ~w~n", [recibe_resultado()]),
   Cpid ! {total, Dpid},
   io:format("total ~w~n", [recibe_resultado()]),
   io:format("multiplica 1 * 2~n"),
   Cpid ! {multiplica, 1, 2},
   Cpid ! {ultimo, Dpid},
   io:format("ultimo ~w~n", [recibe_resultado()]),
   io:format("multiplica 3 * 4~n"),
   Cpid ! {multiplica, 3, 4},
   Cpid ! {ultimo, Dpid},
   io:format("ultimo ~w~n", [recibe_resultado()]),
   Cpid ! {total, Dpid},
   io:format("total ~w~n", [recibe_resultado()]),
   Cpid ! termina,
   ok.
 
% 3. Implementar el proceso conc:cliente que interactúe con el proceso
%  conc:calcula del problema anterior. Registrar los procesos con los nombres
%  cliente y servidor, respectivamente. Implementar las siguientes funciones 
% de interfaz:

% •	inicio() – crea y registra los procesos cliente y servidor.
% •	ejecuta(Operación, X, Y) – le pide al cliente que solicite una Operación 
%   (suma o multiplica) con los valores X y Y. Despliega un mensaje de error 
%   si no reconoce la operación. 
% •	despliega(Valor) – le pide al cliente que despliegue un valor calculado 
%   (ultimo o total). Despliega un mensaje de error si no reconoce el valor 
%   solicitado.
% •	termina() – le pide al cliente y al servidor que terminen de ejecutarse.
% Escribe la función conc:prueba_servidor como la función prueba_hola del problema 
% anterior para probar tu código. 

% función que implementa el proceso
cliente() ->
    receive
        {ejecuta, Operacion, X, Y} -> 
            case Operacion of
                suma ->
                    io:format("suma ~w + ~w~n", [X, Y]),
                    servidor ! {suma, X, Y};
                multiplica ->
                    io:format("multiplica ~w * ~w~n", [X, Y]),
                    servidor ! {multiplica, X, Y};
                Error ->
                    io:format("Operación ~w desconocida~n", [Error])
            end,
            cliente();
        {despliega, Valor} -> 
            Dpid = whereis(cliente),
            case Valor of
                ultimo ->
                    servidor ! {ultimo, Dpid},
                    io:format("ultimo ~w~n", [recibe_resultado()]);
                total ->
                    servidor ! {total, Dpid},
                    io:format("total ~w~n", [recibe_resultado()]);
                Error ->
                    io:format("Valor ~w desconocido~n", [Error])
            end,
            cliente();
        termina -> 
            io:format("Termina cliente~n", [])
     end.

inicio() ->
    io:format("Crea servidor~n", []),
    register(servidor, spawn(?MODULE, calcula, [])),
    io:format("Crea cliente~n", []),
    register(cliente, spawn(?MODULE, cliente, [])).

ejecuta(Operacion, X, Y) -> 
    cliente ! {ejecuta, Operacion, X, Y}.

despliega(Valor) -> 
    cliente ! {despliega, Valor}.

termina() -> 
    % verifica si cliente y servidor están registrados
    cliente ! termina,
    servidor ! termina.

prueba_servidor() ->
    inicio(),
    ejecuta(suma, 1, 2),
    despliega(ultimo),
    ejecuta(suma, 3, 4),
    despliega(ultimo),
    despliega(total),
    ejecuta(multiplica, 1, 2),
    despliega(ultimo),
    ejecuta(multiplica, 3, 4),
    despliega(ultimo),
    despliega(total),
    ejecuta(divide, 10, 2),     % error
    despliega(primero),         % error
    timer:sleep(1000),   % para darle tiempo antes de eliminar los procesos
    termina(),  
    ok.


