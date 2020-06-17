% Eliminacion de Gauss Jordan
% Abraham Cepeda Oseguera
% A00827666

main();

function main()
    fprintf('<--------Welcome to the Gauss Jordan Elimination method-------->\n');
    answer = input('Enter how many systems of equations do you want to solve: ');
    for i = 1:answer
        fprintf('Lets begin with the %i systems of equations\n\n', i);
        n = input('Enter the number of variables: ');
        [A, A2] = create_matrix(n); % Initial matrix
        val = 0;
        A = identity_zeros(A, n, val); % Reordered matrix
        if rank(A) == rank(A2)
            for j = 1:n
                A = value_to_one_i(A, n, j) % make identity number equal to 1
                A = value_to_one_lower(A, n, j) % make numbers of column equal to 1 (lower)
                A = value_to_zero(A,n,j) % make numbers of column equal to 0
                A = value_to_one_upper(A,n,j) % make numbers of column equal to 1 (upper)
            end
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

% Function make values equal to zero (any value except identity)
function new_matrix = value_to_zero(matrix, n, val)
    for i = val+1:n
        if matrix(i,val) > 0
            for j = val:n + 1
                matrix(i,j) = matrix(i,j) - (matrix(val,j));
            end
        elseif matrix(i,val) < 0
            for j = val:n + 1
                matrix(i,j) = matrix(i,j) + (matrix(val,j));
            end
        end
    end
    new_matrix = matrix;
end

% Function change (xi,yi) to 1 (for upper values)
function new_matrix = value_to_one_upper(matrix, n, val)
    for j = 1:val - 1
        number = matrix(j,val);
        if number ~= 0
            for i = val:n + 1
                matrix(j,i) = matrix(j,i) - (matrix(val,i)*number);
            end
        end
    end
    new_matrix = matrix;
end

% Function change (xi,yi) to 1 (for lower values)
function new_matrix = value_to_one_lower(matrix, n, val)
    for j = val+1:n
        number = matrix(j,val);
        if number ~= 0
            for i = val:n + 1
                matrix(j,i) = matrix(j,i) / number;
            end
        end
    end
    new_matrix = matrix;
end

% Function change (n,n) to 1 (for identity values)
function new_matrix = value_to_one_i(matrix, n, val)
    if matrix(val,val) ~= 1
        number = double(matrix(val,val));
        for i = val:n+1 
            matrix(val,i) = double(matrix(val,i) / number);
        end
    end
    new_matrix = matrix;
end

% Function check zeros in identity
function new_matrix = identity_zeros(matrix, n, val)
    for j = 1:n
        if matrix(j,j) == 0
            matrix_temp = matrix(j,:);
            val = 1;
            if j == 1
                matrix_temp_2 = matrix(j+1,:);
                matrix((j+1),:) = matrix_temp;
                matrix(j,:) = matrix_temp_2;
            else
                matrix_temp_2 = matrix(j-1,:);
                matrix((j-1),:) = matrix_temp;
                matrix(j,:) = matrix_temp_2;
            end
        else
            val = 0;
        end
    end
    if val == 1
        matrix = identity_zeros(matrix, n, val);
    end
    new_matrix = matrix;
end

% Function create matrix -- The user enters the values
function [new_matrix, new_matrix2]  = create_matrix(n)
    matrix = zeros(n, n + 1); % Initial matrix (amplified)
    matrix2 = zeros(n); % Initial matrix
    for j = 1:n
        for k = 1:n + 1
            if k == (n + 1)
                matrix(j,k) = double(input('Enter the result: '));
            else
                matrix(j,k) = double(input('Enter the coeficients: '));
                matrix2(j,k) = matrix(j,k);
            end
        end
    end
    new_matrix = matrix;
    new_matrix2 = matrix2;
end