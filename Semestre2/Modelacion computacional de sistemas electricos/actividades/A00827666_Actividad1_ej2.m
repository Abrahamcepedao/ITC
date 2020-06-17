% Actividad 1 - Ejercicio 2
% Abraham Cepeda Oseguera
% A00827666
clear, close all;
[tx, ty] = meshgrid(-3:0.5:3,-3:0.5:3);
f1 = @(t) t.^3 - 4*t;
f2 = @(t) t.^2 - 4 + f1(t);
figure
quiver(tx, ty, f1(tx), f2(ty), 'linewidth', 1, 'color', [0,1,0.75]);
axis equal
title('</------Gráfica 2------->')
xlabel('x-value');
ylabel('y-value');
zlabel('t-value');
grid on