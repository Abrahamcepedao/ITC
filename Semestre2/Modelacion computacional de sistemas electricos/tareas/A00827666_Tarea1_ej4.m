% Tarea 1 - Ejercicio 4
% Abraham Cepeda Oseguera
% A00827666
clear, close all;
[x, y] = meshgrid(0:0.2:2,0:0.2:2);
u = cos(x).*y;
v = sin(x).*y;
t = tiledlayout(2,2);
nexttile
quiver(x,y,u,v, 'linewidth', 1, 'color', [0,0,0]);
title('u = cos(x).*y & v = sin(x).*y');
nexttile
quiver(x,y,-u,v, 'linewidth', 1, 'color', [0,1,0.75]);
title('u = -cos(x).*y & v = sin(x).*y');
nexttile
quiver(x,y,u,-v, 'linewidth', 1, 'color', [0,1,1]);
title('u = cos(x).*y & v = -sin(x).*y');
nexttile
quiver(x,y,-u,-v, 'linewidth', 1, 'color', [0,0.5,1]);
title('u = -cos(x).*y & v = -sin(x).*y');