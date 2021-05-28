-module(socios).
-export([abrir_tienda/0, cerrar_tienda/0]).


abrir_tienda() ->
    register(tienda, spawn('tienda@Abrahams-MacBook-Pro-2', tienda, abre_tienda, [])).

cerrar_tienda() -> 
    tienda ! exit.