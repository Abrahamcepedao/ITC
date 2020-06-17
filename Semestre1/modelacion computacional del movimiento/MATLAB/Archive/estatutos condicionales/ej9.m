%ejercicio 9
%Ana Sofía Fernandes Moheno
%A01637799
answer = input("¿Colon descubrió América? (Si/No)", "s");
if answer == "Si"
    answer = input("¿La independencia de México fue en el año 1810?  (Si/No)", "s");
    if answer == "Si"
        answer = input("¿The Doors fue un grupo de rock Americano?  (Si/No)", "s");
        if answer == "Si"
            disp("¡¡¡Ganaste!!!")
        else
            disp("Perdiste :(")
        end
    else
        disp("Perdiste :(")
    end
else
    disp("Perdiste :(")
end
        