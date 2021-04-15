-module(recursivo).
-export ([fibo/1, fibot/1]).


fibo(0) -> 0;
fibo(1) -> 1;
fibo(N) -> fibo(N-1) + fibo(N-2).


fibot(X) -> fib_iter(1,0,X).
fib_iter(_, B, 0) -> B;
fib_iter(A,B,Count) -> fib_iter(A+B, A, Count-1).

