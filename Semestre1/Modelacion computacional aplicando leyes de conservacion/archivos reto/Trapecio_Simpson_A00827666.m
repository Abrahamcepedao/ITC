% Trapezium and Sympson
% Abraham Cepeda Oseguera
% A00827666
syms x
answer = input("Enter 1 for trapezium and 2 for sympson: ");
while answer ~= 0
    if answer == 1
        pt1 = input("Enter point 1: ");
        pt2 = input("Enter point 2: ");
        n = input("Enter n: ");
        ecu = input("Ingresa funcion en terminos de x: >");
        resultado = trapezium(ecu, pt1, pt2, n);
        fprintf("The result with trapezium is: %f\n", resultado);
    elseif answer == 2
        pt1 = input("Enter point 1: ");
        pt2 = input("Enter point 2: ");
        n = input("Enter n: ");
        while mod(n, 2) ~= 0
            n = input("Enter n (must be an even number): ");
        end
        ecu = input("Ingresa funcion en terminos de x: >");
        resultado = sympson(ecu, pt1, pt2, n);
        fprintf("The result with sympson is: %f\n", resultado);
    end
    answer = input("Enter 1 for trapezium, 2 for sympson, 0 to exit: ");
end
fprintf("The program has finished")


function [res] = trapezium(ecuacion, inf, sup, n)
    syms x
    deltax = (sup - inf) / n;
    ecudif = diff(ecuacion);
    ecu = sqrt(1 + (ecudif)^2);
    f0 = subs(ecu, {x}, inf);
    res = 0;
    for i = (inf + deltax):deltax:(sup - deltax)
        res = res + (subs(ecu, {x}, i)) * 2;
    end    
    fn = subs(ecu, {x}, sup);
    res = (f0 + res + fn) * (deltax / 2);
end

function [res] = sympson(ecuacion, inf, sup, n)
    syms x
    deltax = (sup - inf) / n;
    f0 = subs(ecuacion, {x}, inf);
    fn = subs(ecuacion, {x}, sup);
    fimpar = 0;
    fpar = 0;
    deltaxx = deltax + inf;
    for i = 1:1:n-2
        if mod(i, 2) == 0
            fpar = fpar + subs(ecuacion, {x}, deltaxx);
        else
            fimpar = fimpar + subs(ecuacion, {x}, deltaxx);
        end
        deltaxx = deltaxx + deltax; 
    end    
    fpar = fpar * 2;
    fimpar = fimpar * 4;
    res = (f0 + fimpar + fpar + fn) * (deltax / 3);
end
