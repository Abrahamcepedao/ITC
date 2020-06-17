%main
seg = input("Dame la cantidad de segundos ");
[hr, min, ss] = calcula_tiempo(seg);
fprintf("Cantidad de horas: %i\nCantidad de minutos %i\nCantidad de segundos%i", hr, min, ss);
% calcula_tiempo
% Convierte los segundos a hora, minutos y segundos
% Entrada: seg
% Salida: hr, min, ss
function [hr,min, ss] = calcula_tiempo(seg)
    hr = floor(seg/3600);
    min = floor(mod(seg, 3600)/60);
    ss = mod(mod(seg, 3600),60);
end
