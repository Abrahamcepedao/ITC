t = 0:5:100;
x = (4*t.^3) - (10*t);
y = (9*t) - (t.^2);
plot3(x,y,t)
vx = (12*t.^2) - 10;
vy = (9-2*t);
hold on
plot3(vx,vy,t)
ax = (24*t);
ay = (-2);
hold on
grid on
xlabel("x")
ylabel("y")
zlabel("t")
