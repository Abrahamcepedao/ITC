% Actividad 4 - Plots
% Abraham Cepeda Oseguera
% A00827666
clear; close all;
syms x
b = [-10:0.2:10];
fx0 = x^2 * sin(x);
fx1 = x - cos(x); 
fx2 = x*log10(x);  
fx3 = exp(0.3*x) - x^2; 
fx4 = 2*cos(x) - sqrt(x)/2; 
fx = [fx0,fx1,fx2,fx3,fx4];
tiledlayout(3,2)
for i = 1:5
    nexttile
    plot(b,subs(fx(i),b))
    grid on
    pause
end


