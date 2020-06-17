%Ana Sofía fernandes
%Sabina Avila
%Alexa Gonzalez
num = input("Teclee un numero");
for i = 2:num
    count = 2;
    while count < (i + 1)
        if mod(i,count) == 0
            fprintf("%i\n",i)
        count = count + 1;
        end
    end
end
            