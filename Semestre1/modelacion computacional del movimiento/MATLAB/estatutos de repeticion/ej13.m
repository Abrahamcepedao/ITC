%Ana Sofía fernandes
%Sabina Avila
%Alexa Gonzalez
costo_totales = 0;
for i = 1:13
    costo_producto = input("Ingresa el costo del producto: ");
    costo_totales = costo_totales + costo_producto;
end
costo_final = costo_totales * 0.85;
fprintf("Total a pagar: %.2f", costo_final)