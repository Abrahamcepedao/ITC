%ejercicio 8
%Ana Sofía Fernandes Moheno
%A01637799
computadoras = input("Ingrese cantidad de computadoras: ");
precio = 11000;
costo = computadoras * precio;
descuento = 0;
if computadoras > 0
    if computadoras >= 10
        descuento = costo * 0.4;
    elseif computadoras >= 5
        descuento = costo * 0.2;
    else
        descuento = costo * 0.1;
    end
    fprintf("El costo total es de %.2f y el descuentp es de %.2f", costo, descuento)
else
    disp("No compro nada")
end
  

