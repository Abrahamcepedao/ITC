-module(tienda).
-import(lists,[append/2, delete/2, member/2, nth/2]).
-record(producto, {nombre, cantidad}).
-export([servidor/4]).
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
servidor(SO, PR, PE, PP) -> 
    receive
        exit -> io:fwrite("Se ha cerrado la tienda...~n");

        %-------------socios-------------
        % Suscribir socio
        {suscribir_socio, Socio} -> 
            io:fwrite("Agregando socio...~n"),
            Step = member(Socio, SO),
            if 
                (Step) -> 
                    %P ! {error, "ingresa un nombre de socio diferente..."},
                    servidor(SO, PR, PE, PP);
                (not Step) -> 
                    SOTEMP = append([Socio], SO),
                    %P ! {exito, "socio agregado exitosamente..."},
                    servidor(SOTEMP, PR, PE, PP)
            end;
        
        % Eliminar socio
        {eliminar_socio, Socio} ->
            io:fwrite("Eliminando socio...~n"),
            SOTEMP = delete(Socio, SO),
            servidor(SOTEMP, PR, PE, PP);
        
        % lista de socios
        {lista_socios} -> 
            io:fwrite("Imprimiendo lista de socios...~n"),
            io:fwrite("Socios: ~p~n", [SO]),
            servidor(SO, PR, PE, PP);


        
        %-------------productos-------------
        % Registar producto
        {registrar_producto, Producto, Cantidad} ->
            io:fwrite("Agregando producto...\n"),
            Po = #producto{nombre=Producto, cantidad=Cantidad},
            PRTEMP = append([Po], PR),
            %P ! {exito, "producto agregado exitosamente..."},
            servidor(SO, PRTEMP, PE, PP);

        % Eliminar producto
        {elimina_producto, Producto} ->
            io:fwrite("Eliminando producto...\n"),
            PRTEMP = [X || X <- PR, X#producto.nombre/=Producto],
            servidor(SO, PRTEMP, PE, PP);

        % Modifica producto
        {modifica_producto, Producto, Cantidad} ->
            io:fwrite("Modficando producto...\n"),
            PRTEMP1 = [X || X <- PR, X#producto.nombre==Producto],
            Prod = nth(1, PRTEMP1),
            Cant = Prod#producto.cantidad + Cantidad,
            if
                (Cant < 0) -> Prodtemp = #producto{nombre=Producto, cantidad=0};
                (Cant > 0) -> Prodtemp = #producto{nombre=Producto, cantidad=Cant}
            end,
            PRTEMP2 = [X || X <- PR, X#producto.nombre/=Producto],
            PRTEMP3 = append([Prodtemp], PRTEMP2),
            servidor(SO, PRTEMP3, PE, PP);

        % lista de productos en existencia
        {lista_existencias} ->
            io:fwrite("Imprimiendo productos...\n"),
            io:fwrite("Productos: ~p~n", [PR]),
            %P ! {lista_productos, PR},
            servidor(SO, PR, PE, PP)


        %-------------pedidos-------------
        
    end.