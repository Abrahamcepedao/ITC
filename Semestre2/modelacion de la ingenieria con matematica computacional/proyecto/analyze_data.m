% <-----------------Entregable 2----------------->
% Integrantes del equipo:
% Abraham Cepeda Oseguera A00827666
% Sergio López Urzaiz A00827462
% Jesús Gerardo Rodríguez Tristán A01283717
% Axel Gael Uzeta Gómez A00829417
% Alexander Reyna Ramírez A01570594

% <----Edades----->
% Grupo 1 < 20
% Grupo 2 < 40
% Grupo 3 > 40

% <----Sexo----->
% 1 = Masculino
% 2 = Femenino

% <----Pedir----->
% 1 = Paloma
% 2 = Cerveza
% 3 = Vino
% 4 = Coctel
% 5 = Solo
% 6 = Otros

% <----Coctel----->
% 0 = No
% 1 = Blue Moon
% 2 = Mojito
% 3 = Piña Colada
% 4 = Frutas
% 5 = Sangría
% 6 = Vampiro
% 7 = Bull
% 8 = Clericot
% 9 = Michelada
% 10 = Paloma
% 11 = Baby Mango
% 12 = Blue Hawaii
% 13 = Vodka Tonic
% 14 = Martini
% 15 = Bloody Mary

% <----Forma----->
% 1 = Curvo
% 2 = Recto

% <----Vaso----->
% 1 = Caballito
% 2 = Chico
% 3 = Normal
% 4 = Tarro
% 5 = Copa

% <----Textura----->
% 1 = Liso
% 2 = Textura

data =  csvread('Encuesta.csv', 1);
answer = 1;

while answer ~= 0
    answer = menu();
    figure
    if answer == 1
        title('Preferencia de vaso por cada sexo');
        hold on
        h = vaso_por_sexo(data);
    elseif answer == 2
        title('Coctel más popular de todas las edades');
        hold on
        h = coctel_mas_popular(data);
    elseif answer == 3
        title('Coctel más popular dentro del primer grupo de edad');
        hold on
        h = coctel_mas_popular_1(data);
    elseif answer == 4
        title('Coctel más popular dentro del segundo grupo de edad');
        hold on
        h = coctel_mas_popular_2(data);
    elseif answer == 5
        title('Coctel más popular dentro del tercer grupo de edad');
        hold on
        h = coctel_mas_popular_3(data);
    elseif answer == 6
        title('Coctel más popular entre hombres del primer grupo de edad');
        hold on
        h = coctel_mas_popular_1_m(data);
    elseif answer == 7
        title('Coctel más popular entre mujeres del primer grupo de edad');
        hold on
        h = coctel_mas_popular_1_f(data);
    elseif answer == 8
        title('Gusto de que un vaso sea exótico');
        hold on
        h = vaso_exotico(data);
    elseif answer == 9
        title('Gusto de que un vaso sea exótico del primer grupo de edad');
        hold on
        h = vaso_exotico_1(data);
    elseif answer == 10
        title('Gusto de que un vaso sea exótico del segundo grupo de edad');
        hold on
        h = vaso_exotico_2(data);
    elseif answer == 11
        title('Gusto de que un vaso sea exótico del tercer grupo de edad');
        hold on
        h = vaso_exotico_3(data);
    elseif answer == 12
        title('Vaso preferido');
        hold on
        h = vaso_preferido(data);
    elseif answer == 13
        title('Vaso preferido dentro del primer grupo de edad');
        hold on
        h = vaso_preferido_1(data);
    elseif answer == 14
        title('Vaso preferido dentro del segundo grupo de edad');
        hold on
        h = vaso_preferido_2(data);
    elseif answer == 15
        title('Vaso preferido dentro del tercer grupo de edad');
        hold on
        h = vaso_preferido_3(data);
    elseif answer == 16
        title('Bebidas pedidas por hombres');
        hold on
        h = bebidas_hombres(data);
    elseif answer == 17
        title('Bebidas pedidas por mujeres');
        hold on
        h = bebidas_mujeres(data);
    elseif answer == 18
        title('Edades de los encuestados');
        hold on
        h = edades(data);
    end
end

fprintf("\n\n\nGracias por utilizar nuestro programa!\n\n\n")

