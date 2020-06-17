% Tarea 2 - Ejercicio 1
% Abraham Cepeda Oseguera
% A00827666
clear; clc; close all;
[X,Y] = meshgrid(-10:0.1:10,-10:0.1:10);
z = @(x,y) (sin((sqrt(x.^2+y.^2)))) ./ (sqrt(x.^2+y.^2));

figure(1)
mesh(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Mesh--->')
colormap cool
pause

figure(2)
surf(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Surf--->')
colormap winter
pause

figure(3)
surfc(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Surfc--->')
colormap parula
pause

figure(4)
contour3(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Contour3--->')
colormap summer