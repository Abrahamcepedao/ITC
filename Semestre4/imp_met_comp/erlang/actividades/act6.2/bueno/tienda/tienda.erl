% Actividad Integradora 6.2 Programación Distribuida en Erlang
% Lunes 7 de junio del 2021
% Abraham Cepeda | A00827666
% José Alfredo Angulo Peñuelas | A00825063
% Lucas Eduardo Idigoras | A00827751


-module(tienda).
-import(lists,[append/2, delete/2, member/2, nth/2]).
-record(producto, {nombre, cantidad}). % record de producto - contiene el nombre y la cantidad disponible
-record(pedido, {numero, socio, lista_productos}). % record de pedido - contiene el  numero, socio y el listado de productos{nombre, cantidad}
-record(pedido_atendido, {socio, num_pedidos}). % record de pedido  atendido - contiene el socio y el numero de pedidos
-export([servidor/5, abrir_tienda/0]).

%Aqui tenemos el servidor donde toda la magia sucede donde todas las funciones se encuentran y
%son mandado los respectivos pid para que vaya mostrando lo que queremos.

% SO => lista de socios
% PR => lista de productos
% PE => lista de pedidos atendidos
% PP => lista de pedidos en proceso


% revisa la disponibilidad del producto
validar_pedido(T, PR) -> 
    Prod = tuple_to_list(T), % convertir la tupla (pedido) a una lista para poder acceder a los elementos
    PRTEMP = [X || X <- PR, X#producto.nombre==nth(1,Prod)], % Filtrar productos con el producto del pedido
    Prod2 = nth(1, PRTEMP), % Toma el primer elemento (producto)
    Cant = Prod2#producto.cantidad - nth(2, Prod), % Calcula la cantidad restante
    if % validar si la cantidad esta disponible
        (Cant < 0) -> Cant2 = Prod2#producto.cantidad; % no esta disponible: la cantidad será la cantidad disponible
        (Cant > 0) -> Cant2 = nth(2, Prod) % hay disponibilidad: la cantidad
    end,
    #producto{nombre=nth(1, Prod), cantidad=Cant2}. % regresa el producto con la cantidad solicidtada o la disponible
    
% Ejecuta la función que valida la disponibilidad del producto para cada producto del pedido
validar_pedidos([], _, PN) -> PN;
validar_pedidos([H|T], PR, PN) -> 
    PNTEMP = append([validar_pedido(H, PR)], PN), % se agrega el pedido modificado al listado para finalmente regresar el pedido actualizado
    validar_pedidos(T, PR, PNTEMP).

%Agregar cantidad de producto
actualizar_producto1(H, PR) ->
    Prod = tuple_to_list(H), % convertir la tupla a una lista para poder acceder a sus elementos
    PRTEMP = [X || X <- PR, X#producto.nombre==nth(1,Prod)], % filtrar los productos a los que tengan ese nombre
    Prod2 = nth(1, PRTEMP), % Tomar el primer elemento (producto)
    PRTEMP2 = [X || X <- PR, X#producto.nombre/=nth(1,Prod)], % filtra los productos a los que no tengan ese nombre
    Cant = Prod2#producto.cantidad + nth(2, Prod), % le agrega al producto la cantidad del pedido
    append([#producto{nombre=nth(1, Prod), cantidad=Cant}],PRTEMP2). % agrega a la lista de productos el producto modificado

% Disminuir cantidad de producto
actualizar_producto0(H, PR) ->
    Prod = tuple_to_list(H), % convertir la tupla a una lista para poder acceder a sus elementos
    PRTEMP = [X || X <- PR, X#producto.nombre==nth(2,Prod)], % filtrar los productos a los que tengan ese nombre
    Prod2 = nth(1, PRTEMP), % Tomar el primer elemento (producto)
    PRTEMP2 = [X || X <- PR, X#producto.nombre/=nth(2,Prod)], % filtra los productos a los que no tengan ese nombre 
    Cant = Prod2#producto.cantidad - nth(3, Prod), % le resta al producto la cantidad del pedido
    append([#producto{nombre=nth(2, Prod), cantidad=Cant}],PRTEMP2). % agrega a la lista de productos el producto modificado

% actualiza la lista de productos ya sea disminuyendo o aumentando
actualizar_productos(PR, [], _) -> PR;
actualizar_productos(PR, [H|T], Type) ->
    if
        (Type == 0) -> PRTEMP = actualizar_producto0(H, PR); % agregar a producto
        (Type == 1) -> PRTEMP = actualizar_producto1(H, PR) % disminuir a producto
    end,
    actualizar_productos(PRTEMP, T, Type).

servidor(SO, PR, PE, PP, N) -> 
    receive
        exit -> io:fwrite("Se ha cerrado la tienda...~n");

        %-------------socios-------------
        % Suscribir socio
        {suscribir_socio, Socio, P} -> 
            %Primero verificamos que el nombre no este en la lista
            Step = member(Socio, SO),
            if 
                (Step) -> 
                    %si esta en la lista les pedimos ingresar un nombre nuevo
                    P ! {response, "ingresa un nombre de socio diferente..."},
                    servidor(SO, PR, PE, PP, N);
                (not Step) -> 
                    %si no esta en la lista lo agregamos a la misma y actualizamos
                    SOTEMP = append([Socio], SO),
                    P ! {response, "socio agregado exitosamente..."},
                    servidor(SOTEMP, PR, PE, PP, N)
            end;
        
        % Eliminar socio
        {eliminar_socio, Socio, P} ->
            %Con la funcion de delete eliminamos el socio de la lista de socios y actualizamos la misma.
            SOTEMP = delete(Socio, SO),
            P ! {response, "Se eliminó el socio correctamente..."},
            servidor(SOTEMP, PR, PE, PP, N);
        
        % lista de socios
        {lista_socios, P} -> 
            %En esta funcion por el metodo pid enviamos la lista de los socios
            P ! {response, SO},
            servidor(SO, PR, PE, PP, N);


        
        %-------------productos-------------
        % Registar producto
        {registrar_producto, Producto, Cantidad, P} -> 
            %Guardamos en esta vareable todo lo necesario del mismo producto
            Po = #producto{nombre=Producto, cantidad=Cantidad},
            %Con la funcion de append agregamos el producto a la lista de los productos
            PRTEMP = append([Po], PR),
            P ! {response, "producto agregado exitosamente..."},
            servidor(SO, PRTEMP, PE, PP, N);

        % Eliminar producto
        {elimina_producto, Producto, P} ->
            %Eliminamos el producto con esta funcion integrada en erlang
            PRTEMP = [X || X <- PR, X#producto.nombre/=Producto],
            P ! {response, "producto  eliminado exitosamente..."},
            servidor(SO, PRTEMP, PE, PP, N);

        % Modifica producto
        {modifica_producto, Producto, Cantidad, P} -> 
            PRTEMP1 = [X || X <- PR, X#producto.nombre==Producto], % Filtra la lista de productos al que tenga ese nombre
            Prod = nth(1, PRTEMP1), % Toma el primer elemento (producto)
            Cant = Prod#producto.cantidad + Cantidad, % Le agrega o resta la cantidad especificada
            if % Evita que se le reste una cantidad mayor a la disponible. En ese caso se le asigna 0 de disponibilidad
                (Cant < 0) -> Prodtemp = #producto{nombre=Producto, cantidad=0};
                (Cant > 0) -> Prodtemp = #producto{nombre=Producto, cantidad=Cant}
            end,
            PRTEMP2 = [X || X <- PR, X#producto.nombre/=Producto], % Filtra la lista de productos al que no tenga ese nombre
            PRTEMP3 = append([Prodtemp], PRTEMP2), % Agrega el producto ya modificado
            P ! {response, "Se modificó el producto exitosamente..."},
            servidor(SO, PRTEMP3, PE, PP, N);

        % lista de productos en existencia
        {lista_existencias, P} ->
            %En esta funcion por el metodo pid enviamos la lista del producto en existencia.
            P ! {response, PR},
            servidor(SO, PR, PE, PP, N);


        %-------------pedidos-------------
        % Crear un nuevo pedido para un socio 
        {crea_pedido, Socio,ListaDeProductos, P} -> 
            Po = #pedido{numero=N, socio=Socio, lista_productos=ListaDeProductos}, % Crea un pedido con la información proporcionada
            PPTEMP = append([Po], PP),
            NTEMP = N+1, % Aumenta el número de pedidio

            % Revisar disponibilidad
            PN = validar_pedidos(ListaDeProductos, PR, []),

            % Editar disponibilidad
            PRTEMP = actualizar_productos(PR, PN, 0),

            P ! {response, PN, N},
            servidor(SO, PRTEMP, PE, PPTEMP, NTEMP);

        % Aceptar pedido
        {acepta_pedido, Socio, Pedido, P} -> 
            PPTEMP = [X || X <- PP, X#pedido.numero/=Pedido], % Filtra los pedidos en proceso con base al número de pedido
            PETEMP = [X || X <- PE, X#pedido_atendido.socio==Socio], % Filtra los pedidos en atendidos con base al socio
            L = length(PETEMP), % En esta variable se guarda el tamaño de la lista de pedidos atendidos
            if
                (L > 0) ->
                    Ped = nth(1, PETEMP), % Toma el primer elemento (pedido)
                    Cant = Ped#pedido_atendido.num_pedidos + 1, % Incrementa la cantidad de peidos atendidos
                    PETEMP2 = [X || X <- PE, X#pedido_atendido.socio/=Socio], % Filtra los pedidos en atendidos con base al socio
                    Pedtemp = #pedido_atendido{socio=Socio,num_pedidos=Cant},  % Crea un nuevo pedido con la información del socio actualizada
                    PETEMP3 = append([Pedtemp], PETEMP2); % Agrega el pedido a la lista de pedidos atendidos
                (L == 0) ->
                    Pedtemp = #pedido_atendido{socio=Socio,num_pedidos=1}, % Incrementa la cantidad de peidos atendidos a 1
                    PETEMP3 = append([Pedtemp], PE) % Agrega el pedido a la lista de pedidos atendidos
            end,
            P ! {response, "Pedido aceptado correctamente..."},
            servidor(SO, PR, PETEMP3, PPTEMP, N);
        
        % Rechazar pedido
        {rechaza_pedido, _, Pedido, P} -> 
            PPTEMP = [X || X <- PP, X#pedido.numero/=Pedido], % Filtra los pedidos en proceso con base al número de pedido 
            PPTEMP2 = [X#pedido.lista_productos || X <- PP, X#pedido.numero==Pedido], % Filtra los pedidos en proceso con base al número de pedido y regresa el listado de productos del pedido
            
            % editar disponibilidad
            PRTEMP = actualizar_productos(PR, nth(1,PPTEMP2), 1),

            P ! {response, "Pedido rechazado correctamente..."},
            servidor(SO, PRTEMP, PE, PPTEMP, N) ;
        
        % Lista de pedidos en proceso
        {pedidos_en_proceso, P} ->
            %En esta funcion por le metodo pid enviamos los pedidos en proceso
            P ! {response, PP},
            servidor(SO, PR, PE, PP, N);
        
        % Lista de pedidos atendidos 
        {pedidos_atendidos, P} ->
            %En esta funcion por el metodo pid enviamos los pedidos atendidos
            P ! {response, PE},
            servidor(SO, PR, PE, PP, N)
    end.

abrir_tienda() ->
    %Con esta funcion preparamos todo el servidor para empezar a recibir solicitudes
    Pid = spawn(tienda, servidor, [[],[],[],[], 0]),
    register(tienda, Pid).