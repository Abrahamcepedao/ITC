%Ana Sofía fernandes
%Sabina Avila
%Alexa Gonzalez
ventas_totales = 0;
for i = 1:10
    venta_mes = input("Ingresa la venta del mes");
    ventas_totales = ventas_totales + venta_mes;
end
ganancia = ventas_totales * 0.10;
fprintf("Ganancia del mes: %.2f", ganancia)