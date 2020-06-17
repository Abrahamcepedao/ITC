clc
close all

%variables usadas
syms x y muk z % x = aC, y = aA, z = T

%ecuaciones
equ1 = x + y == 0;
equ2 = 1154 * muk - z + 6440 + 400 * x == 0;
equ3 = -z + 8050 - 250 * y == 0;

%solucion de ecuaciones
[x,y,z] = solve(equ1, equ2, equ3);

%Cambiar a números decimales
x = vpa(x,2);
y = vpa(y,2);
z = vpa(z,2);

%definir muk y acelaracion
muk = 0:0.01:1;
a = (-7.7 * muk) + 11; %acelaración de aC

%Sacar velocidad final
vF = sqrt(40 * a);
plot(muk, vF);

%Plot
xlabel("Muk_K");
ylabel("vF (ft/sec)");


