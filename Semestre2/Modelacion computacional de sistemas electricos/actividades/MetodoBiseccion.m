% Actividad 4 - Metodo Biseccion
% Abraham Cepeda Oseguera
% A00827666
function [raizX, raizY, iter] = MetodoBiseccion(fx,a,b,e,max)
    syms x
    m = (a+b)/2;
    iter = 1;
    while (abs(subs(fx,{x},m)) > e && iter < max)
        if subs(fx,{x},a)*subs(fx,{x},m) < 0
            b = m;
        else
            a = m;
        end
        m = (a+b)/2;
        iter = iter + 1;
    end
    raizX = m;
    raizY = subs(fx,{x},m);
end
