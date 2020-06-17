% Actividad 4 - Metodo Newton Raphson
% Abraham Cepeda Oseguera
% A00827666
function [xi, raizY, iter] = MetodoNewton(fx,dfx,xi,e,max)
    syms x
    iter = 0;
    while (abs(subs(fx,{x},xi)) >= e && iter < max)
        iter = iter + 1;
        xi = xi - (subs(fx,{x},xi)/subs(dfx,{x},xi));
    end
    raizY = subs(fx,{x},xi);
end

