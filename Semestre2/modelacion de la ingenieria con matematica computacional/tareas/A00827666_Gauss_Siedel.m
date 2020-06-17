% Metodo de Gauss Siedel
% Abraham Cepeda Oseguera
% A00827666

main();

function main()
    fprintf('<--------Welcome to the Jacobi Method-------->\n');
    answer = input('Enter how many systems of equations do you want to solve: ');
    for i = 1:answer
        fprintf('Lets begin with the %i systems of equations\n\n', i);
        n = input('Enter the number of variables: ');
        A = create_matrix(n); % Initial matrix
        val = check_zeros(A, n);
        if val ~= 0
            val2 = dominant(A,n);
            if val2 == 1
                A = solve(A, n); % Solve for each variable
                B = initial_values(A, n); % get initial values (variables equal zero)
                B = get_new_values(B, A ,n); % get new values
                Bi = B; % set initial set of previous values
                B = calculate_it(A, Bi, B, n, 0);
                print_results(B, n);
            end
        else
           fprintf("Invalid system of equations\n\n");
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

% Function calculate iteration
function new_matrix = calculate_it(A, Bi, Bf, n, count)
    Bf = get_new_values(Bf, A, n); % get new values
    val = check_validity(Bi, Bf, n); % check if answer is valid
    Bi = Bf; % set past results for lparisionater com
    count = count + 1;
    fprintf('Iterations == %i\n', count)
    if val == 0
        new_matrix = calculate_it(A, Bi, Bf, n, count);
    else
        new_matrix = Bf;
    end
end

% Function chech for validity
function val = check_validity(Bi, Bf,n)
    tol = 1e-4;
    val = 0;
    for i = 1:n
        if abs(Bi(i,1) - Bf(i,1)) < tol
            val = val + 1;
        end
    end
    if val == n
        val = 1;
    else
        val = 0;
    end
end

% Function get new values
function new_matrix = get_new_values(variables, matrix, n)
    new_matrix = zeros(n,1);
    for i = 1:n
        number = 0;
        for j = 1:n
            if i < j
                number = number + matrix(i,j-1) * variables(j,1);
            elseif i > j
                number = number + matrix(i,j) * variables(j,1);
            end
        end
        new_matrix(i,1) = number + matrix(i,n);
        variables(i,1) = new_matrix(i,1); % update the value constanly (only difference with jacobi)
    end
end

% Function get initial values
function new_matrix = initial_values(matrix, n)
    new_matrix = zeros(n,1);
    for i = 1:n
        new_matrix(i,1) = matrix(i, n);
    end
end

% Funciton to solve for each variable
function new_matrix = solve(matrix, n)
    new_matrix = zeros(n);
    for i = 1:n
        number = matrix(i,i);
        for j = 1:n+1
            if i < j
                if j ~= n + 1
                    new_matrix(i,j-1) = -matrix(i,j)/number;
                else
                    new_matrix(i,j-1) = matrix(i,j)/number;
                end
            elseif i > j
                if j ~= n + 1
                    new_matrix(i,j) = -matrix(i,j)/number;
                else
                    new_matrix(i,j) = matrix(i,j)/number;
                end
            end
        end
    end
end

% Function check for diagonally dominant
function val = dominant(matrix,n)
    val = 1;
    for i = 1:n
       row_sum = sum(abs(matrix(i,:))) - abs(matrix(i,i)) - abs(matrix(i,n+1));
       if matrix(i,i) < row_sum
           val = 0;
           fprintf('The matrix most be diagonally dominant!\n');
       end
    end
end
    
% Function check for zeros in identity
function val = check_zeros(matrix, n)
    val = 1;
    for i = 1:n
        if matrix(i,i) == 0
            val = 0;
        end
    end
end

% Function create matrix -- The user enters the values
function new_matrix  = create_matrix(n)
    new_matrix = zeros(n, n + 1); % Initial matrix (amplified)
    for j = 1:n
        for k = 1:n + 1
            if k == (n + 1)
                new_matrix(j,k) = double(input('Enter the result: '));
            else
                new_matrix(j,k) = double(input('Enter the coeficients: '));
            end
        end
    end
end