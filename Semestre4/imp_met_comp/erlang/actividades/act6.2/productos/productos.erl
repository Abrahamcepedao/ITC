-module(productos).
-export([abrir_tienda/0, cerrar_tienda/0]).


abrir_tienda() ->
    spawn('tienda@Abrahams-MacBook-Pro-2', tienda, servidor, [[],[],[],[]]).
    %PID = spawn('tienda@Abrahams-MacBook-Pro-2', tienda, servidor, [[],[],[],[]]),
    %register(pidtienda, PID).

cerrar_tienda() -> 
    pidtienda ! exit.