% Abraham Cepeda Oseguera
% A00827666
% Regresion lineal por mínimos cuadrados

% <--------------Ejercicio A)------------->
figure(1)
y = [10 10.9 11.7 12.6 13.8 14.9];
x = 2012:1:2017;
fprintf("<-------Ejercicio A)------->\n");
[a,b] = RegresionLineal(x,y);
fprintf("-> Población en el 2004 = %.2f\n", (2004*a+b));

prediction = 2004*a+b;
number = 0;
num = 2004;
while number < prediction*2
   num = num + 0.1;
   number = (num)*a+b;
end
fprintf("-> El doble de la poblacion del 2004 occurirá en el %.1f\n",(num));

pause
% <--------------Ejercicio B)------------->
figure(2)
y2 = [35 35.6 36.25 36.9 37.5 38.1 38.8 39.4 40];
x2 = 10:10:90;
fprintf("<-------Ejercicio B)------->\n");
[a2,b2] = RegresionLineal(x2,y2);
fprintf("-> Solubilidad cuando T 25C = %.2f\n", (25*a2+b2));

