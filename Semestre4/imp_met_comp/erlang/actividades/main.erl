-module(main).
-export([armonica/1, sube_baja/1, fibo/1, fibot/1]).


%<-------armonica-------->
armonica(0) -> 0;
armonica(N) when N > 0 ->
    1/N + armonica(N-1).


%<-------sube_baja-------->
sube_baja(N) -> baja(N, N).
baja(1, M) -> 
    %io:format("~2.. B", [1]),
    io:write(1),
    io:fwrite("~tc", [32]),
    sube(1, M);

baja(N, M) when N > 1 ->
    io:write(N),
    io:fwrite("~tc", [32]),
    baja(N-1, M).

sube(M, M) ->
    io:write(M),
    io:fwrite("~tc~n", [32]);

sube(N, M) when N < M ->
    io:write(N),
    io:fwrite("~tc", [32]),
    sube(N+1, M).


%<-------fibo-------->
fibo(0) -> 0;
fibo(1) -> 1;
fibo(N) -> fibo(N-1) + fibo(N-2).


%<-------fibot-------->
fibot(X) -> fib_iter(1,0,X).
fib_iter(_, B, 0) -> B;
fib_iter(A,B,Count) -> fib_iter(A+B, A, Count-1).