% <---------------Proyecto Entregable 4: ModelaciÛn de baso-------------->
% Integrantes del equipo:
% Abraham Cepeda Oseguera A00827666
% Sergio LÛpez Urzaiz A00827462
% Jes˙s Gerardo RodrÌguez Trist·n A01283717
% Axel Gael Uzeta GÛmez A00829417
% Alexander Reyna RamÌrez A01570594

f = @(x) ((0.2*cos(1.5*x) - 3.5).^2); % Definir funciÛn del contorno del vaso
f2 = @(x) ((x-0.5)/0.016).^(1/3); % Definir funciÛn del interior del vaso
Vout = integral(f,0,16)* pi; % Calcular el volumen del vaso conforme al contorno
Vin = integral(f2,0.5,16)* pi; % Calcular el volumen interior del vaso

fprintf("El volumen exterior es de %f ml\n", Vout);
fprintf("El volumen interior es de %f ml\n", Vin);
fprintf("El volumen del vaso es de %f ml\n", Vout-Vin);

t = tiledlayout(2,2); % Definir la organizaciÛn de las gr·ficas que se van a mostrar (2x2)
y=[0:0.4:16]; % Definir los intervalos de y
x = 0.2*cos(1.5*y) - 3.5; % Declarar funcion exterior en tÈrminos de y
nexttile % Seleccionar el siguiente recuadro
plot(x,y) % Gr·ficar la funciÛn exterior en dos dimensiones
nexttile % Seleccionar el siguiente recuadro
cylinder(x) % Gr·ficar la funciÛn exterior en tres dimensiones, rotando la funcin sobre el eje y

y2 = [0.5:0.4:16]; % Definir los intervalos de y2
x2 = -((y2-0.5)/0.016).^(1/6); % Declarar funcion interior en tÈrminos de y

hold on % Mantenerse sobre el mismo recuadro
cylinder(x2) % graficar la funcion interior en el mismo recuadro para que se observe mejor la idea del diseno del vaso

nexttile % Seleccionar el siguiente recuadro
plot(x2,y2) % Gr·ficar la funcion interior en dos dimensiones
nexttile % Seleccionar el siguiente recuadro
cylinder(x2) % Gr·ficar la funcion interior en tres dimensiones, rotando la funcion sobre el eje y
