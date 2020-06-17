for i = 0:0.5:10
    ey = -i.^2 + 10*i;
    ey2 = -i.^2 + 11*i;
    plot(i,ey, 'b*')
    hold on
    plot(i,ey2, 'ro')
end
    