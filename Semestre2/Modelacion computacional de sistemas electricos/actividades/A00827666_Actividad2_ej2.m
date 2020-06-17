% Actividad 2 - Ejercicio 2
% Abraham Cepeda Oseguera
% A00827666
clear; clc; close all;
[X,Y] = meshgrid(-3:0.2:3,-3:0.2:9);
z = @(x,y) (16*x.^4) + (15*x.^2) - x + 6 - 2.*y.*x.^2 + (15*y.^2) - y;

box on
tiledlayout(2,2)
nexttile
mesh(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Mesh--->')
colormap cool
pause
nexttile
surf(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Surf--->')
colormap winter
pause
nexttile
surfc(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Surfc--->')
colormap parula
pause
nexttile
contour3(X,Y,z(X,Y))
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')
title('<---Contour3--->')
colormap summer