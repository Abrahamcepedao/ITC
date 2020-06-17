#abraham cepeda a00827666
#ciclo while
import math
import sys

#///////////////////////////////////////////////creciente////////////////////////////////////////////////////////////////////////
def ciclo_contador_creciente():
    #desplegar que hace la funcion
    print('Esta función despliega los numeros del 1 ')
    print('Hasta el valor que ingreses ahora:', end='') 
    #leer la cantidad
    print('Teclea el valor:', end='')
    iN = int(input())
    # 1. Inicializar la vcc antes del ciclo
    iK = 1
    # 2. Incluir en la condición la vcc
    while iK <= iN:
        # Bloque de instrucciones del while
        # Delimitadas por la indentación
        print(iK)  
        # 3. Actualizar iK
        iK = iK + 1
def ciclo_contador_creciente_for():
    #desplegar que hace la funcion
    print('Esta función despliega los numeros del 1 ')
    print('Hasta el valor que ingreses ahora:', end='') 
    #leer la cantidad
    print('Teclea el valor:', end='')
    iN = int(input())
    # 2. Incluir en la condición la vcc
    for i in range (iN):
        # Bloque de instrucciones del while
        # Delimitadas por la indentación
        print(i)

#///////////////////////////////////////////////decreciente////////////////////////////////////////////////////////////////////////
def ciclo_contador_decreciente():
    #desplegar que hace la funcion
    print('Esta función despliega los numeros de iN a 1 ')
    #leer la cantidad
    print('Teclea el valor:', end='')
    iN = int(input())
    # 1. Inicializar la vcc antes del ciclo
    iK = iN
    # 2. Incluir en la condición la vcc
    while iK >= 1:
        # Bloque de instrucciones del while
        # Delimitadas por la indentación
        print(iK)  
        # 3. Actualizar iK
        iK = iK - 1
def ciclo_contador_decreciente_for():
    #desplegar que hace la funcion
    print('Esta función despliega los numeros de iN a 1 ')  
    #leer la cantidad
    print('Teclea el valor:', end='')
    iN = int(input())
    # 2. Incluir en la condición la vcc
    for i in range(iN, 0, -1):
        # Bloque de instrucciones del while
        # Delimitadas por la indentación
        print(i)
       
#///////////////////////////////////////////////alcancia////////////////////////////////////////////////////////////////////////        
def alcancia():
    #leer la cantidad 
    print('Cantidad de valores a sumar:')
    iN = int(input())
    # 1. Inicializar la vcc antes del ciclo
    iAcum = 0
    iK = 1
    # 2. Incluir en la condición la vcc
    while iK <= iN:
        # Acumular el iK en iAcum
        iAcum = iAcum + iK
        # 3. Actualizar iK
        iK = iK +1
    print('El total $', iAcum)
def alcancia_for():
    #leer la cantidad 
    print('Cantidad de valores a sumar:')
    iN = int(input())
    # 1. Inicializar la vcc antes del ciclo
    iAcum = 0
    # 2. Incluir en la condición la vcc
    for i in range(iN):
        # Acumular el iK en iAcumt
        num = int(input())
        iAcum = iAcum + num
    print('El total $', iAcum)

#///////////////////////////////////////////////chonita////////////////////////////////////////////////////////////////////////
def tienda_chonita_for():
    print('Calcular el total a pagar:')
    print('Teclea la camtidad de productos:')
    iN = int(input())
    # 1: Inicializar acumulador y vcc
    dAcum = 0
    # 2. Incluir en la condicion la vcc
    for i in range(1, iN + 1):
        #Teclea el precio
        print('Teclea el precio', i, ': ', end='')
        dPrecio = float(input())
        # Acumular el iK en iAcum
        dAcum = dAcum + dPrecio
    #Desplegar los resultados
    print('Total a pagar $', dAcum)
    
#///////////////////////////////////////////////elevado////////////////////////////////////////////////////////////////////////
def elevado():
    print('Esta función eleva x^n')
    #leer x y n
    iN = int(input('Teclea el exponente n:'))
    iX = int(input('Teclea el valor de x:'))
    # Inicializar acumulador y contador
    iAcum = 1
    iK = 1
    while iK <= iN:
        iAcum = iAcum * iX
        iK = iK + 1
    print(f'{iX}^{iN}={iAcum}')
def elevado_for():
    print('Esta función eleva x^n')
    #leer x y n
    iN = int(input('Teclea el exponente n:'))
    iX = int(input('Teclea el valor de x:'))
    # Inicializar acumulador y contador
    iAcum = 1
    for i in range(iN):
        iAcum = iAcum * iX
    print(f'{iX}^{iN}={iAcum}')
    
    
    