% Menu function
function answer = menu()
    fprintf("<-----Teclea la opción que deseas graficar------>\n");
    fprintf("0. Para terminar el programa\n");
    fprintf("1. Forma de paso por cada sexo\n");
    fprintf("2. Coctel mas popular (Edad general)\n");
    fprintf("3. Coctel mas popular (Primer grupo de edad)\n");
    fprintf("4. Coctel mas popular (Segundo grupo de edad)\n");
    fprintf("5. Coctel mas popular (Tercer grupo de edad)\n");
    fprintf("6. Coctel mas popular entre hombres (Primer grupo de edad)\n");
    fprintf("7. Coctel mas popular entre mujeres (Primer grupo de edad)\n");
    fprintf("8. Gusto de vaso exótico (Edad general)\n");
    fprintf("9. Gusto de vaso exótico (Primer grupo de edad)\n");
    fprintf("10. Gusto de vaso exótico (Segundo grupo de edad)\n");
    fprintf("11. Gusto de vaso exótico (Tercer grupo de edad)\n");
    fprintf("12. Tipo de vaso preferido (Edad general)\n");
    fprintf("13. Tipo de vaso preferido (Primer grupo de edad)\n");
    fprintf("14. Tipo de vaso preferido (Segundo grupo de edad)\n");
    fprintf("15. Tipo de vaso preferido (Tercer grupo de edad)\n");
    fprintf("16. Bebidas pedidas por hombres\n");
    fprintf("17. Bebidas pedidas por mujeres\n");
    fprintf("18. Edades de los encuestados\n");
    answer = input("Teclea tu respuesta: ");
end

% Preferencia de vaso recto o curvo por cada sexo
function h = vaso_por_sexo(M)
    dataset = zeros(1,4);
    for i = 1:1:62
        if M(i,2) == 1
            if M(i,7) == 1
                dataset(1,1) = dataset(1,1) + 1;
            else
                dataset(1,2) = dataset(1,2) + 1;
            end
        else
            if M(i,7) == 1
                dataset(1,3) = dataset(1,3) + 1;
            else
                dataset(1,4) = dataset(1,4) + 1;
            end
        end
    end
    h = histogram('Categories',{'H Curvo','H Recto','M Curvo', 'M Recto'},'BinCounts',[dataset]);
end

% Coctel más popular incluyendo a gente de todas las edades
function h = coctel_mas_popular(M)
    dataset = zeros(1,16);
    for i = 1:1:62
        if M(i,6) == 0
            dataset(1,1) = dataset(1,1) + 1;
        elseif M(i,6) == 1
            dataset(1,2) = dataset(1,2) + 1;
        elseif M(i,6) == 2
            dataset(1,3) = dataset(1,3) + 1;
        elseif M(i,6) == 3
            dataset(1,4) = dataset(1,4) + 1;
        elseif M(i,6) == 4
            dataset(1,5) = dataset(1,5) + 1;
        elseif M(i,6) == 5
            dataset(1,6) = dataset(1,6) + 1;
        elseif M(i,6) == 6
            dataset(1,7) = dataset(1,7) + 1;
        elseif M(i,6) == 7
            dataset(1,8) = dataset(1,8) + 1;
        elseif M(i,6) == 8
            dataset(1,9) = dataset(1,9) + 1;
        elseif M(i,6) == 9
            dataset(1,10) = dataset(1,10) + 1;
        elseif M(i,6) == 10
            dataset(1,11) = dataset(1,11) + 1;
        elseif M(i,6) == 11
            dataset(1,12) = dataset(1,12) + 1;
        elseif M(i,6) == 12
            dataset(1,13) = dataset(1,13) + 1;
        elseif M(i,6) == 13
            dataset(1,14) = dataset(1,14) + 1;
        elseif M(i,6) == 14
            dataset(1,15) = dataset(1,15) + 1;
        elseif M(i,6) == 15
            dataset(1,16) = dataset(1,16) + 1;
        end
    end
    h = histogram('Categories',{'No','Blue Moon','Mojito', 'Piña colada', 'Frutas', 'Sangría', 'Vampiro', 'Bull', 'Clericot', 'Michelada', 'Paloma', 'Baby mango', 'Blue Hawaii', 'Vodka Tonic', 'Martini', 'Bloody Mary'},'BinCounts',[dataset]);
end

