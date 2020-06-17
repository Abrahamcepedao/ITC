%Ana Sofía fernandes
%Sabina Avila
%Alexa Gonzalez
num = input("Teclea un número: ");
count = 2;
check = 0;
if num > 2
    while count < num
        if mod(num,count) == 0
            check = 1;
        end
        count = count + 1;
    end
    if check == 1
        fprintf("El numero %i no es un número primo", num)
    else
        fprintf("El numero %i es un número primo", num)
    end
elseif num == 2
    fprintf("El numero %i es un número primo", num)
else
    fprintf("El numero %i no es un número primo", num)
end