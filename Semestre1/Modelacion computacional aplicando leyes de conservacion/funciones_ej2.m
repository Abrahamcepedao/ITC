% Abraham Cepeda Oseguera
% A00827666
% Actividad funciones ejercicio 2

%main
n = input("Enter the number of the sequence: ");
fibo_num = fibonaccii(n);
fprintf("The value of the %i term of the fibonacci sequence is: %i", n, fibo_num);

% fibonacci
% Gives the nth term of the fibonnaci secuence
% Input: the nth term
% Output: the value of the nth term
function [fibo_num] = fibonaccii(n)
    num1 = 0;
    num2 = 1;
    if n < 2
        if n == 0
            fibo_num = num1;
        elseif n == 1
            fibo_num = num2;
        else
            disp("Enter a valid number")
        end
    else
        for i = 2:n
            sum = num1 + num2;
            num1 = num2;
            num2 = sum;
        end
        fibo_num = sum;
    end
end