% Coctel más popular dentro del primer grupo de edad
function h = coctel_mas_popular_1(M)
    dataset = zeros(1,16);
    for i = 1:1:62
        if M(i,1) == 1
            if M(i,6) == 0
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,6) == 1
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,6) == 2
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,6) == 3
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,6) == 4
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,6) == 5
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,6) == 6
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,6) == 7
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,6) == 8
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,6) == 9
                dataset(1,10) = dataset(1,10) + 1;
            elseif M(i,6) == 10
                dataset(1,11) = dataset(1,11) + 1;
            elseif M(i,6) == 11
                dataset(1,12) = dataset(1,12) + 1;
            elseif M(i,6) == 12
                dataset(1,13) = dataset(1,13) + 1;
            elseif M(i,6) == 13
                dataset(1,14) = dataset(1,14) + 1;
            elseif M(i,6) == 14
                dataset(1,15) = dataset(1,15) + 1;
            elseif M(i,6) == 15
                dataset(1,16) = dataset(1,16) + 1;
            end
        end
    end
    h = histogram('Categories',{'No','Blue Moon','Mojito', 'Piña colada', 'Frutas', 'Sangría', 'Vampiro', 'Bull', 'Clericot', 'Michelada', 'Paloma', 'Baby mango', 'Blue Hawaii', 'Vodka Tonic', 'Martini', 'Bloody Mary'},'BinCounts',[dataset]);
end

% Coctel más popular dentro del segundo grupo de edad
function h = coctel_mas_popular_2(M)
    dataset = zeros(1,16);
    for i = 1:1:62
        if M(i,1) == 2
            if M(i,6) == 0
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,6) == 1
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,6) == 2
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,6) == 3
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,6) == 4
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,6) == 5
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,6) == 6
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,6) == 7
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,6) == 8
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,6) == 9
                dataset(1,10) = dataset(1,10) + 1;
            elseif M(i,6) == 10
                dataset(1,11) = dataset(1,11) + 1;
            elseif M(i,6) == 11
                dataset(1,12) = dataset(1,12) + 1;
            elseif M(i,6) == 12
                dataset(1,13) = dataset(1,13) + 1;
            elseif M(i,6) == 13
                dataset(1,14) = dataset(1,14) + 1;
            elseif M(i,6) == 14
                dataset(1,15) = dataset(1,15) + 1;
            elseif M(i,6) == 15
                dataset(1,16) = dataset(1,16) + 1;
            end
        end
    end
    h = histogram('Categories',{'No','Blue Moon','Mojito', 'Piña colada', 'Frutas', 'Sangría', 'Vampiro', 'Bull', 'Clericot', 'Michelada', 'Paloma', 'Baby mango', 'Blue Hawaii', 'Vodka Tonic', 'Martini', 'Bloody Mary'},'BinCounts',[dataset]);
end

% Coctel más popular dentro del tercer grupo de edad
function h = coctel_mas_popular_3(M)
    dataset = zeros(1,16);
    for i = 1:1:62
        if M(i,1) == 3
            if M(i,6) == 0
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,6) == 1
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,6) == 2
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,6) == 3
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,6) == 4
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,6) == 5
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,6) == 6
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,6) == 7
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,6) == 8
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,6) == 9
                dataset(1,10) = dataset(1,10) + 1;
            elseif M(i,6) == 10
                dataset(1,11) = dataset(1,11) + 1;
            elseif M(i,6) == 11
                dataset(1,12) = dataset(1,12) + 1;
            elseif M(i,6) == 12
                dataset(1,13) = dataset(1,13) + 1;
            elseif M(i,6) == 13
                dataset(1,14) = dataset(1,14) + 1;
            elseif M(i,6) == 14
                dataset(1,15) = dataset(1,15) + 1;
            elseif M(i,6) == 15
                dataset(1,16) = dataset(1,16) + 1;
            end
        end
    end
    h = histogram('Categories',{'No','Blue Moon','Mojito', 'Piña colada', 'Frutas', 'Sangría', 'Vampiro', 'Bull', 'Clericot', 'Michelada', 'Paloma', 'Baby mango', 'Blue Hawaii', 'Vodka Tonic', 'Martini', 'Bloody Mary'},'BinCounts',[dataset]);
end


% Coctel más popular dentro de los hombres del primer grupo de edad
function h = coctel_mas_popular_1_m(M)
    dataset = zeros(1,16);
    for i = 1:1:62
        if M(i,1) == 1 && M(i,2) == 1
            if M(i,6) == 0
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,6) == 1
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,6) == 2
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,6) == 3
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,6) == 4
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,6) == 5
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,6) == 6
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,6) == 7
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,6) == 8
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,6) == 9
                dataset(1,10) = dataset(1,10) + 1;
            elseif M(i,6) == 10
                dataset(1,11) = dataset(1,11) + 1;
            elseif M(i,6) == 11
                dataset(1,12) = dataset(1,12) + 1;
            elseif M(i,6) == 12
                dataset(1,13) = dataset(1,13) + 1;
            elseif M(i,6) == 13
                dataset(1,14) = dataset(1,14) + 1;
            elseif M(i,6) == 14
                dataset(1,15) = dataset(1,15) + 1;
            elseif M(i,6) == 15
                dataset(1,16) = dataset(1,16) + 1;
            end
        end
    end
    h = histogram('Categories',{'No','Blue Moon','Mojito', 'Piña colada', 'Frutas', 'Sangría', 'Vampiro', 'Bull', 'Clericot', 'Michelada', 'Paloma', 'Baby mango', 'Blue Hawaii', 'Vodka Tonic', 'Martini', 'Bloody Mary'},'BinCounts',[dataset]);
