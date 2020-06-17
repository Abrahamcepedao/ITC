%Ana Sofía fernandes
%Sabina Avila
%Alexa Gonzalez
suma = 0;
for i = 1:999
    if mod(i,3) == 0 || mod(i,5) == 0
        suma = suma + i;
    end
end
fprintf("La suma es = %.2f", suma)
    