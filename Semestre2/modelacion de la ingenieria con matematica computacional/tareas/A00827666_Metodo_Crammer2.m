% Metodo de crammer
% Abraham Cepeda Oseguera
% A00827666

main();

function main()
    fprintf('<--------Welcome to the crammer method program!-------->\n');
    n = input('Enter how many systems of equations do you want to solve: ');
    for i = 1:n
        fprintf('Lets begin with the %i systems of equations\n\n', i);
        answer = input('Enter the number of variables: ');
        A = zeros(answer); % Coefficients matrix
        B = zeros(answer,1); % Results matrix
        for j = 1:answer
            for k = 1:answer
                A(j,k) = input('Enter the coefficient: ');
            end
            B(j,1) = input('Enter the result of the equation: ');
        end
        if det(A) ~= 0
            det_a = det(A)
            matrix_results = zeros(answer,1);
            for x = 1:answer
                matrix_temporal = A
                for j = 1:answer
                   matrix_temporal(j,x) = B(j,1)
                end
                matrix_results(x,1) = det(matrix_temporal) / det_a
            end
        else
            fprintf('Invalid system of equations\n');
        end
    end
    fprintf('The program has finished with ease!\n')
end


