% Abraham Cepeda Oseguera
% A00827666
% Actividad funciones ejercicio 3

%main
n = input("Enter the number of lines: ");
triangle(n);

% triangle
% Recieves the number of lines and creates a triangle of *
% Input: the number of lines
% Output: the triangle made out of *
function triangle(n)
    for i = 1:n
        for x = 1:i
            fprintf("*")
        end
        fprintf("\n")
    end
end