-module(socios).
-export([suscribir_socio/1, eliminar_socio/1, lista_socios/0, crea_pedido/2, 
        acepta_pedido/2, rechaza_pedido/2, pedidos_en_proceso/0, pedidos_atendidos/0]).


% <------------------Socios------------------>
% <------Suscribir socio------>
suscribir_socio(Socio) -> 
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {suscribir_socio, Socio, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Eliminar socio------>
eliminar_socio(Socio) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {eliminar_socio, Socio, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Lista de socios------>
lista_socios() ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {lista_socios, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.


% <------------------Pedidos------------------>
% <------Crear pedido------>
crea_pedido(Socio, ListaDeProductos) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {crea_pedido, Socio, ListaDeProductos, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.
% <------Acepta pedido------>
acepta_pedido(Socio, Pedido) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {acepta_pedido, Socio, Pedido, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Rechaza pedido------>
rechaza_pedido(Socio, Pedido) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {rechaza_pedido, Socio, Pedido, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Pedidos en proceso------>
pedidos_en_proceso() ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {pedidos_en_proceso, self()},
    receive
        {response, R} -> io:fwrite("Pedidos: ~p~n", [R])
    end.

% <------Pedidos atendidos------>
pedidos_atendidos() ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {pedidos_atendidos, self()},
    receive
        {response, R} -> io:fwrite("Pedidos: ~p~n", [R])
    end.