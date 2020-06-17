clear
clc
syms a0 a1 a2 a3 x
%----------------------------------------------------------------

%%Obtener funcion

x1=100;     %Punto inicial
y1=500;

x2=2800;    %Punto Final
y2=200;     

eq1= a3*x1^3+a2*x1^2+a1*x1+a0==y1;
eq2= a3*x2^3+a2*x2^2+a1*x2+a0==y2;

%Editables
x3=775;     %Punto 1
y3=-3000;

x4=2125;    %Punto 2
y4=1000;

eq3= a3*x3^3+a2*x3^2+a1*x3+a0==y3;
eq4= a3*x4^3+a2*x4^2+a1*x4+a0==y4;

sol=solve([eq1,eq2,eq3,eq4],[a0,a1,a2,a3]);%%Solucion lineal de la ecuacion

v1=double(sol.a0); %Se asignan los valores de cada coeficiente
v2=double(sol.a1);
v3=double(sol.a2);
v4=double(sol.a3);


%----------------------------------------------------------------

%%Longitud de curvatura

fx=v4*x^3+v3*x^2+v2*x+v1;  %Funcion general 
fxd=diff(fx);              %Derivada de la funcion
fxl=sqrt(1+(fxd^2));       

lg=int(fxl,x,[x1,x2]);     %Longitud de curva
%----------------------------------------------------------------

%Obtener minimos del radio de curvatura
mini = 797;
min = 93.687470156344;
mini2 = 2354;
min2 = 99.967353;

%----------------------------------------------------------------
%%Tangente y punto medio de la grada_1

y=fx;   %Funcion general
puntox= mini;   %Punto minimo 1 de radio de curvatura
yprim=diff(y);  %Derivada de la funcion
m = subs(yprim,x,puntox);   %Se obtiene la pendiente en el minimo en el punto
puntoy=subs(y,x,puntox);    %Se encuentra el punto y

y2f=m*x-m*puntox+puntoy;    %Se establece la funcion de la recta tangente
y2t=y2f; %Se crea una nueva variable para la funcion tangente

if(m>0) %Se evalua si la pendiente es positiva se establece una distancia sobre la tangente de -20
    f1 =-20;
else    %Si es negativa la distancia es de 20 sobre la tangente
    f1 =20;
end
x2f= puntox+f1*sqrt(1/(1+m^2)); %Se obtiene la X sobre la tangente que de distancia sea 20
y2f= puntoy+m*f1*sqrt(1/(1+m^2));   %Se obtiene la Y sobre la tangente que de distancia sea 20
%%Tangente y punto medio de la grada_2

y_2=fx; %Funcion general
puntox_2= mini2;    %Punto minimo 2 de radio de curvatura
yprim_2=diff(y);    %Derivada de la funcion
m_2 = subs(yprim,x,puntox_2);   %Se obtiene la pendiente en el minimo en el punto
puntoy_2=subs(y,x,puntox_2);    %Se encuentra el punto Y
y2f_2=m_2*x-m_2*puntox_2+puntoy_2;  %Se establece la funcion de la recta tangente
y2t_2 = y2f_2;  %Se crea una nueva variable para la funcion tangente
if(m_2>0)   %Se evalua si la pendiente es positiva se establece una distancia sobre la tangente de 20
    f1_2 =20;
else        %Si es negativa la distancia es de -20 sobre la tangente
    f1_2 =-20;
end
x2f_2= puntox_2+f1_2*sqrt(1/(1+m_2^2)); %Se obtiene la X sobre la tangente que de distancia sea 20
y2f_2= puntoy_2+m_2*f1_2*sqrt(1/(1+m_2^2)); %Se obtiene la Y sobre la tangente que de distancia sea 20
%----------------------------------------------------------------

%obtener puntos de la 1er barrera
xgrada1_i=x2f-40; %Esquina izquierda de la barrera
ygrada1_i=y2f;  

xgrada1_f=x2f+40; %Esquina derecha de la barrera
ygrada1_f=y2f;


%obtener puntos de la 2da barrera
xgrada2_i=x2f_2-40; %Esquina izquierda de la barrera
ygrada2_i=y2f_2;

xgrada2_f=x2f_2+40; %Esquina derecha de la barrera
ygrada2_f=y2f_2;

%----------------------------------------------------------------

