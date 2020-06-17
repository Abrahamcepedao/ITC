% Abraham Cepeda Oseguera
% A00827666
% Actividad Runge-kutta 2do. Orden
% Ejercicio B)
clear;
close all;
clc;

% datos iniciales
x0 = 0;
xf = 3;
h = 0.1;
y0 = 1;

% Hacer calculos
n = (xf/h) + 1;
x = x0:h:xf;
y = zeros(1,length(x));
fxy = @(x,y) sin(x);

fprintf("<-----Heun----->\n");
RK_Heun(h,n,x,y,y0,fxy);
hold on
fprintf("<-----Punto Medio----->\n");
hold on
RK_PuntoMedio(h,n,x,y,y0,fxy);
fprintf("<-----Ralston----->\n");
hold on
RK_Ralston(h,n,x,y,y0,fxy);