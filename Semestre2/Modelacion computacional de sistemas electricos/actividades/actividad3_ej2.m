% <---Grupo 1 | Equipo 4--->
% <----Integrantes del equipo---->
% Abraham Cepeda Oseguera          -- A00827666
% Juan Pablo David Lerma           -- A01283879
% José Juan López Valenzuela       -- A01283642
% Jesús Gerardo Rodríguez Tristán  -- A01283717
% Carlos Sebastián Salinas Morales -- A01283585
clear; close all;
x = [-10:0.1:10];
f = cell(5,1);
f{1} = @(x) (x.^2).*sin(x); % [6 7]
f{2} = @(x) x - cos(x); % [0 2]
f{3} = @(x) x.*log(x); % [0 2]
f{4} = @(x) exp(0.3.*x) - x.^2; % [0 2]
f{5} = @(x) 2*cos(x) - sqrt(x)/2; % [1 3]
intervalos = [[6, 7]; [0, 2]; [0, 2]; [0, 2]; [1, 3]];
for i = 1:5
    figure(i)
    plot(x,f{i}(x));
    fprintf('<-----Funcion %i------->\n', i);
    fprintf('Raíz en el intervalo %i a %i\n', intervalos(i,1), intervalos(i,2));
    [raizX, raizY, Iter] = MetodoBiseccion(f{i},intervalos(i,1),intervalos(i,2),0.001);
    fprintf('<--Resultados-->\n')
    fprintf('El valor de x es = %.5f\n', raizX);
    fprintf('El valor de f(x) es = %.5f\n', raizY);
    fprintf('El valor de las iteraciones es = %.5f\n', Iter)
    pause
end
