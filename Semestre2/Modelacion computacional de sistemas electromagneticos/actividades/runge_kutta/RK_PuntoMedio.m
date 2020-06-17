% Abraham Cepeda Oseguera
% A00827666
% Actividad Runge-kutta 2do. Orden
% Funcion Runge-kutta -- Punto Medio
function RK_PuntoMedio(h,n,x,y,y0,fxy)
    for i = 1:n
       y(i) = y0;
       k1 = fxy(x(i), y(i));
       k2 = fxy(x(i)+0.5*h, y(i)+0.5*k1*h);
       y0 = y(i) + h*k2;
       fprintf('i %d xi %2.5f yi %2.5f k1 %2.5f k2 %2.5f\n', i, x(i), y(i), k1, k2);
    end
    plot(x,y,'r');
end