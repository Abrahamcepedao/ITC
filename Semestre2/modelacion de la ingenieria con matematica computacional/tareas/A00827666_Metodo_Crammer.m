% Metodo de crammer
% Abraham Cepeda Oseguera
% A00827666

main();
function main()
    answer = 1;
    while answer ~= 0
        syms x y z
        answer = menu();
        if answer == 1
            ecu1 = input('Enter the first ecuation: ')
            ecu2 = input('Enter the second ecuation: ')
            ecu3 = input('Enter the third ecuation: ')
            [x, y, z] = crammer(ecu1, ecu2, ecu3)
            fprintf("x = %.2f\n", x);
            fprintf("y = %.2f\n", y);
            fprintf("z = %.2f\n", z);
            clear
            answer = 1;
            main();
        end
    end
end

function answer = menu()
    fprintf('1. To enter a systems of equations\n');
    fprintf('0. To exit\n');
    answer = input('Enter your answer: ');
end

% crammer function
function [xv, yv, zv] = crammer(ecu1,ecu2,ecu3)
    [A1, B1] = equationsToMatrix(ecu1)
    [A2, B2] = equationsToMatrix(ecu2)
    [A3, B3] = equationsToMatrix(ecu3)
    Ai = zeros(3);
    for i = 1:3
       Ai(1,i) = A1(1,i)
       Ai(2,i) = A2(1,i)
       Ai(3,i) = A2(1,i)
    end
    Ai = [A1;A2;A3]; % inicial matrix
    B = [B1;B2;B3]; % Results matrix
    Ax = Ai;
    Ay = Ai;
    Az = Ai;
    for i = 1:3
        Ax(i,1) = B(i);
        Ay(i,2) = B(i);
        Az(i,3) = B(i);
    end
    detA = det(Ai);
    detx = det(Ax);
    dety = det(Ay);
    detz = det(Az);
    xv = detx / detA;
    yv = dety / detA;
    zv = detz / detA;
end