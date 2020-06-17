%Abraham Cepeda Oseguera
%A00827666
%Actividad matrice
%Ejercicio 2
ren = input('Cantidad de renglones');
col = input('Cantidad de columnas');
matrix = zeros(ren, col);
for ex = 1:1:ren
    for ey = 1:1:col
        matrix(ex, ey) = input('Enter a number: ');
    end
end
suma_vector = zeros(ren,1);
for ey = 1:1:col
    suma = 0;
    for ex = 1:1:ren
        suma = suma + matrix(ex, ey);
    suma_vector(ey) = suma;
    end
end
disp(suma_vector)