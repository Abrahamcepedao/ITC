%Abraham Cepeda Oseguera
%A00827666
%Actividad matrice
%Ejercicio 2
ren = input('Cantidad de renglones');
col = input('Cantidad de columnas');
if ren == col
    matrix = zeros(ren);
    for ex = 1:1:ren
        for ey = 1:1:col
            matrix(ex,ey) = input('Telcea una cantidad'); 
        end
    end
    vector = zeros(ren,1);
    for i = 1:1:ren
        vector(i) = matrix(i, i);
    end
    disp(matrix)
    disp(vector)
else
    disp('La matriz no es cuadradada')
end