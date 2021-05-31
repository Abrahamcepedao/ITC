-module(productos).
-export([registrar_producto/2, lista_existencias/0, eliminar_producto/1, modifica_producto/2]).


% <------Registrar producto------>
registrar_producto(Producto, Cantidad) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {registrar_producto, Producto, Cantidad, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.
% <------Eliminar producto------>
eliminar_producto(Producto) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {elimina_producto, Producto, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Modificar producto------>
modifica_producto(Producto, Cantidad) ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {modifica_producto, Producto, Cantidad, self()},
    receive
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Lista de existencias (producto)------>
lista_existencias() ->
    {pidtienda, 'tienda@Abrahams-MacBook-Pro-2'} ! {lista_existencias, self()},
    receive
        {response, R} -> io:fwrite("Productos: ~p~n", [R])
    end.