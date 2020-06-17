% Matriz inversa
% Abraham Cepeda Oseguera
% A00827666

main()

function main()
    fprintf('<--------Welcome to the Inverse Matrix method-------->\n');
    answer = input('Enter how many systems of equations do you want to solve: ');
    for i = 1:answer
        fprintf('Lets begin with the %i systems of equations\n\n', i);
        n = input('Enter the number of variables: ');
        [A, A2] = create_matrix(n); % Initial matrix
        if det(A) ~= 0
            A = get_inverse_matrix(A);
            A = A * A2;
            print_results(A, n);
        else
            fprintf('Sistem of equations is not compatible\n');
        end
    end
    fprintf('The program has finished with ease!\n')
end

% Function to print the final matrix
function print_results(matrix, n)
    for i = 1:n
       fprintf('\n\n ------->  Variable %i == %.4f\n\n', i, matrix(i,1));
    end
end

% Function to get inverse matrix
function new_matrix = get_inverse_matrix(matrix)
    new_matrix = inv(matrix);
end

% Function create matrix -- The user enters the values
function [new_matrix, new_matrix2]  = create_matrix(n)
    matrix = zeros(n); % Initial matrix (amplified)
    matrix2 = zeros(n,1); % Initial matrix
    for j = 1:n
        for k = 1:n + 1
            if k == (n + 1)
                matrix2(j,1) = double(input('Enter the result: '));
            else
                matrix(j,k) = double(input('Enter the coeficients: '));
            end
        end
    end
    new_matrix = matrix;
    new_matrix2 = matrix2;
end