end

% Coctel más popular dentro de los mujeres del primer grupo de edad
function h = coctel_mas_popular_1_f(M)
    dataset = zeros(1,16);
    for i = 1:1:62
        if M(i,1) == 1 && M(i,2) == 2
            if M(i,6) == 0
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,6) == 1
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,6) == 2
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,6) == 3
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,6) == 4
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,6) == 5
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,6) == 6
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,6) == 7
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,6) == 8
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,6) == 9
                dataset(1,10) = dataset(1,10) + 1;
            elseif M(i,6) == 10
                dataset(1,11) = dataset(1,11) + 1;
            elseif M(i,6) == 11
                dataset(1,12) = dataset(1,12) + 1;
            elseif M(i,6) == 12
                dataset(1,13) = dataset(1,13) + 1;
            elseif M(i,6) == 13
                dataset(1,14) = dataset(1,14) + 1;
            elseif M(i,6) == 14
                dataset(1,15) = dataset(1,15) + 1;
            elseif M(i,6) == 15
                dataset(1,16) = dataset(1,16) + 1;
            end
        end
    end
    h = histogram('Categories',{'No','Blue Moon','Mojito', 'Piña colada', 'Frutas', 'Sangría', 'Vampiro', 'Bull', 'Clericot', 'Michelada', 'Paloma', 'Baby mango', 'Blue Hawaii', 'Vodka Tonic', 'Martini', 'Bloody Mary'},'BinCounts',[dataset]);
end

% Qué tanto le gusta a cada persona que el vaso sea exótico dentro de todas
% las edades
function h = vaso_exotico(M)
    dataset = zeros(1,10);
    for i = 1:62
        if M(i,4) == 1
            dataset(1,1) = dataset(1,1) + 1;
        elseif M(i,4) == 2
            dataset(1,2) = dataset(1,2) + 1;
        elseif M(i,4) == 3
            dataset(1,3) = dataset(1,3) + 1;
        elseif M(i,4) == 4
            dataset(1,4) = dataset(1,4) + 1;
        elseif M(i,4) == 5
            dataset(1,5) = dataset(1,5) + 1;
        elseif M(i,4) == 6
            dataset(1,6) = dataset(1,6) + 1;
        elseif M(i,4) == 7
            dataset(1,7) = dataset(1,7) + 1;
        elseif M(i,4) == 8
            dataset(1,8) = dataset(1,8) + 1;
        elseif M(i,4) == 9
            dataset(1,9) = dataset(1,9) + 1;
        elseif M(i,4) == 10
            dataset(1,10) = dataset(1,10) + 1;
        end
    end
    h = histogram('Categories', {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10'}, 'BinCounts', [dataset]);
end
   
% Qué tanto le gusta a cada persona que el vaso sea exótico del primer
% grupo de edades
function h = vaso_exotico_1(M)
    dataset = zeros(1,10);
    for i = 1:62
        if M(i,1) == 1
            if M(i,4) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,4) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,4) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,4) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,4) == 5
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,4) == 6
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,4) == 7
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,4) == 8
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,4) == 9
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,4) == 10
                dataset(1,10) = dataset(1,10) + 1;
            end
        end
    end
    h = histogram('Categories', {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10'}, 'BinCounts', [dataset]);
end

% Qué tanto le gusta a cada persona que el vaso sea exótico del segundo
% grupo de edades
function h = vaso_exotico_2(M)
    dataset = zeros(1,10);
    for i = 1:62
        if M(i,1) == 2
            if M(i,4) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,4) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,4) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,4) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,4) == 5
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,4) == 6
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,4) == 7
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,4) == 8
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,4) == 9
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,4) == 10
                dataset(1,10) = dataset(1,10) + 1;
            end
        end
    end
    h = histogram('Categories', {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10'}, 'BinCounts', [dataset]);
end

% Qué tanto le gusta a cada persona que el vaso sea exótico del tercer
% grupo de edades
function h = vaso_exotico_3(M)
    dataset = zeros(1,10);
    for i = 1:62
        if M(i,1) == 3
            if M(i,4) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,4) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,4) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,4) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,4) == 5
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,4) == 6
                dataset(1,6) = dataset(1,6) + 1;
            elseif M(i,4) == 7
                dataset(1,7) = dataset(1,7) + 1;
            elseif M(i,4) == 8
                dataset(1,8) = dataset(1,8) + 1;
            elseif M(i,4) == 9
                dataset(1,9) = dataset(1,9) + 1;
            elseif M(i,4) == 10
                dataset(1,10) = dataset(1,10) + 1;
            end
        end
    end
    h = histogram('Categories', {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10'}, 'BinCounts', [dataset]);
end

%Vaso preferido de todas las edades
function h = vaso_preferido(M)
    dataset = zeros(1,5);
    for i = 1:62
        if M(i,8) == 1
            dataset(1,1) = dataset(1,1) + 1;
        elseif M(i,8) == 2
            dataset(1,2) = dataset(1,2) + 1;
        elseif M(i,8) == 3
            dataset(1,3) = dataset(1,3) + 1;
        elseif M(i,8) == 4
            dataset(1,4) = dataset(1,4) + 1;
        elseif M(i,8) == 5
            dataset(1,5) = dataset(1,5) + 1;
        end
    end
    h = histogram('Categories', {'Caballito', 'Chico', 'Normal', 'Tarro', 'Copa'}, 'BinCounts', [dataset]);
end

%Vaso preferido del primer grupo de edad
function h = vaso_preferido_1(M)
    dataset = zeros(1,5);
    for i = 1:62
        if M(i,1) == 1
            if M(i,8) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,8) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,8) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,8) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,8) == 5
                dataset(1,5) = dataset(1,5) + 1;
            end
        end
    end
    h = histogram('Categories', {'Caballito', 'Chico', 'Normal', 'Tarro', 'Copa'}, 'BinCounts', [dataset]);
