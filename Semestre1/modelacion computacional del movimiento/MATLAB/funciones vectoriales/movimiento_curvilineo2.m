t = 0:.5:2;
x = (7*cos(pi*t));
y = (-7*sin(pi*t));
plot3(x,y,t)
hold on
xlabel("x")
ylabel("y")
zlabel("t")
grid on