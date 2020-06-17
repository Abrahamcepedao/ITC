% Actividad3 - Ejercicio 2
% Abraham Cepeda Oseguera
% A00827666
clear; close all;
x = [-10:0.1:10];
fx1 = @(x) (x.^2).*sin(x);
fx2 = @(x) x - cos(x);
figure(1)
plot(x,fx(x));
grid on
disp('Raíz en el intervalo 6 a 7 ')
[raizX, raizY, Iter] = MetodoBiseccion(fx,6,7,0.001);
disp(' ')
disp(['El valor de X es = ' num2str(raizX)])
disp(['El valor de f(x) es = ' num2str(raizY)])
disp(['El valor de las iteraciones es = ' num2str(Iter)]);
disp(' ')
disp('Raíz en el intervalo 6 a 7 ')
[raizX, raizY, Iter] = MetodoBiseccion(fx,6,7,0.001);
disp(' ')
disp(['El valor de X es = ' num2str(raizX)])
disp(['El valor de f(x) es = ' num2str(raizY)])
disp(['El valor de las iteraciones es = ' num2str(Iter)]);
disp(' ')
