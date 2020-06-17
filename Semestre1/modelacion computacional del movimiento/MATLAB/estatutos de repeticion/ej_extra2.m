binario = input("introduce número binario");
binario2 = binario;
digitos = 0;
while binario > 0
    digitos = digitos + 1;
    binario = floor(binario/10);
end
suma = 0;
for i = digitos:-1:0
    if floor(binario2/10^(i-1)) == 1
        suma = suma + (2^(i-1));
        binario2 = binario2 - (10^(i-1));
    end
end
fprintf("Número = %i", suma)        