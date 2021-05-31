-module(tienda).
-import(lists,[append/2, delete/2, member/2, nth/2]).
-record(producto, {nombre, cantidad}).
-record(pedido, {numero, socio, lista_productos}).
-record(pedido_atendido, {socio, num_pedidos}).
-export([servidor/5, abrir_tienda/0]).
%acciones
% ----socio----
%     -> suscribir socio
%     -> eliminar socio 
%     -> lista de socios
% ----prroductos/pedidos----
%     -> crear pedidos
%     -> acepta pedidos 
%     -> rechazar pedidos
%     -> lista de pedidos en proceso
%     -> lista de pedidos atendidos
%     -> lista de existencias
%     -> registrar productos 
%     -> eliminar productos
%     -> modificar productos

% SO => lista de socios
% PR => lista de productos
% PE => lista de pedidos atendidos
% PP => lista de pedidos en proceso
servidor(SO, PR, PE, PP, N) -> 
    receive
        exit -> io:fwrite("Se ha cerrado la tienda...~n");

        %-------------socios-------------
        % Suscribir socio
        {suscribir_socio, Socio, P} -> 
            io:fwrite("Agregando socio...~n"),
            Step = member(Socio, SO),
            if 
                (Step) -> 
                    P ! {response, "ingresa un nombre de socio diferente..."},
                    servidor(SO, PR, PE, PP, N);
                (not Step) -> 
                    SOTEMP = append([Socio], SO),
                    P ! {response, "socio agregado exitosamente..."},
                    servidor(SOTEMP, PR, PE, PP, N)
            end;
        
        % Eliminar socio
        {eliminar_socio, Socio, P} ->
            io:fwrite("Eliminando socio...~n"),
            SOTEMP = delete(Socio, SO),
            P ! {response, "Se eliminó el socio correctamente..."},
            servidor(SOTEMP, PR, PE, PP, N);
        
        % lista de socios
        {lista_socios, P} -> 
            io:fwrite("Imprimiendo lista de socios...~n"),
            P ! {response, SO},
            servidor(SO, PR, PE, PP, N);


        
        %-------------productos-------------
        % Registar producto
        {registrar_producto, Producto, Cantidad, P} ->
            io:fwrite("Agregando producto...\n"),
            Po = #producto{nombre=Producto, cantidad=Cantidad},
            PRTEMP = append([Po], PR),
            P ! {response, "producto agregado exitosamente..."},
            servidor(SO, PRTEMP, PE, PP, N);

        % Eliminar producto
        {elimina_producto, Producto, P} ->
            io:fwrite("Eliminando producto...\n"),
            PRTEMP = [X || X <- PR, X#producto.nombre/=Producto],
            P ! {response, "producto  eliminado exitosamente..."},
            servidor(SO, PRTEMP, PE, PP, N);

        % Modifica producto
        {modifica_producto, Producto, Cantidad, P} ->
            io:fwrite("Modficando producto...\n"),
            PRTEMP1 = [X || X <- PR, X#producto.nombre==Producto],
            io:fwrite("Respuesta: ~p~n", [PRTEMP1]),
            Prod = nth(1, PRTEMP1),
            Cant = Prod#producto.cantidad + Cantidad,
            if
                (Cant < 0) -> Prodtemp = #producto{nombre=Producto, cantidad=0};
                (Cant > 0) -> Prodtemp = #producto{nombre=Producto, cantidad=Cant}
            end,
            PRTEMP2 = [X || X <- PR, X#producto.nombre/=Producto],
            PRTEMP3 = append([Prodtemp], PRTEMP2),
            P ! {response, "Se modificó el producto exitosamente..."},
            servidor(SO, PRTEMP3, PE, PP, N);

        % lista de productos en existencia
        {lista_existencias, P} ->
            io:fwrite("Imprimiendo productos...\n"),
            P ! {response, PR},
            servidor(SO, PR, PE, PP, N);


        %-------------pedidos-------------
        % Crear un nuevo pedido para un socio 
        {crea_pedido, Socio,ListaDeProductos, P} ->
            Po = #pedido{numero=N, socio=Socio, lista_productos=ListaDeProductos},
            PPTEMP = append([Po], PP),
            NTEMP = N+1,

            P ! {response, "Pedido creado correctamente..."},
            servidor(SO, PR, PE, PPTEMP, NTEMP);

        % Aceptar pedido
        {acepta_pedido, Socio, Pedido, P} ->
            PPTEMP = [X || X <- PP, X#pedido.numero/=Pedido],
            PETEMP = [X || X <- PE, X#pedido_atendido.socio==Socio],
            L = length(PETEMP),
            if
                (L > 0) ->
                    Ped = nth(1, PETEMP),
                    Cant = Ped#pedido_atendido.num_pedidos + 1,
                    PETEMP2 = [X || X <- PE, X#pedido_atendido.socio/=Socio],
                    Pedtemp = #pedido_atendido{socio=Socio,num_pedidos=Cant},
                    PETEMP3 = append([Pedtemp], PETEMP2);
                (L == 0) ->
                    Pedtemp = #pedido_atendido{socio=Socio,num_pedidos=1},
                    PETEMP3 = append([Pedtemp], PE)
            end,
            P ! {response, "Pedido aceptado correctamente..."},
            servidor(SO, PR, PETEMP3, PPTEMP, N);
        
        % Rechazar pedido
        {rechaza_pedido, _, Pedido, P} ->
            PPTEMP = [X || X <- PP, X#pedido.numero/=Pedido],
            P ! {response, "Pedido rechazado correctamente..."},
            servidor(SO, PR, PE, PPTEMP, N) ;
        
        % Lista de pedidos en proceso
        {pedidos_en_proceso, P} ->
            io:fwrite("Imprimiendo pedidos en proceso...\n"),
            P ! {response, PP},
            servidor(SO, PR, PE, PP, N);
        
        % Lista de pedidos atendidos 
        {pedidos_atendidos, P} ->
            io:fwrite("Imprimiendo pedidos atendidos...\n"),
            P ! {response, PE},
            servidor(SO, PR, PE, PP, N)
    end.

abrir_tienda() ->
    %spawn('tienda@Abrahams-MacBook-Pro-2', tienda, servidor, [[],[],[],[], 0]).
    Pid = spawn(tienda, servidor, [[],[],[],[], 0]),
    register(pidtienda, Pid).