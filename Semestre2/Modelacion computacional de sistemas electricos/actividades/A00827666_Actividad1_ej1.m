% Actividad 1 - Ejercicio 1
% Abraham Cepeda Oseguera
% A00827666
clear, close all;
t = [-1000:1:1000]; 
x = @(t) t.^2 - 2*t;
y = @(t) t + 1;
figure
comet3(x(t),y(t),t);
title('</------Gráfica 1------->')
xlabel('x-value');
ylabel('y-value');
zlabel('t-value');
grid on