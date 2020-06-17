%ejercicio 4
%Ana Sofía Fernandes Moheno
%A01637799
actividad = input("inserte actividad: (dormido/sentado)", "s");
tiempo = input("inserte el tiempo en minutos:");

if actividad == "dormido"
    actividad = 1.08*tiempo;
    fprintf("calorias = %.2f", actividad) 
   
elseif actividad == "sentado"
    actividad=1.66*tiempo;
    fprintf("calorias = %.2f", actividad)

else
    disp("No deberia estar haciendo esta actividad")
end




