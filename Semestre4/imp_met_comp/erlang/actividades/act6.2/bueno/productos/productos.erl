% Actividad Integradora 6.2 Programación Distribuida en Erlang
% Lunes 7 de junio del 2021
% Abraham Cepeda | A00827666
% José Alfredo Angulo Peñuelas | A00825063
% Lucas Eduardo Idigoras | A00827751

-module(productos).
-export([registrar_producto/2, lista_existencias/0, eliminar_producto/1, modifica_producto/2]).
-record(producto, {nombre, cantidad}). % record de producto - contiene el nombre y la cantidad disponible

% contiene el nombre del nodo (cambiar para probar el código)
matriz() -> 'tienda@Abrahams-MacBook-Pro-2'.

% <----funciones de impresion------>
% imprime producto
imprime_producto(P, N) -> 
    io:fwrite("~nProducto: ~w~n", [N]),
    io:fwrite("-->nombre: ~w~n", [P#producto.nombre]),
    io:fwrite("-->cantidad: ~w~n", [P#producto.cantidad]).

% imprime lista de productos
imprime_productos([],_) -> ok;
imprime_productos([H|T], N) -> 
    imprime_producto(H, N), 
    imprime_productos(T, N+1).

%En esta funcion es donde llamamos los distintos metodos para los productos desde el registrar hasta el
%modificar en adicion a esto tambien tenemos la funcion de lista existencias que nos muestra todos los
%productos en existencia.


% <------Registrar producto------>
registrar_producto(Producto, Cantidad) ->
    io:fwrite("Agregando producto: ~p~n", [Producto]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {registrar_producto, Producto, Cantidad, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Eliminar producto------>
eliminar_producto(Producto) ->
    io:fwrite("Eliminando producto: ~p~n", [Producto]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {elimina_producto, Producto, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Modificar producto------>
modifica_producto(Producto, Cantidad) ->
    io:fwrite("Modificando producto: ~p~n", [Producto]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {modifica_producto, Producto, Cantidad, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Lista de existencias (producto)------>
lista_existencias() ->
    io:fwrite("Imprimiendo productos...\n"),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {lista_existencias, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> imprime_productos(R, 1)
    end.