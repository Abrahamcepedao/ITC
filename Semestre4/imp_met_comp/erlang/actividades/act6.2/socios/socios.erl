-module(socios).
-export([suscribir_socio/1, eliminar_socio/1, lista_socios/0, crea_pedido/2, 
        acepta_pedido/2, rechaza_pedido/2, pedidos_en_proceso/0,
        pedidos_atendidos/0, lista_existencias/0]).

matriz() -> 'tienda@Abrahams-MacBook-Pro-2'.

% <------------------Socios------------------>
% <------Suscribir socio------>
suscribir_socio(Socio) -> 
    {tienda, matriz()} ! {suscribir_socio, Socio, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Eliminar socio------>
eliminar_socio(Socio) ->
    {tienda, matriz()} ! {eliminar_socio, Socio, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Lista de socios------>
lista_socios() ->
    {tienda, matriz()} ! {lista_socios, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.


% <------------------Pedidos------------------>
% <------Crear pedido------>
crea_pedido(Socio, ListaDeProductos) ->
    {tienda, matriz()} ! {crea_pedido, Socio, ListaDeProductos, self()},
    receive
        {response, R, N} -> 
            io:fwrite("Número de pedido: ~w~n", [N]),
            io:fwrite("Así quedó su pedido: ~p~n", [R]),
            io:fwrite("Ahora puede aceptar o rechazar su pedido..~n")
    end.
% <------Acepta pedido------>
acepta_pedido(Socio, Pedido) ->
    {tienda, matriz()} ! {acepta_pedido, Socio, Pedido, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Rechaza pedido------>
rechaza_pedido(Socio, Pedido) ->
    {tienda, matriz()} ! {rechaza_pedido, Socio, Pedido, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Pedidos en proceso------>
pedidos_en_proceso() ->
    {tienda, matriz()} ! {pedidos_en_proceso, self()},
    receive
        {response, R} -> io:fwrite("Pedidos: ~p~n", [R])
    end.

% <------Pedidos atendidos------>
pedidos_atendidos() ->
    {tienda, matriz()} ! {pedidos_atendidos, self()},
    receive
        {response, R} -> io:fwrite("Pedidos: ~p~n", [R])
    end.

% <------Lista de existencias (producto)------>
lista_existencias() ->
    {tienda, matriz()} ! {lista_existencias, self()},
    receive
        {response, R} -> io:fwrite("Productos: ~p~n", [R])
    end.