end

%Vaso preferido del segundo grupo de edad
function h = vaso_preferido_2(M)
    dataset = zeros(1,5);
    for i = 1:62
        if M(i,1) == 2
            if M(i,8) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,8) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,8) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,8) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,8) == 5
                dataset(1,5) = dataset(1,5) + 1;
            end
        end
    end
    h = histogram('Categories', {'Caballito', 'Chico', 'Normal', 'Tarro', 'Copa'}, 'BinCounts', [dataset]);
end

%Vaso preferido del tercer grupo de edad
function h = vaso_preferido_3(M)
    dataset = zeros(1,5);
    for i = 1:62
        if M(i,1) == 3
            if M(i,8) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,8) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,8) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,8) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,8) == 5
                dataset(1,5) = dataset(1,5) + 1;
            end
        end
    end
    h = histogram('Categories', {'Caballito', 'Chico', 'Normal', 'Tarro', 'Copa'}, 'BinCounts', [dataset]);
end

%Bebidas pedidas por hombres
function h = bebidas_hombres(M)
    dataset = zeros(1,6);
    for i = 1:62
        if M(i,2) == 1
            if M(i,3) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,3) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,3) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,3) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,3) == 5
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,3) == 6
                dataset(1,6) = dataset(1,6) + 1;
            end
        end
    end
    h = histogram('Categories', {'Paloma', 'Cerveza', 'Vino', 'Coctel', 'Solo', 'Otros'}, 'BinCounts', [dataset]);
end

%Bebidas pedidas por mujeres
function h = bebidas_mujeres(M)
    dataset = zeros(1,6);
    for i = 1:62
        if M(i,2) == 2
            if M(i,3) == 1
                dataset(1,1) = dataset(1,1) + 1;
            elseif M(i,3) == 2
                dataset(1,2) = dataset(1,2) + 1;
            elseif M(i,3) == 3
                dataset(1,3) = dataset(1,3) + 1;
            elseif M(i,3) == 4
                dataset(1,4) = dataset(1,4) + 1;
            elseif M(i,3) == 5
                dataset(1,5) = dataset(1,5) + 1;
            elseif M(i,3) == 6
                dataset(1,6) = dataset(1,6) + 1;
            end
        end
    end
    h = histogram('Categories', {'Paloma', 'Cerveza', 'Vino', 'Coctel', 'Solo', 'Otros'}, 'BinCounts', [dataset]);
end

%edade de la gente que respondió
function h = edades(M)
    dataset = zeros(1,3);
    for i = 1:62
        if M(i,1) == 1
            dataset(1,1) = dataset(1,1) + 1;
        elseif M(i,1) == 2
            dataset(1,2) = dataset(1,2) + 1;
        elseif M(i,1) == 3
            dataset(1,3) = dataset(1,3) + 1;
        end
    end
    h = histogram('Categories', {'16 - 19', '20 - 39', '40 y mas'}, 'BinCounts', [dataset]);
end