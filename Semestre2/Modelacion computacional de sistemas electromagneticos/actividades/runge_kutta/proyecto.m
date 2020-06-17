altura = input("Ingrese la altura a la que desea que este el dipolo (40-140)");
while (altura > 2 || altura < 0)
    altura = input("la altura debe estar entre 40 y 140 metros");
end
r = altura * 0.05;
mu0 = 4*pi*10^-7;
i = input("ingrese la corriente desada");
i= -i;
disp("Elija el tipo de material que va a utilizar");
disp("1) Hierro");
disp("2) Cobalto hierro");
disp("3) Niquel hierro");
disp("4) Manganeso-Zinc");
disp("5) Acero al carbon");
disp("6) Olatino");
op1 = input("ingrese el numero del material deseado");
while (op1 < 1 || op1 > 6)
    disp("las opciones posibles van del 1 al 6")
    op1 = input("");
end

if(op1 == 1)
    m = 6.3*10^-3;
end
if(op1 == 2)
   m = 2.3*10^-2;
end
if(op1 == 3)
   m = 1.25*10^-1;
end
if(op1 == 4)
   m = 2.5*10^-2;
end
if(op1 == 5)
   m = 1.26*10^-4;
end
if(op1 == 6)
   m = 1.26*10^-6;
end
m = i*pi*r^2;

g = input("Ingrese la masa deseada del dipo (1 - 100 gramos )");
while( g < 1 || g > 100)
    disp("la masa debe estar entre 1 y 100 gramos");
    g = input("Ingrese la masa nuevamente");
end
g = g/1000;

k = (3*m*mu0*i*r^2)/2*g;
f = @(z,t) -9.8 +  k*(z^2/(z^2 + r^2)^(5/2));

a = 1;
h = 0.1;
xi = 0;
xf = 10;
%[x,y] = RK_SegundoOrden(f,xi,xf,0,h,a);
[x,y] = RK_CuartoOrden(f,xi,xf,altura,h);
%x = [xi:h:xf];
plot(x,y);

