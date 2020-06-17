% Abraham Cepeda Oseguera
% A00827666
% Actividad 2 - RK 4to. Orden
clear; close all;clc;
figure(1);

%Datos iniciales
xi = 0;
xf = 4;
h = 0.5;
yi = 4;
                           
f = @(x,y) (y + 1)*(x + 1)*cos(x^2 + 2*x);

%function [x, y] = RK_SegundoOrden(f, xi, xf, yi, h, a2)

%Se llama al método RK_SegundoOrden de Heun a2=1/2
a2=1/2;
[x,y]=RK_SegundoOrden(f,xi,xf,yi,h,a2);
plot(x,y,'b-o','DisplayName','Heun');
hold on;
pause;

%Se llama al método RK_SegundoOrden de Punto medio a2=1
a2=1;

[x,y]=RK_SegundoOrden(f,xi,xf,yi,h,a2);
plot(x,y,'g-*','DisplayName','Punto Medio');
hold on;
pause;

%Se llama al método RK_SegundoOrden de Ralston a2=2/3
a2=2/3;
[x,y]=RK_SegundoOrden(f,xi,xf,yi,h,a2);
plot(x,y,'m-+','DisplayName','Ralston');
hold on;
pause;

%Se llama al método RK_CuartoOrden
[x,y]=RK_CuartoOrden(f, xi, xf, yi, h);
plot(x,y,'r-x','DisplayName','RK CuartoOrden');
hold on;
pause;

%Solución analítica
fo= 5*exp(0.5*sin(x.^2 + 2*x)) - 1; 
plot(x,fo,"k",'DisplayName','Sol. Analítica');
hold on;
legend;