%Puntos relevantes de la funcion

%Puntos criticos
fder = diff(fx);    %Se obtiene la derivada de la funcion
fder = simplify(fder);  %Se simplifica la derivada de la funcion (a decimales)
crit_p = solve(fder);   %Se aplica solucion lineal a la funcion, obteniendo los puntos minimos/maximos


%Puntos de inflexion
fder = diff(diff(fx));  %Se obtiene la segunda derivada
inflec_pt = solve(fder,'MaxDegree',3);  %Se resuelve la segunda derivada donde cambia la concavidad de la funcion de 3 grado
idx = imag(double(inflec_pt)) == 0;     %Se resuelve donde es 0 en la funcion
inflec_pt = inflec_pt(idx);             %Se obtienen y almacenan las coordenadas del punto de inflexion


%----------------------------------------------------------------
%Todas las impresiones
fprintf("<-------Diseño de la zona de curvas en una pista de Fórmula Uno------->\n")
fprintf("<-------Función general------->\n")
fprintf("y = %.9fx^3 + %.9fx^2 %.9fx + %.9f\n",v4,v3,v2,v1); %Se imprime la funcion
fprintf("a0: %.9f\n", v1);
fprintf("a1: %.9f\n", v2);
fprintf("a2: %.9f\n", v3);
fprintf("a3: %.9f\n\n", v4);

fprintf("<-------Longitud de curva------->\n")
fprintf("l = %0.4f\n\n",lg);   %Se imprime la longitud

fprintf("<-------Valores mínimos radio de curvatura------->\n")
fprintf("El valor minimo del radio %i de curvatura es de: %.12f\n",mini, min);
fprintf("El valor minimo del radio %i de curvatura es de: %.12f\n\n",mini2, min2);

fprintf("<-------Datos radio de curvatura en el punto 1------->\n");
fprintf("Pendiente 1 radio curvatura minimo: %.9f\n",m);    %Se imprime la pendiente 
fprintf("Punto 1 radio curvatura minimo: (%.9f,%.9f)\n",puntox,puntoy); %Se imprime el punto 1
fprintf("La funcion en el punto 1 es: y= ");
disp(y2t); %Se imprime la funcion

fprintf("Posicion del centro de la 1er grada: (%.9f,%.9f)\n",x2f,y2f);   %Se imprime el punto central frontal de las gradas

fprintf("Pendiente 2 radio de curvatura minimo: %.9f\n",m_2);   %Se imprime la pendiente
fprintf("Punto 2 radio de curvatura minimo: (%.9f,%.9f)\n",puntox_2,puntoy_2); %Se imprime el punto 2

fprintf("La funcion en el punto 2 es: y=");   
disp(y2t_2);    %Se imrpime la funcion

fprintf("Posicion del centro de la 2da grada: (%.9f,%.9f)\n",x2f_2,y2f_2);   %Se imprime el punto central frontal de las gradas

fprintf("Coordenadas barrera1: (%.9f,%.9f),(%.9f,%.9f)\n",xgrada1_i,ygrada1_i,xgrada1_f,ygrada1_f);

fprintf("Coordenadas barrera2: (%.9f,%.9f),(%.9f,%.9f)\n",xgrada2_i,ygrada2_i,xgrada2_f,ygrada2_f); %Se imprimen las coordenadas

fprintf("Puntos Criticos: ");
disp(crit_p);

fprintf("Puntos Inflexion: %.12f", inflec_pt);

%----------------------------------------------------------------
%Plot graph

%--------------------------------

%Graficar funcion general

%Punto inicial
plot(x1,y1,'or');
hold on
%Punto final
plot(x2,y2,'ob');
hold on
%Funcion general
fplot(fx,[x1,x2],'color',[0 0 0]);
hold on

%--------------------------------

%Puntos criticos e inflexion

%Puntos criticos
plot(double(crit_p), double(subs(fx,crit_p)),'rx'); %Se grafican todos los puntos criticos/max/min de la funcion con una x en color rojo
hold on

%Punto inflexion
plot(double(inflec_pt), double(subs(fx,inflec_pt)),'bx');   %Se grafican los puntos de inflexion con una x en color azul
text(double(inflec_pt), double(subs(fx,inflec_pt)),'Punto inflexion')   %Se agrega texto sobre las coordenadas de los puntos
hold on

