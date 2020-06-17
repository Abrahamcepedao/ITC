% Actividad 2: Mínimos cuadrados
% Abraham Cepeda Oseguera
% A00827666

% <-----Datos iniciales------>
n = 19; % valor de n
distancia = [19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]; % datos independientes (eje x)
tiempo = [9.816778106, 10.44211816, 10.97075039, 9.556742561, 10.01883342, 10.81568873, 8.779377461, 10.29809067, 11.79844761, 9.1856426, 10.01883342, 10.2271918, 10.97075039, 10.29809067, 10.51526762, 7.994746714, 10.4294664, 11.08128051, 6.563496463];
% tiempo = [-0.000102721, -0.000105942, -0.000111996, -0.000107143, -0.000102389, -0.000108925, -0.000101965, -9.94948E-05, -0.00011534, -0.000108932, -0.000100381, -0.00010592, -0.000110837, -0.000111221, -0.000108888, -9.59406E-05, -8.27474E-05, -6.88861E-05, -3.15506E-05];
% velocidad = [0.001013514, 0.001045296, 0.001071429, 0.001, 0.001023891, 0.00106383, 0.000958466, 0.001038062, 0.001111111, 0.000980392, 0.001023891, 0.001034483, 0.001071429, 0.001038062, 0.001048951, 0.000914634, 0.000904704, 0.000761421, 0.000414365];
% tiempo = [9.8667, 9.5667, 9.333, 10, 9.7, 9.4, 10.433, 9.633, 9, 10.2, 9.7667, 9.6667, 9.333, 9.6333, 9.5333, 10.933, 11.05, 13.13, 24.13];% datos dependientes (eje y)

% <-----Variables globales------>
sum_xi_2 = 0; % acumulador de cada xi al cuadrado
sum_xi_yi = 0; % acumulador de cada xi * yi
sum_yi = 0; % acumulador de cada yi
sum_xi = 0; % acumlador de cada xi

% <-----Calcular acumuladores------>
for i = 1:n
    sum_xi_2 = sum_xi_2 + (distancia(1,i)^2); % calcular suma de xi^2
    sum_yi = sum_yi + tiempo(1,i); % calcular suma de yi
    sum_xi = sum_xi + distancia(1,i); % calcular suma de xi
    sum_xi_yi = sum_xi_yi + (distancia(1,i) * tiempo(1,i)); % calcular suma de yi * xi
end

% <-----Calcular valores para obtener la funcion------>
% Obtener m
m_ar_izq = sum_xi_yi * n; %m arriba izq
m_ar_der = sum_yi * sum_xi; %m arriba der

m_ab_izq = sum_xi_2 * n; %m abajo izq
m_ab_der = sum_xi^2; %m abajo der

m_arriba = m_ar_izq - m_ar_der; %m arriba
m_abajo = m_ab_izq - m_ab_der; %m abajo

m = m_arriba / m_abajo; % <-----M Result------>
fprintf('m = %.8f\n', m);

% Obtener b
b_ar_izq = sum_xi_2 * sum_yi; %b arriba izq
b_ar_der = sum_xi * sum_xi_yi; %b arriba der

b_ab_izq = sum_xi_2 * n; %b abajo izq
b_ab_der = sum_xi^2; %b abajo der

b_arriba = b_ar_izq - b_ar_der; %b arriba
b_abajo = b_ab_izq - b_ab_der; %b abajo

b = b_arriba / b_abajo; % <-----B Result------>
fprintf('b = %.8f\n', b);


% <-----Calcular valores para obtener los errores------>
syms x % hacer x una variable

y = m*x + b; % definir la funcion obtenida
delta_y = 0; % declarar delta y
sum_delta_y = 0; % declarar el acumulador de delta y
for i = 1:n
    delta_y = (tiempo(1,i) - subs(y,{x},distancia(1,i)))^2; % calcular delta y
    sum_delta_y = sum_delta_y + delta_y; % calcular suma de todas las delta y
end

% Obtener Sy
sy = sqrt(sum_delta_y/(n-2)); % <-----Sy Result------>
fprintf('sy = %.8f\n', sy);

% Obtener Sm
sm = sy * sqrt(n / ((sum_xi_2 * n) - (sum_xi^2))); % <-----Sm Result------>
fprintf('sm = %.12f\n', sm);

% Obtener Sb
sm = sy * sqrt(sum_xi_2 / ((sum_xi_2 * n) - (sum_xi^2))); % <-----Sb Result------>
fprintf('sb = %.12f\n', sm);

x = [1:0.1:n]; % definir rango de funcion
y = m*x + b; % declarar funcion
plot(distancia, tiempo); % graficar puntos originales
hold on % mantener grafica anterior
plot(x,y); % graficar funcion obtenida
title('Puntos originales y función obtenida');
xlabel('Distancia');
ylabel('Tiempo');
