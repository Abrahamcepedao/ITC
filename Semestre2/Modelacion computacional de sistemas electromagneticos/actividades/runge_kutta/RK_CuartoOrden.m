% Abraham Cepeda Oseguera
% Carlos Sebastian Salinas
% Gerardo Mora Beltran
% Funcion Runge-kutta 4to. Orden
function [x,y] = RK_CuartoOrden(f,xi,xf,yi,h)
    x = [xi:h:xf];
    y = zeros(1,length(x));
    y(1) = yi;
 
    for i = 1:length(x)-1
       k1 = f(x(i), y(i));
       k2 = f(x(i) + 0.5*h, y(i) + 0.5*k1*h);
       k3 = f(x(i) + 0.5*h, y(i) + 0.5*k2*h);
       k4 = f(x(i) + h,y(i) + k3*h);
       y(i+1) = y(i) + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
       %fprintf('i %d xi %2.5f yi %2.5f k1 %2.5f k2 %2.5f\n', i, x(i), y(i), k1, k2);
    end
    plot(x,y,'g');
end