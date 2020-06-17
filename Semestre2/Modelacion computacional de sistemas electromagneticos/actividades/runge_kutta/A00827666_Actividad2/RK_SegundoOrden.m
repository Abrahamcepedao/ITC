% Abraham Cepeda Oseguera
% A00827666
% Funcion Runge-kutta 2do. Orden
function [x,y] = RK_SegundoOrden(f,xi,xf,yi,h,a2)
    x = [xi:h:xf];
    y = zeros(1,length(x));
    y(1) = yi;
    
    a1 = 1 - a2;
    p1 = 1/(2*a2);
    q11 = p1;
    for i = 1:length(x)-1
       k1 = f(x(i), y(i));
       k2 = f(x(i)+p1*h, y(i)+q11*k1*h);
       y(i+1) = y(i) + (a1*k1+a2*k2)*h;
       %fprintf('i %d xi %2.5f yi %2.5f k1 %2.5f k2 %2.5f\n', i, x(i), y(i), k1, k2);
    end
    plot(x,y,'g');
end