#///////////////////////////////////////////////cuenta_ PNC////////////////////////////////////////////////////////////////////////
def cuenta_pnc(iN):
    # Inicializar contador y acumuladores
    iK = 1
    cc = 0
    cn = 0
    cp = 0
    while iK <= iN:
        #leer valor
        iV = int(input('Ingresa un número'))
        #checar si es negativo, cero o positivo
        if iV > 0:
            cp = cp +1
        elif iV < 0:
            cn = cn + 1
        else:
            cc = cc + 1
        iK = iK + 1
    print(f'positivos={cp}\nnegativos={cn}\nceros={cc}')
def cuenta_pnc_for(iN):
    # Inicializar contador y acumuladores
    cc = 0
    cn = 0
    cp = 0
    for i in range(iN):
        #leer valor
        iV = int(input('Ingresa un número'))
        #checar si es negativo, cero o positivo
        if iV > 0:
            cp = cp +1
        elif iV < 0:
            cn = cn + 1
        else:
            cc = cc + 1
    print(f'positivos={cp}\nnegativos={cn}\nceros={cc}')
    
    
    
#///////////////////////////////////////////////multiplicar////////////////////////////////////////////////////////////////////////
def multiplicar(iN):
    #inicializar iK
    iK = 10
    while iK >= 1:        
        #realizar e imprimir operacion
        print(f'{iN}x{iK}={iN*iK}')
        # Actulizar valor de iK
        iK = iK - 1
def multiplicar_for(iN):
    #inicializar iK
    iK = 10
    for i in range(10, 0, -1):   
        #realizar e imprimir operacion
        print(f'{iN}x{i}={iN*i}')
        

#///////////////////////////////////////////////promedio////////////////////////////////////////////////////////////////////////
def promedio(iN):
    #inicializar iK
    iK = 1
    acum = 0
    prom = 0
    while iK <= iN:
        #leer numero
        num = int(input())
        #realizar e imprimir operacion
        acum = acum + num
        prom = acum / iK
        # Actulizar valor de iK
        iK = iK + 1
    print(prom)
        
#///////////////////////////////////////////////tiofibo////////////////////////////////////////////////////////////////////////        
def tioFibo(iN):
    # Inicializar variables
    suma = 1
    firstNumber = 0
    secondNumber = 1
    count = 1
    #checar que se número válido
    if iN > 0:
        #checar si es 1 o 2
        if iN == 1:
            print('0')
        elif iN == 2:
            print('0, 1')
        else:
            #imprimir primeros dos números
            print('0, 1, ', end='')
            #hacer cálculo de todos los demás números
            while count < (iN - 2):
                suma = firstNumber + secondNumber
                firstNumber = secondNumber
                secondNumber = suma
                count = count + 1
                print(suma, ', ', end='')
            #hacer un último calculo con el propósito de que no salga con coma
            suma = firstNumber + secondNumber
            print(suma)
    else:
        print('enter valid number')

def tioFibo_for(iN):
    # Inicializar variables
    suma = 1
    firstNumber = 0
    secondNumber = 1
    count = 1
    #checar que se número válido
    if iN > 0:
        #checar si es 1 o 2
        if iN == 1:
            print('0')
        elif iN == 2:
            print('0, 1')
        else:
            #imprimir primeros dos números
            print('0, 1, ', end='')
            #hacer cálculo de todos los demás números
            for i in range(iN-3):
                suma = firstNumber + secondNumber
                firstNumber = secondNumber
                secondNumber = suma
                print(suma, ', ', end='')
            #hacer un último calculo con el propósito de que no salga con coma
            suma = firstNumber + secondNumber
            print(suma)
    else:
        print('enter valid number')
    
#///////////////////////////////////////////////adivina////////////////////////////////////////////////////////////////////////
def adivina(iN):
    # Inicializar variables
    count = 0
    serie = 8
    numeros = ""
    #hacer calculo de la serie
    while count < iN:
        serie = serie + count
        count = count + 1
        #imprimir cada elemento
        numeros = numeros + str(serie) + ","
    #leer número del usuario
    userNum = int(input())
    #checar si acertó o no
    while userNum != (serie + count):
         userNum = int(input())
    print(numeros + "?Felicidades")
    
def adivina_for(iN):
    # Inicializar variables
    serie = 8
    numeros = ""
    #hacer calculo de la serie
    for i in range(0, iN):
        serie = serie + i
        #imprimir cada elemento
        numeros = numeros + str(serie) + ","
    #leer número del usuario
    userNum = int(input())
    #checar si acertó o no
    while userNum != (serie + (i + 1)):
         userNum = int(input())
    print(numeros + "?Felicidades")
    
