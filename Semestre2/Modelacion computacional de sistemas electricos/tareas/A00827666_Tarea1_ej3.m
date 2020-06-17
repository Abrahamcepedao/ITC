% Tarea 1 - Ejercicio 3
% Abraham Cepeda Oseguera
% A00827666
clear, close all;
for i = 0:3:6
    rectangle('Position', [0 i 2 2], 'Curvature', [1, 1], 'FaceColor', 'r', 'EdgeColor', [0 0 1]);
    rectangle('Position', [4 i 2 2], 'Curvature', [1, 1], 'FaceColor', 'b', 'EdgeColor', [1 0 0]);
    axis equal
    hold on
end
title('</------Ejercicio 3------->')
