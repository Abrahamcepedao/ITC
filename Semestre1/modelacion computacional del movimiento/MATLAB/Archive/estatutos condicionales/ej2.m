%ejercicio 2
%Ana Sofía Fernandes Moheno
%A01637799
num1 = input("Dame un numero ");
num2 = input("Dame un numero ");
num3 = input("Dame un numero ");




if num1 + num2 == num3
    fprintf("%i + %i = %i", num1, num2, num3)
elseif num1 + num3 == num2
    fprintf("%i + %i = %i", num1, num3, num2)
elseif num2 + num3 == num1
    fprintf("%i + %i = %i", num2, num3, num1)
else
    disp("Ninguno")
end