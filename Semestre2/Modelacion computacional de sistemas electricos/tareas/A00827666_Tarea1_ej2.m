% Tarea 1 - Ejercicio 2
% Abraham Cepeda Oseguera
% A00827666
clear, close all;
t = [1:0.1:300]; 
x = @(t) t.^2 + 2*t;
y = @(t) t.^5 + t.^3 + t.^2 + t;
z = @(t) t;
figure
comet3(x(t),y(t),z(t));
title('</------Ejercicio 2------->')
xlabel('x-value');
ylabel('y-value');
zlabel('t-value');
grid on