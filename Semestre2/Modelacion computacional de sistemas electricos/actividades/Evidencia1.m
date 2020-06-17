tipoCarga=input("Desea colocar la posicion de una carga prueba o fuente? (p/f): ","s");
x=input("Coordenada en x de la carga: ");
y=input("Coordenada en y de la carga: ");
d=input("Elije la distancia entre las cargas fuente (m): ");
a=d/2;
d2=input("Elige la distancia entre la carga prueba y la carga fuente (m): ");
eje=input("Desea que las cargas fuente se encuentren en el eje x o y?: ","s");
if tipoCarga=="f"
    xQ1=x;
    yQ1=y;
    if eje=="x"
        xQ2=xQ1+(2*a);
        yQ2=yQ1;
        dire=input("Hacia donde quiere que este la carga prueba, arriba o abajo? (u/d): ","s");
        if dire=="u"
            r=sqrt((d2^2)-(a^2));
        else
            r=-(sqrt((d2^2)-(a^2)));
        end
        xQp=xQ1+a;
        yQp=yQ1+r;
    else
        xQ2=xQ1;
        yQ2=yQ1-(2*a);
        dire=input("Hacia donde quiere que este la carga prueba, derecha o izquierda? (d/i): ","s");
        if dire=="d"
            r=sqrt((d2^2)-(a^2));
        else
            r=-(sqrt((d2^2)-(a^2)));
        end
        xQp=xQ1+r;
        yQp=yQ1-a;
    end
else
    xQp=x;
    yQp=y;
    if eje=="x"
        dire=input("Hacia donde quiere que este la carga prueba, arriba o abajo? (u/d): ","s");
        if dire=="u"
            r=sqrt((d2^2)-(a^2));
        else
            r=-(sqrt((d2^2)-(a^2)));
        end
        xQ1=xQp-a;
        yQ1=yQp-r;
        xQ2=xQp+a;
        yQ2=yQp-r;
    else
        dire=input("Hacia donde quiere que este la carga prueba, derecha o izquierda? (d/i): ","s");
        if dire=="d"
            r=sqrt((d2^2)-(a^2));
        else
            r=-(sqrt((d2^2)-(a^2)));
        end
        xQ1=xQp-r;
        yQ1=yQp+a;
        xQ2=xQp-r;
        yQ2=yQp-a;
    end
end
q=input("Ingrese la magnitud de la carga en micro Coulombs: ");
q1=q/1000000;
q2=-q1;
k=1/(4*pi*(8.854*(10^-12)));
E1=((k*q1)/(d2^2));
E1xy=E1*[(xQp-xQ1)/d2 (yQp-yQ1)/d2];
E2=((k*q2)/(d2^2));
E2xy=E2*[(xQp-xQ2)/d2 (yQp-yQ2)/d2];
Exy=E1xy+E2xy;
E=sqrt((Exy(1)^2)+(Exy(2)^2));
rectangle('Position',[xQ1-.05 yQ1-.05 .1 .1],'Curvature',[1,1],'FaceColor','r','EdgeColor',[0 0 1]);
rectangle('Position',[xQ2-.05 yQ2-.05 .1 .1],'Curvature',[1,1],'FaceColor','b','EdgeColor',[1 0 0]);
rectangle('Position',[xQp-.05 yQp-.05 .1 .1],'Curvature',[1,1],'FaceColor','g','EdgeColor',[0 1 0]);
hold on

quiver(xQp,yQp,E1xy(1)/abs(E1),E1xy(2)/abs(E1))
txt = ['E1: (' num2str(E1xy(1)) ' i ' num2str(E1xy(2)) ' j ) ' 'N/C'];
text(xQp+(E1xy(1)/abs(E1)),yQp+(E1xy(2)/abs(E1)),txt);

quiver(xQp,yQp,E2xy(1)/abs(E2),E2xy(2)/abs(E2))
txt = ['E1: (' num2str(E2xy(1)) ' i ' num2str(E2xy(2)) ' j ) ' 'N/C'];
text(xQp+(E2xy(1)/abs(E2)),yQp+(E2xy(2)/abs(E2)),txt);

quiver(xQp,yQp,Exy(1)/abs(E),Exy(2)/abs(E))
txt = ['E1: (' num2str(Exy(1)) ' i ' num2str(Exy(2)) ' j ) ' 'N/C'];
text(xQp+(Exy(1)/abs(E)),yQp+(Exy(2)/abs(E)),txt);
hold off