%Ana Sofía fernandes
%Sabina Avila
%Alexa Gonzalez
edad = input("Teclee su edad: "); 
costo = 100;
perdida5 = 0;
perdida4 = 0;
perdida3 = 0;
perdida2 = 0;
perdida1 = 0;
while edad ~= 0
    if edad >= 66
        disp("Descuento = 35%")
        perdida5 = perdida5 + (costo * .35);
    elseif edad >= 46
        disp("Descuento = 25%")
        perdida4 = perdida4 + (costo * .25);
    elseif edad >= 20
        disp("Descuento = 10%")
        perdida3 = perdida3 + (costo * .10);
    elseif edad >= 15
        disp("Descuento = 25%")
        perdida2 = perdida2 + (costo * .25);
    elseif edad >= 5
        disp("Descuento = 35%")
        perdida1 = perdida1 + (costo * .35);
    else
        disp("No puede entrar al teatro")
    end
    edad = input("Teclee su edad: "); 
end
fprintf("Categoría 1 = %.2f, Categoría 2 = %.2f, Categoría 3 = %.2f, Categoría 4 = %.2f, Categoría 5 = %.2f,", perdida1, perdida2, perdida3, perdida4, perdida5)
