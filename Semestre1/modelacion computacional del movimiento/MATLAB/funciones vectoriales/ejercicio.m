t = 0:5:100;
x = (4*t.^3);
y = (5*t.^2);
plot3(x,y,t)
vx = (12*t.^2);
vy = (10*t);
hold on
plot3(vx,vy,t)
grid on
xlabel("x")
ylabel("y")
zlabel("t")





