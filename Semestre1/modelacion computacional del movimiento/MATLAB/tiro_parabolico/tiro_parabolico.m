t = 0:0.1:3.1;
y = 15*t - 4.905*t.^2;
x = 25.98*t;
subplot (1,3,1)
%para cuer cuantos metros para llegar a altura max
plot(x,y)
subplot (1,3,2)
%para ver cuanto tiempo para llegar a altura max
plot(t,y)
subplot (1,3,3)
plot3(x,y,t)
 
plot(x,y)
hold on
for i = 0:0.1:3.1
    ex = 25.98*i;
    ey = 15*i - 4.905*i.^2;
    hold on
    plot(x(ex),y(ey), 'b0')
end
    
    