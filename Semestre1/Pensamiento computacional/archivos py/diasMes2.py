def diaSiguiente(d, m, a):
    '''Recibe una fecha y la función debe calcular el dia siguiente o detectar error en fecha
   
   Análisis:
    datos de entrada: dia, mes, años
    datos de salida: desplegar el dia siguiente o error en fecha
    
   Procesos-
   -caso 1: error en fecha
   -caso 2: día actual (fin de mes)
   -caso 3: día actual (fin de año)
   -caso 4: día regular
'''
    dM = diasMes(m)
    if (d > 0 and d <= dM) and (dM != 0) and (a > 1900):
        #poner lo mas frecuente primero
        if d < dM:
            d = d + 1
        elif m < 12:
            d = 1
            m = m +1
        else:
            d = 1
            m = 1
            a = a +1
        print(d,m,a, sep="/")   
    else:
        print('ERROR')


def diasMes(m):
    #validar el mes
    if m > 0 and m <=12:
        if m in [1, 3, 5, 7, 10, 12]:
            return 31
        elif m == 2:
            return 28
        else:
            return 30
    else:
       return 0
    
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
    
def main():
    #leer el dia
    dia = int(input())
     #leer el mes
    mes = int(input())
     #leer el año
    año = int(input())
    
    diaSiguiente(dia, mes, año)
  



#llamar main
main()


    