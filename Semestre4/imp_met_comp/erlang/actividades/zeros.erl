-module(main).
-export([zeros/1]).

zeros(n) when n > 0 -> [0]++zeros(n-1).


