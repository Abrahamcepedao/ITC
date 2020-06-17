%Abraham Cepeda Oseguera
for i = 1:15
    num = input("Telcea un número negativo: ");
    while num >= 0
        num = input("Telcea un número negativo porfavor: ");
    end
    num = num * -1;
    fprintf("%i \n", num)
end