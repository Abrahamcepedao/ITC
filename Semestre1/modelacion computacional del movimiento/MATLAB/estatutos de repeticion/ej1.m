%Abraham Cepeda Oseguera
positivos = 0;
cero = 0;
negativos = 0;
for i = 1:20
    num = input("enter any number: ");
    if num > 0
        positivos = positivos + 1;
    elseif num < 0 
        negativos = negativos + 1;
    else
        cero = cero + 1;
    end
end
fprintf('positivos = %i negativos = %i cero = %i', positivos, negativos, cero)