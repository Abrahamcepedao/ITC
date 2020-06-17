% Abraham Cepeda Oseguera
% A00827666
% Actividad Runge-kutta 2do. Orden
% Ejercicio C)
clear;
close all;
clc;

% datos iniciales
t0 = 0;
tf = 2.8;
h = 0.1;
y0 = 15;

% Hacer calculos
n = (tf/h) + 2;
t = t0:h:tf;
y = zeros(1,length(t));
fty = @(t,y) 20 + 7*sin(2*t);

fprintf("<-----Heun----->\n");
RK_Heun(h,n,t,y,y0,fty);
hold on
fprintf("<-----Punto Medio----->\n");
hold on
RK_PuntoMedio(h,n,t,y,y0,fty);
fprintf("<-----Ralston----->\n");
hold on
RK_Ralston(h,n,t,y,y0,fty);