% Actividad 2 - Ejercicio 1
% Abraham Cepeda Oseguera
% A00827666
clear; clc; close all;
a = 1;
b = 1;
[T,U] = meshgrid(0:0.2:2*pi,0:0.2:2*pi);

fx = @(t,u) a.*cos(t).*cos(u);
fy = @(t,u) b.*cos(t).*sin(u);
z = @(t,u) cos(t).^2+u.*0;

surf(fx(T,U),fy(T,U),z(T,U), 'EdgeColor', 'none');
colormap winter
grid on
title('Ejercicio 1')