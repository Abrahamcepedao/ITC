num = input('Teclea un numero entero: ');

if num == 1
    disp('lunes ');
elseif num == 2
    disp('martes ');
elseif num == 3
    disp('miercoles ');
elseif num == 4
    disp('jueves ');
elseif num == 5
    disp('viernes ');
elseif num == 6
    disp('sabado ');
elseif num == 7
    disp('domingo ')
elseif(num < 1 || num > 7)
   disp('Error');
end