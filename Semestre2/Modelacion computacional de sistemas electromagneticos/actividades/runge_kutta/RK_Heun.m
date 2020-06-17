% Abraham Cepeda Oseguera
% A00827666
% Actividad Runge-kutta 2do. Orden
% Funcion Runge-kutta -- Heun
function RK_Heun(h,n,x,y,y0,fxy)
    for i = 1:n
       y(i) = y0;
       k1 = fxy(x(i), y(i));
       k2 = fxy(x(i)+h, y(i)+k1*h);
       y0 = y(i) + h*((0.5*k1)+(0.5*k2));
       %fprintf('i %d xi %2.5f yi %2.5f k1 %2.5f k2 %2.5f\n', i, x(i), y(i), k1, k2);
    end
    plot(x,y,'b');
end