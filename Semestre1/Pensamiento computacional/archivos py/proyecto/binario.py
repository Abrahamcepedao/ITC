import math
binario = int(input("introduce número binario"))
binario2 = binario;
digitos = 0;
while binario > 0:
    digitos = digitos + 1;
    binario = binario // 10;
suma = 0;
for i in range(digitos, -1, -1):
    if binario2 // math.pow(10, (i-1)) == 1:
        suma = suma + math.pow(2, i-1);
        binario2 = binario2 - (math.pow(10, (i-1)));
print("Número = ", suma)   