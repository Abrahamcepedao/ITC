% <---------------Proyecto Entregable 4: Modelación de baso-------------->
% Integrantes del equipo:
% Abraham Cepeda Oseguera A00827666
% Sergio López Urzaiz A00827462
% Jesús Gerardo Rodríguez Tristán A01283717
% Axel Gael Uzeta Gómez A00829417
% Alexander Reyna Ramírez A01570594

f = @(y) ((0.2*cos(1.5*y) - 3.5).^2); % Definir función del contorno del vaso
f2 = @(y) ((y-0.5)/0.016).^(1/3); % Definir función del interior del vaso
Vout = integral(f,0,16)* pi % Calcular el volumen del vaso conforme al contorno
Vin = integral(f2,0.5,16)* pi % Calcular el volumen interior del vaso

t = tiledlayout(2,2); % Definir la organización de las gráficas que se van a mostrar (2x2)
y=[0:0.4:16]; % Definir los intervalos de y
x = 0.2*cos(1.5*y) - 3.5; % Declarar funcion exterior en términos de y
nexttile % Seleccionar el siguiente recuadro
plot(x,y) % Gráficar la función exterior en dos dimensiones
nexttile % Seleccionar el siguiente recuadro
cylinder(x) % Gráficar la función exterior en tres dimensiones, rotando la función sobre el eje y

y2 = [0.5:0.4:16]; % Definir los intervalos de y2
x2 = -((y2-0.5)/0.016).^(1/6); % Declarar función interior en términos de y

hold on % Mantenerse sobre el mismo recuadro
cylinder(x2) % graficar la función interior en el mismo recuadro para que se observe mejor la idea del diseño del vaso

nexttile % Seleccionar el siguiente recuadro
plot(x2,y2) % Gráficar la función interior en dos dimensiones
nexttile % Seleccionar el siguiente recuadro
cylinder(x2) % Gráficar la función interior en tres dimensiones, rotando la función sobre el eje y
