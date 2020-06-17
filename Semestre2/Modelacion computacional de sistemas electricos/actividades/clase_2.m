clear; clc; close all;
[tx, ty] = meshgrid(-10:0.2:10,-10:0.2:10);
z = @(x,y) (x.^2)/9 + (y.^2)/4;

figure
surf(tx,ty,z(tx,ty))
colormap winter
grid on
title('grafia 3d')

clear; clc; close all;

[tx, ty] = meshgrid(0:0.02*pi:2*pi,0:0.02*pi:2*pi);
z = @(x,y) sin(x-y).*sin(x).*sin(y);
figure
surf(tx,ty,z(tx,ty))
colorbar
box on
colormap parula; pause;
colormap winter; pause;
colormap lines;
grid on
zoom on
title('Grafica 3D');
axis off
colorbar off

clear; clc; close all;

x = [-2:0.2:2];
y = [-2:0.2:2];
[X,Y] = meshgrid(x,y);

Z = X.*exp(-X.^2-Y.^2);
figure(1)
mesh(X,Y,Z);
pause
F(1) = getframe;
surf(X,Y,Z);
F(2) = getframe;

grid on
movie(F,20)


clear; clc; close all;
[X,Y,Z] = sphere(100);
r = 3;
X = X * r;
Y = Y * r;
Z = Z * r;

Z(Z<0) = NaN;
figure(1)

contour3(X,Y,Z,3,'LineWidth', 1.5);
colormap parula(5)
pause
hold on
contour(X,Y,Z,3,'LineWidth', 1.5);
colormap parula(5)


clear; clc; close all;
[X,Y,Z] = sphere(100);
r = 3;
X = X * r;
Y = Y * r;
Z = Z * r;

Z(Z<0) = NaN;
figure(2)

surf(X,Y,Z, 'EdgeColor', 'none');
colormap parula
hold on
contour3(X,Y,Z,3,'LineWidth', 1.5);
colormap winter


