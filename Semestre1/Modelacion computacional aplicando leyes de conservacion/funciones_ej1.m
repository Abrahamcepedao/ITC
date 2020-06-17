% Abraham Cepeda Oseguera
% A00827666
% Actividad funciones ejercicio 1

%main
x = input("Enter de x value: ");
n = input("Enter de n value: ");
taylor(x, n)

% factorial
% Calculates and returns the factor of a given number
% Input: Number to factor
% Output: Factor
function [factor] = factorial(num)
    factor = 1;
    for x = 1:num
        factor = factor * x;
    end
end

% taylor
% Mkaes the approach of e^x
% Input: x and the n terms
% Output: Nothing (prints)
function taylor(x,n)
    acum = 1;
    for i = 1:n
        acum = acum + (x ^ i) / factorial(i);
    end
    fprintf("The approach of e ^ x: %.2f", acum)
end