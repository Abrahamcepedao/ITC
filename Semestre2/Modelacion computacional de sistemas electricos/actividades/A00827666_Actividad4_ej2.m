% Actividad 4 - Ejercicio 2
% Abraham Cepeda Oseguera
% A00827666
clear; close all;
syms x

fx0 = x^2 * sin(x); % [6 6.5] | x1 = 6
fx1 = x - cos(x); % [0 1] | xi = 1
fx2 = x*log10(x); % [0.5 2] | xi = 1.5
fx3 = exp(0.3*x) - x^2; % [-1 -0.5][1 1.5] | xi = 1
fx4 = 2*cos(x) - sqrt(x)/2; % [-8 -7][-6 -5][-2 -1][0 2] | xi = 1
fx = [fx0,fx1,fx2,fx3,fx4]; % vector con funciones

inter = [[6 6.5];[0 1];[0.5 2];[1 1.5];[0 2]]; % Intervalos para metod biseccion
xis = [6 1 1.5 1 1]; % xis para metodo Newton
err = 0.0001;
maxRep = 20;

for i = 1:length(fx)
    [raizX, raizY, iter] = MetodoNewton(fx(i),diff(fx(i)),xis(i),err, maxRep);
    fprintf('Resultados Funcion %d - Newton Rapson\n', i);
    fprintf('El valor de x es = %f\n', raizX);
    fprintf('El valor de y es = %f\n', raizY);
    fprintf('El valor de iteraciones es = %d\n\n', iter);
    
    [raizX, raizY, iter] = MetodoBiseccion(fx(i),inter(i,1),inter(i,2),err, maxRep);
    fprintf('Resultados Funcion %d - Metodo Biseccion\n', i);
    fprintf('El valor de x es = %f\n', raizX);
    fprintf('El valor de y es = %f\n', raizY);
    fprintf('El valor de iteraciones es = %d\n\n', iter);
end

