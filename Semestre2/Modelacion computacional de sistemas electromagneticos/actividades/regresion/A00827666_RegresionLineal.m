% Abraham Cepeda Oseguera
% A00827666
% Regresion lineal por mínimos cuadrados
n = 11;
y = [82 88 56 64 77 92 23 41 80 59 47];
x = [6 10 2 4 6 7 0 1 8 5 3];

sumX = sum(x);
sumY = sum(y);
sumX2 = sum(x.^2);
sumXY = sum(x.*y);
sumY2 = sum(y.^2);
a = (n*sumXY-sumX*sumY)/(n*sumX2-sumX^2);
b = (sumY-a*sumX)/n;

r = (n*sumXY - sumX*sumY)/(sqrt(n*sumX2-sumX^2)*sqrt(n*sumY2-sumY.^2));

scatter(x,y);
x = min(x):1:max(x);
hold on
plot(x,x.*a + b);

fprintf("-> a = %.2f\n", a);
fprintf("-> b = %.2f\n", b);
fprintf("-> r = %.4f\n", r);
fprintf("-> Ecuacion: y = %.2f + %.2fx\n",b,a);