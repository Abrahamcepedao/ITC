%Abraham Cepeda Oseguera
num = input("Teclea un número: ");
mayor = -9999999999999999;
for i = 1:num
    number = input("Teclea cualquier número: ");
    if number > mayor
        mayor = number;
    end
end
fprintf("Número menor = %i", mayor)