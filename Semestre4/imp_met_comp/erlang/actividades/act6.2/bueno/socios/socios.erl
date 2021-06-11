% Actividad Integradora 6.2 Programación Distribuida en Erlang
% Lunes 7 de junio del 2021
% Abraham Cepeda | A00827666
% José Alfredo Angulo Peñuelas | A00825063
% Lucas Eduardo Idigoras | A00827751

-module(socios).
-import(lists,[nth/2]).
-export([suscribir_socio/1, eliminar_socio/1, lista_socios/0, crea_pedido/2, 
        acepta_pedido/2, rechaza_pedido/2, pedidos_en_proceso/0,
        pedidos_atendidos/0, lista_existencias/0]).
-record(producto, {nombre, cantidad}). % record de producto - contiene el nombre y la cantidad disponible
-record(pedido, {numero, socio, lista_productos}). % record de pedido - contiene el  numero, socio y el listado de productos{nombre, cantidad}
-record(pedido_atendido, {socio, num_pedidos}). % record de pedido  atendido - contiene el socio y el numero de pedidos

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


% imprime socio
imprime_socio(P, N) -> 
    io:fwrite("~nSocio: ~w~n", [N]),
    io:fwrite("-->nombre: ~w~n", [P]).

% imprime lista de socios
imprime_socios([],_) -> ok;
imprime_socios([H|T], N) -> 
    imprime_socio(H, N), 
    imprime_socios(T, N+1).

% imprime pedido atendido
imprime_pedidoa(P, N) -> 
    io:fwrite("~nPedido: ~w~n", [N]),
    io:fwrite("-->nombre de socio: ~w~n", [P#pedido_atendido.socio]),
    io:fwrite("-->numero de pedidos: ~w~n", [P#pedido_atendido.num_pedidos]).

% imprime lista de pedidos atendidos
imprime_pedidoas([],_) -> ok;
imprime_pedidoas([H|T], N) -> 
    imprime_pedidoa(H, N), 
    imprime_pedidoas(T, N+1).


% imprime producto de lista de pedidos en proceso
imprime_productop(P, N) ->
    Prod = tuple_to_list(P),
    Name = nth(1, Prod),
    Cant = nth(2, Prod),
    io:fwrite("Producto: ~w~n", [N]),
    io:fwrite("-->nombre: ~w~n", [Name]),
    io:fwrite("-->cantidad: ~w~n~n", [Cant]).

% imprime productos de lista de pedidos en proceso
imprime_productosp([], _) -> ok;
imprime_productosp([H|T],N) ->
    imprime_productop(H, N),
    imprime_productosp(T, N+1).

% imprime pedido en proceso
imprime_pedidop(P) -> 
    io:fwrite("~nPedido: ~w~n", [P#pedido.numero]),
    io:fwrite("-->socio: ~w~n", [P#pedido.socio]),
    io:fwrite("-->lista de productos:~n"),
    imprime_productosp(P#pedido.lista_productos, 1).

% imprime lista de pedidos en proceso
imprime_pedidops([]) -> ok;
imprime_pedidops([H|T]) -> 
    imprime_pedidop(H), 
    imprime_pedidops(T).


% contiene el nombre del nodo (cambiar para probar el código)
matriz() -> 'tienda@Abrahams-MacBook-Pro-2'.

%Al igual que la funcion de productos aqui es donde llamamos los distintos metodos en adicion a los metodos
%de socios tambien contamos con los metodos de pedido que con verificaciones de los metodos de productos
%podemos crear solicitudes para los diferentes tipos de pedidos.

% <------------------Socios------------------>
% <------Suscribir socio------>
suscribir_socio(Socio) -> 
    io:fwrite("Agregando socio: ~p~n", [Socio]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {suscribir_socio, Socio, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Eliminar socio------>
eliminar_socio(Socio) ->
    io:fwrite("Eliminando socio: ~p~n", [Socio]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {eliminar_socio, Socio, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Lista de socios------>
lista_socios() ->
    io:fwrite("Imprimiendo lista de socios...~n"),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {lista_socios, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> imprime_socios(R, 1)
    end.


% <------------------Pedidos------------------>
% <------Crear pedido------>
crea_pedido(Socio, ListaDeProductos) ->
    io:fwrite("Creando pedido para socio: ~p~n", [Socio]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {crea_pedido, Socio, ListaDeProductos, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R, N} -> 
            io:fwrite("Número de pedido: ~w~n", [N]),
            io:fwrite("Así quedó su pedido: ~n"),
            imprime_productos(R, 1),
            io:fwrite("Ahora puede aceptar o rechazar su pedido..~n")
    end.
% <------Acepta pedido------>
acepta_pedido(Socio, Pedido) ->
    io:fwrite("Aceptando pedido ~w para socio: ~p~n", [Pedido,  Socio]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {acepta_pedido, Socio, Pedido, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Rechaza pedido------>
rechaza_pedido(Socio, Pedido) ->
    io:fwrite("Rechazando pedido ~w para socio: ~p~n", [Pedido,  Socio]),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {rechaza_pedido, Socio, Pedido, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> io:fwrite("Respuesta: ~p~n", [R])
    end.

% <------Pedidos en proceso------>
pedidos_en_proceso() ->
    io:fwrite("Imprimiendo pediodos en proceso...~n"),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {pedidos_en_proceso, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> imprime_pedidops(R)
    end.

% <------Pedidos atendidos------>
pedidos_atendidos() ->
    io:fwrite("Imprimiendo pediodos en atendidos...~n"),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {pedidos_atendidos, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> imprime_pedidoas(R, 1)
    end.

% <------Lista de existencias (producto)------>
lista_existencias() ->
    io:fwrite("Imprimiendo lista de productos...~n"),
    %Envia por un pid lo que se desee hacer y espera la respuesta
    {tienda, matriz()} ! {lista_existencias, self()},
    receive
        %al recibir se desplegara lo que se pidio
        {response, R} -> imprime_productos(R, 1)
    end.