#///////////////////////////////////////////////aproximacion de pi////////////////////////////////////////////////////////////////////////
def aproximacionDePi(iN):
    #inicializar varibales
    acum = 1
    count = 1
    num1 = -1
    num2 = 3
    #hacer cálculo para obtener valor de acum
    while count < iN:
        acum = acum + (num1 / num2)
        num1 = num1 * -1
        num2 = num2 + 2
        count = count + 1
    #sacar valor de acum final
    acum = acum * 4
    #imprimir resultado
    print(f'La aproximación de Pi es: {acum}')
    
def aproximacionDePi_for(iN):
    #inicializar varibales
    acum = 1
    num1 = -1
    num2 = 3
    #hacer cálculo para obtener valor de acum
    for i in range(iN - 1):
        acum = acum + (num1 / num2)
        num1 = num1 * -1
        num2 = num2 + 2
    #sacar valor de acum final
    acum = acum * 4
    #imprimir resultado
    print(f'La aproximación de Pi es: {acum}')
    
        
#///////////////////////////////////////////////numero mayor////////////////////////////////////////////////////////////////////////
def mayor_for(iN):
    numMayor = -sys.maxsize-1
    for i in range(1, iN + 1):
        num = int(input(f'Ingresa el valor {i}:'))
        if num > numMayor:
            numMayor = num
    print(numMayor)
#///////////////////////////////////////////////pastel////////////////////////////////////////////////////////////////////////
def pastel():
    ren = int(input())
    col = int(input())
     #con python
    for i in range (1, ren + 1):
        print('*' * col)
    #con los demas
    print()
    for i in range (1, ren + 1):
        for i in range(1, col + 1):
            print('*', end='')
        print()
#///////////////////////////////////////////////triangulo////////////////////////////////////////////////////////////////////////
def triangulo():
    ren = int(input())
    for i in range (1, ren + 1):
        print('*' * i)
#///////////////////////////////////////////////pirámide////////////////////////////////////////////////////////////////////////
def piramide():
    ren = int(input())
    for i in range(1, ren + 1):
        print(' ' * (ren - i) + '*' * i + '*' * (i -1))
    
        
def menu():
    print('''1. Ciclo creciente
2. Ciclio decreciente
3. Alcancia
4. Tiendita dona Chonita
5. Elevar x^n
6. cuenta PNC
7. multiplicar
8. promedio
9. Fibonacci
10. Adivina
11. AproxDePi

For:
12. Mayor
13. creciente
14. decreciente
15. alcancia
16. chonita
17. elevado
18. pnc
19. multiplicar
20. pastel
21. triangulo
22. piramide
23. fibo
24. Aprox de pi
25. Adivina
0. Terminar
''')
    return int(input())

def main():
    #leer la opcion del menu
    opcion = menu()
    while opcion != 0:
        if opcion == 1:
            ciclo_contador_creciente()
        elif opcion == 2:
            ciclo_contador_decreciente()
        elif opcion == 3:
            alcancia()
        elif opcion == 4:
            tienda_chonita()
        elif opcion == 5:
            elevado()
        elif opcion == 6:
            iN = int(input('Introduce la cantidad de numeros: '))
            cuenta_pnc(iN)
        elif opcion == 7:
            iN = int(input('Introduce un numero: '))
            multiplicar(iN)
        elif opcion == 8:
            iN = int(input('Introduce la cantidad de numeros: '))
            promedio(iN)
        elif opcion == 9:
            iN = int(input('Introduce la cantidad de numeros: '))
            tioFibo(iN)
        elif opcion == 10:
            iN = int(input('Introduce la cantidad de numeros: '))
            adivina(iN)
        elif opcion == 11:
            iN = int(input('Introduce la cantidad de numeros de aproximación: '))
            aproximacionDePi(iN)
        elif opcion == 12:
            iN = int(input('Introduce la cantidad de numeros: '))
            mayor_for(iN)
        if opcion == 13:
            ciclo_contador_creciente_for()
        elif opcion == 14:
            ciclo_contador_decreciente_for()
        elif opcion == 15:
            alcancia_for()
        elif opcion == 16:
            tienda_chonita_for()
        elif opcion == 17:
            elevado_for()
        elif opcion == 18:
            iN = int(input('Introduce la cantidad de numeros: '))
            cuenta_pnc_for(iN)
        elif opcion == 19:
            iN = int(input('Introduce un numero: '))
            multiplicar_for(iN)
        elif opcion == 20:
            pastel()
        elif opcion == 21:
            triangulo()
        elif opcion == 22:
            piramide()
        elif opcion == 23:
            iN = int(input('Introduce la cantidad de numeros: '))
            tioFibo_for(iN)
        elif opcion == 24:
            iN = int(input('Introduce la cantidad de numeros de aproximación: '))
            aproximacionDePi_for(iN)
        elif opcion == 25:
            iN = int(input('Introduce la cantidad de numeros: '))
            adivina_for(iN)
        else:
            print('Error')
        enter = input('Enter para continuar')
        opcion = menu()

#llamar a la funcion main()
main()
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        