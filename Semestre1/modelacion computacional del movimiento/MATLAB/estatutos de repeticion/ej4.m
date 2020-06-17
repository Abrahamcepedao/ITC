%Abraham Cepeda Oseguera
num = input("Teclea un número: ");
menor = 9999999999999999;
for i = 1:num
    number = input("Teclea cualquier número: ");
    if number < menor
        menor = number;
    end
end
fprintf("Número menor = %i", menor)
    