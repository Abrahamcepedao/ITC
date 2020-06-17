% Abraham Cepeda Oseguera
% A00827666
% Actividad Runge-kutta 2do. Orden
% Ejercicio A)
clear;
close all;
clc;

% datos iniciales
t0 = 0;
tf = 3.5;
h = 0.1;
x0 = 10;

% Hacer calculos
n = (tf/h) + 1;
t = t0:h:tf;
x = zeros(1,length(t));
ftx = @(t,x) t/sqrt(1+t^2);

fprintf("<-----Heun----->\n");
RK_Heun(h,n,t,x,x0,ftx);
hold on
fprintf("<-----Punto Medio----->\n");
hold on
RK_PuntoMedio(h,n,t,x,x0,ftx);
fprintf("<-----Ralston----->\n");
hold on
RK_Ralston(h,n,t,x,x0,ftx);