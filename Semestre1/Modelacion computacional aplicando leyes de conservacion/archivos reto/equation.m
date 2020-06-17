syms x
ecuacion = exp(x) * log(x);
sup = 2;
inf = 1;
n = 1;
for i=1:4
    resultado = trapezium(ecuacion, inf, sup, n);
    fprintf("El resultado es: %.4f\n", resultado);
    n = n * 2;
end


%y\ =-0.000002\ x^{3}+0.00584848x^{2}-4.0197x+845.48\ \left\{100<x<2000\right\}

function [res] = trapezium(ecuacion, inf, sup, n)
    syms x
    deltax = (sup - inf) / n;
    f0 = subs(ecuacion, {x}, inf);
    res = 0;
    for i = (inf + deltax):deltax:(sup - deltax)
        res = res + (subs(ecuacion, {x}, i)) * 2;
    end    
    fn = subs(ecuacion, {x}, sup);
    res = (f0 + res + fn) * (deltax / 2);
end