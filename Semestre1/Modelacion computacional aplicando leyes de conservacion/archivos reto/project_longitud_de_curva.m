clear
clc
syms a0 a1 a2 a3 x
%----------------------------------------------------------------

%%Obtener funcion

x1=100;     %Punto inicial
y1=500;

x2=2800;    %Punto Final
y2=200;     

eq1= a3*x1^3+a2*x1^2+a1*x1+a0==y1;
eq2= a3*x2^3+a2*x2^2+a1*x2+a0==y2;

%Editables
x3=775;     %Punto 1
y3=-3000;

x4=2125;    %Punto 2
y4=1000;

eq3= a3*x3^3+a2*x3^2+a1*x3+a0==y3;
eq4= a3*x4^3+a2*x4^2+a1*x4+a0==y4;

sol=solve([eq1,eq2,eq3,eq4],[a0,a1,a2,a3]);%%Solucion lineal de la ecuacion

v1=double(sol.a0); %Se asignan los valores de cada coeficiente
v2=double(sol.a1);
v3=double(sol.a2);
v4=double(sol.a3);


%----------------------------------------------------------------

%%Longitud de curvatura

fx=v4*x^3+v3*x^2+v2*x+v1;  %Funcion general 
fxd=diff(fx);              %Derivada de la funcion
fxl=sqrt(1+(fxd^2)); 
pt1 = 751;
pt2 = 838;
lg=int(fxl,x,[pt1,pt2]);
fprintf("Longitud: %.4f", lg)b