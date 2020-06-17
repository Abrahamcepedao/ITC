t = 0:0.1*pi:2*pi;
u = 0:0.1*pi:2*pi;
x = @(t,u) cos(t).* cos(u);
y = @(t,u) cos(t).* sin(u);
z = @(t) cos(t).^2;
comet3(x(t,u),y(t,u),z(t));
title('Ejercicio 3')
xlabel('x-value');
ylabel('y-value');
zlabel('t-value');
grid on
