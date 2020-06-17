p = 1:10;
x = zeros(1,10);
y = zeros(1,10);
z = zeros(1,10);

for i = 1:10
    x(i) = (i-1)/5;
    y(i) = sin((pi*(i-1))/4);
    z(i) = (pi*(i-1))/30;
    plot3(x,y,z, '.');
    axis=([-2,2,-2,2,-2,2]);
end

hold on
grid on

xm = sum(x)/10;
ym = sum(y)/10;
zm = sum(z)/10;

plot3(xm,ym,zm,'g.')
