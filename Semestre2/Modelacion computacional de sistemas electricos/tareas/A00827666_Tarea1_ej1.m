% Tarea 1 - Ejercicio 1
% Abraham Cepeda Oseguera
% A00827666
clear, close all;
t = [1:0.1:200]; 
x = @(t) t.^5 - 4*t;
y = @(t) 2*t + 3;
figure
comet3(x(t),y(t), t);
title('</------Ejercicio 1------->')
xlabel('x-value');
ylabel('y-value');
zlabel('t-value');
grid on