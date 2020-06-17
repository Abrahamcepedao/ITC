clc
close all
clear all
figure(1)
figure('units', 'normalized', 'outerposition', [0 0 1 1])
xx = 10;
while xx < 20
    clc
    close all
for x = -20:20
    xx = x + 1;
    y = -(x.*x);
    yy = -(xx.*xx);
    hold on
    xlim([-20 20])
    ylim([-400 0])
    plot(x, y, '*r')
    plot(xx,yy, 'ob')
    axis square

    pause(.2)
end
end