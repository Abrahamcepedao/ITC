% Abraham Cepeda Oseguera
% A00827666
% Regresion Polinomial

T = [273 283 293 303 313 323 333 343 353 363 373]; % X
Cp = [1.00738 1.00129 0.99883 0.99802 0.99804 0.99854 0.99943 1.00067 1.00229 1.00437 1.00697]; % Y
plot(T,Cp, 'linewidth', 1.5);

C = zeros(5);
for i = 1:4
    C(i,1:i+1) = polyfit(T,Cp,i);
end

x = (min(T):0.01:max(T));
y = zeros(4,length(x));
y2 = zeros(4,length(T));

fprintf("Polinomio 1: y = %.10f x + %.10f\n",C(1,1),C(1,2));
fprintf("Polinomio 2: y = %.10f x^2 + %.10f x + %.10f\n",C(2,1),C(2,2), C(2,3));
fprintf("Polinomio 3: y = %.10f x^3 + %.10f x^2 + %.10f x + %.10f\n",C(3,1),C(3,2), C(3,3), C(3,4));
fprintf("Polinomio 4: y = %.10f x^4 + %.10f x^3 + %.10f x^2 + %.10f x + %.10f\n",C(4,1),C(4,2), C(4,3), C(4,4), C(4,5));

for i = 1:4
    y(i,1:length(x)) = polyval(C(i,1:i+1),x);
    hold on;
    plot(x,y(i,1:length(x)), 'linewidth', 1.5);
    y2(i,1:length(T)) = polyval(C(i,1:i+1),T);
    fprintf("MSE %i: %.8f\n",i, mse(Cp-y2));
end
hold on
legend("Data", "Grado1", "Grado2", "Grado3", "Grado4");