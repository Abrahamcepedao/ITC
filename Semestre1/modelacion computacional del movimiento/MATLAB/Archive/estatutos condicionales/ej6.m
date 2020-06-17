%ejercicio 6
%Ana Sofía Fernandes Moheno
%A01637799
salario_actual = input("Ingresa salario actual: ");
antiguedad = input("Ingresa antigüedad en años: ");
if antiguedad >= 10
    utilidad = salario_actual * .20;
elseif antiguedad >= 5
    utilidad = salario_actual * .15;
elseif antiguedad >= 2
    utilidad = salario_actual * .10;
elseif antiguedad >= 1
    utilidad = salario_actual * .07;
else
    utilidad = salario_actual * .05;
end
fprintf("utilidad = %.2f", utilidad)