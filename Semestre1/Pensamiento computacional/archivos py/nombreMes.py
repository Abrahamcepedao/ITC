def nombreMes(m):
    '''Función que recibe como parámetro de entrada del mes y retorna un string con el nombre del mes'''
    if m == 1:
        return 'Enero'
    if m == 2:
        return 'Febrero'
    if m == 3:
        return 'Marzo'
    if m == 4:
        return 'Abril'
    if m == 5:
        return 'Mayo'
    if m == 6:
        return 'Junio'
    if m == 7:
        return 'Julio'
    if m == 8:
        return 'Agosto'
    if m == 9:
        return 'Septiembre'
    if m == 10:
        return 'Octubre'
    if m == 11:
        return 'Noviembre'
    if m == 12:
        return 'Diciembre'
    else:
        return 'El mes ' + str(m) + 'no existe'
    
    