%--------------------------------

%Tangentes

%Tangente punto 1 minimo del radio
fplot(y2t,[x1 x2], '--','color',[.32 .133 .9]); %Se grafica la funcion tangente del punto 1 minimo del radio 
hold on
%Tangente punto 2 minimo del radio
fplot(y2t_2,[x1 x2], '--','color',[.32 .133 .9]);   %Se grafica la funcion tangente del punto 2 minimo del radio
hold on

%--------------------------------

%Puntos con radio menor a 100

%Punto 1 radio<=100
plot(puntox, puntoy, 'or'); %Se grafica el punto 1 minimo del radio
hold on

%Punto 2 radio<=100
plot(puntox_2, puntoy_2, 'or'); %Se grafica el punto 1 minimo del radio
hold on

%--------------------------------

%Graficar gradas

%Punto Central Gradas 1
plot(x2f, y2f, 'o', 'color',[.79 .5 .181]); %Se grafica el punto central de la primer grada/barrera
hold on

%Punto Central Gradas 2
plot(x2f_2, y2f_2, 'o','color',[.79 .5 .181]);  %Se grafica el punto central de la segunda grada/barrera
hold on

%%Grada 1
plot(xgrada1_i,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
hold on
plot(xgrada1_f,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
plot([xgrada1_i, xgrada1_f], [ygrada1_f, ygrada1_f],'color',[0 0 0]);   %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1
gx1_i=[xgrada1_i xgrada1_i];   
gy1_i=[ygrada1_f ygrada1_f-10];
plot(gx1_i,gy1_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

hold on
plot(xgrada1_i,ygrada1_f-10,'o','color',[0 0 0]);
hold on
plot(xgrada1_f,ygrada1_f-10,'o','color',[0 0 0]);
plot([xgrada1_i, xgrada1_f], [ygrada1_f-10, ygrada1_f-10],'color',[0 0 0]); %Se grafica una linea horizontal entre el izquierdo 2 y derecho 2 
gx1_f=[xgrada1_f xgrada1_f];
gy1_f=[ygrada1_f ygrada1_f-10];
plot(gx1_f,gy1_f,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto derecho 1 y derecho 2

hold on

%Gradas 2
plot(xgrada2_i,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
hold on
plot(xgrada2_f,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
plot([xgrada2_i, xgrada2_f], [ygrada2_f, ygrada2_f],'color',[0 0 0]) %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1 
gx2_i=[xgrada2_i xgrada2_i];
gy2_i=[ygrada2_f ygrada2_f+10];
plot(gx2_i,gy2_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

hold on
plot(xgrada2_i,ygrada2_f+10,'o','color',[0 0 0]);
hold on
plot(xgrada2_f,ygrada2_f+10,'o','color',[0 0 0]);
plot([xgrada2_i, xgrada2_f], [ygrada2_f+10, ygrada2_f+10],'color',[0 0 0]) %Se grafica una linea horizontal entre el derecho 1 e izquierdo 2 

gx2_f=[xgrada2_f xgrada2_f];
gy2_f=[ygrada2_f ygrada2_f+10];
plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
hold off

num = 2;
if num == 1
    %ylim(app.UIAxes,[0 maxheight]);
    %xlim(app.UIAxes,[0 xmove]);
    ylim([1270 1330]);
    xlim([2320 2440]);
    figure(2);
    px = 2320;
    py = 1286;
    %Gradas 2
    plot(xgrada2_i,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada2_f,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada2_i, xgrada2_f], [ygrada2_f, ygrada2_f],'color',[0 0 0]) %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1 
    gx2_i=[xgrada2_i xgrada2_i];
    gy2_i=[ygrada2_f ygrada2_f+10];
    plot(gx2_i,gy2_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada2_i,ygrada2_f+10,'o','color',[0 0 0]);
    hold on
    plot(xgrada2_f,ygrada2_f+10,'o','color',[0 0 0]);
    plot([xgrada2_i, xgrada2_f], [ygrada2_f+10, ygrada2_f+10],'color',[0 0 0]) %Se grafica una linea horizontal entre el derecho 1 e izquierdo 2 

    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    hold on
    fplot(fx,[2320,2500],'color',[0 0 0]);
    hold on
    fplot(y2t_2,[2320 2390], '--','color',[.32 .133 .9]);
    hold on
    for i=px:0.05:2440
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
    end
    %----------------------------------------
    
    %ylim(app.UIAxes,[0 maxheight]);
    %xlim(app.UIAxes,[0 xmove]);
    ylim([-3080 -2920]);
    xlim([768 867]);
    figure(3);
    px = 768.2;
    py = -2997;
    %%Grada 1
    plot(xgrada1_i,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada1_f,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada1_i, xgrada1_f], [ygrada1_f, ygrada1_f],'color',[0 0 0]);   %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1
    gx1_i=[xgrada1_i xgrada1_i];   
    gy1_i=[ygrada1_f ygrada1_f-10];
    plot(gx1_i,gy1_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada1_i,ygrada1_f-10,'o','color',[0 0 0]);
    hold on
    plot(xgrada1_f,ygrada1_f-10,'o','color',[0 0 0]);
    plot([xgrada1_i, xgrada1_f], [ygrada1_f-10, ygrada1_f-10],'color',[0 0 0]); %Se grafica una linea horizontal entre el izquierdo 2 y derecho 2 
    gx1_f=[xgrada1_f xgrada1_f];
    gy1_f=[ygrada1_f ygrada1_f-10];
    plot(gx1_f,gy1_f,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto derecho 1 y derecho 2

    hold on
    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    hold on
    fplot(fx,[760,880],'color',[0 0 0]);
    hold on
    fplot(y2t,[760,880], '--','color',[.32 .133 .9]);
    hold on
    for i=px:0.05:868
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
    end
    
    
elseif num == 2
    ylim([1270 1340]);
    xlim([2320 2500]);
    figure(2);
    %Gradas 2
    plot(xgrada2_i,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada2_f,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada2_i, xgrada2_f], [ygrada2_f, ygrada2_f],'color',[0 0 0]) %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1 
    gx2_i=[xgrada2_i xgrada2_i];
    gy2_i=[ygrada2_f ygrada2_f+10];
    plot(gx2_i,gy2_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada2_i,ygrada2_f+10,'o','color',[0 0 0]);
    hold on
    plot(xgrada2_f,ygrada2_f+10,'o','color',[0 0 0]);
    plot([xgrada2_i, xgrada2_f], [ygrada2_f+10, ygrada2_f+10],'color',[0 0 0]) %Se grafica una linea horizontal entre el derecho 1 e izquierdo 2 

    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    fplot(fx,[2320,2390],'color',[0 0 0]);
    hold on
    fplot(y2t_2,[2320 2390], '--','color',[.32 .133 .9]);
    hold on
    px = 2320;
    py = 1286;
    for i=px:0.05:2373
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        if i < 2354
            py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
        else
            py = m_2*i-m_2*puntox_2+puntoy_2;
        end
    end 
    
    %----------------------------------------
    figure(3);
    ylim([-3080 -2920]);
    xlim([768 867]);
    px = 768.2;
    py = -2997;
    %%Grada 1
    plot(xgrada1_i,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada1_f,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada1_i, xgrada1_f], [ygrada1_f, ygrada1_f],'color',[0 0 0]);   %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1
    gx1_i=[xgrada1_i xgrada1_i];   
    gy1_i=[ygrada1_f ygrada1_f-10];
    plot(gx1_i,gy1_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada1_i,ygrada1_f-10,'o','color',[0 0 0]);
    hold on
    plot(xgrada1_f,ygrada1_f-10,'o','color',[0 0 0]);
    plot([xgrada1_i, xgrada1_f], [ygrada1_f-10, ygrada1_f-10],'color',[0 0 0]); %Se grafica una linea horizontal entre el izquierdo 2 y derecho 2 
    gx1_f=[xgrada1_f xgrada1_f];
    gy1_f=[ygrada1_f ygrada1_f-10];
    plot(gx1_f,gy1_f,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto derecho 1 y derecho 2

    hold on
    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    hold on
    fplot(fx,[760,880],'color',[0 0 0]);
    hold on
    fplot(y2t,[760,880], '--','color',[.32 .133 .9]);
    hold on
    for i=px:0.05:816
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        if i < 797
            py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
        else
            py = m*i-m*puntox+puntoy;
        end
    end 
    
end
