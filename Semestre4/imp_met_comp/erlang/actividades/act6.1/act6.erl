-module(act6).
-import(lists,[append/2, delete/2, member/2]).
-export([prueba_suma/0,prueba_suma/2, suma/0, suma/1, prueba_registro/0, 
    prueba_registro/1, registro/1, recibe_resultado/0,print_message/0,
    print_message/1,anillo/3,anillo/4, send_messages/4, send_messages_n/3]).

suma() -> suma(0).
suma(C) ->
    receive
        {suma, N, P} ->
            P ! {respuesta,C+N},
            suma(C+N)
        end.

prueba_suma() ->
    P = spawn(?MODULE, suma, []),
    prueba_suma(10, P).
prueba_suma(N, P) when N > 0 ->
    P ! {suma, N, self()},
    receive
        {respuesta, S} ->
            io:format("Acumulado ~w~n", [S]),
            prueba_suma(N-1, P)
    end;
prueba_suma(_, _) ->
    io:format("Terminé mi trabajo~n").

registro(L) ->
    receive 
        {registra, Nombre} ->
            Step = member(Nombre, L),
            if
                (Step) -> registro(L);
                (not Step) -> 
                    L2 = append([Nombre],  L),
                    registro(L2)
            end;
        {elimina, Nombre} ->
            L2 = delete(Nombre, L),
            registro(L2);
        {busca, Nombre, P} ->
            Step = member(Nombre, L),
            if
                (Step) -> P ! {encontrado, "Si"};
                (not Step) -> P ! {encontrado, "No"}
            end,
            registro(L);
        {lista, P} ->
            P ! {registrados, L},
            registro(L);
        temina -> io:format("Terminar servidor\n")
    end.

recibe_resultado() ->
    receive
        {encontrado, E} -> E;
        {registrados, L} -> L
    end.

prueba_registro() ->
    L = [],
    P = spawn(?MODULE, registro, [L]),
    prueba_registro(P).
prueba_registro(P) ->
    io:format("\n\nregistrando usuario Abraham..\n"),
    P ! {registra, "Abraham"},
    
    io:format("registrando usuaria Fernanda..\n"),
    P ! {registra, "Fernanda"},
    
    io:format("registrando usuaria Jimena..\n"),
    P ! {registra, "Jimena"},
    
    io:format("registrando usuario Ignacio..\n"),
    P ! {registra, "Ignacio"},
    
    P ! {lista, self()},
    io:format("\nlista de usuarios ~p~n", [recibe_resultado()]),
    
    io:format("\n\nbuscando usuario abraham..\n"),
    P ! {busca, "Abraham", self()},
    io:format("Abraham encontrado: ~p~n", [recibe_resultado()]),
    
    io:format("\neliminando usuario abraham..\n"),
    P ! {elimina, "Abraham"},
    
    io:format("\nbuscando usuario abraham..\n"),
    P ! {busca, "Abraham", self()},
    io:format("Abraham encontrado: ~p~n\n", [recibe_resultado()]),
    
    P ! {lista, self()},
    io:format("\nlista de usuarios ~p~n", [recibe_resultado()]),

    P ! termina,
    ok.


print_message() -> print_message(0).
print_message(X) ->
    receive
        {print, P} ->
            P ! {reply,  X+1},
            print_message(X+1)
    end.

send_messages_n(N, M, Message) -> 
    P = spawn(?MODULE, print_message, []),
    send_messages(N, M, Message, P).
send_messages(N, M, Message,P) when N > 0 -> 
    P ! {print, self()},
    receive
        {reply, X} ->
            io:format("p: ~w - n: ~w - m: ~p\n", [M, X, Message]),
            send_messages(N-1, M, Message, P)

    end;
send_messages(0, M, _, _) ->
    io:format("Termino el proceso ~w~n", [M]).

anillo(N, M, Message) -> anillo(N, 1, M, Message).
    
anillo(N, Y, M, Message) when M > 0 ->
    send_messages_n(N, Y, Message),
    anillo(N, Y+1, M-1, Message);
        
anillo(_, _, _, _) ->
    io:format("Se terminó el trabajo~n").
