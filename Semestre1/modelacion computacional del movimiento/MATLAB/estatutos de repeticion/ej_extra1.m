%Abraham Cepeda Oseguera
numero = input("Introduce un número");
num_curioso = numero * numero;
digitos = 0;
num = numero;
while num > 0
    digitos = digitos + 1;
    num = floor(num/10);
end
num_curioso = mod(num_curioso, 10^digitos);
if numero == num_curioso
    fprintf('El número %i es curioso', numero)
else
    fprintf('El número %i no es curioso', numero)
end

