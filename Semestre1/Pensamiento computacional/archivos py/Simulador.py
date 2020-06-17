def crear_matriz(tam_ren, tam_col):
    matriz = [ [0] * tam_col for i in range(tam_ren)]
    return matriz

def desplegar(matriz):
    '''for iR in range(5):
        for iC in range(5):
            print(matriz[iR][iC])
        #salto de renglon
        print()'''
    pass
        
def inicializar(matriz):
    valor = 0
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            matriz[iR][iC] = valor
            valor = valor + 5
    #retornar matriz actualizada
    return matriz

def suma(matriz):
    acumulador = 0
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            acumulador += matriz[iR][iC]
    return acumulador
    
    
def promedio(matriz):
    acumulador = 0
    contador = 0
    for iR in range(len(matriz)):
        contador += len(matriz[iR])
        for iC in range(len(matriz[iR])):
            acumulador += matriz[iR][iC]
    return acumulador/contador


def menu():
    print('''1. sumar
2. promedio
3. mayor desplegando r,c
4. menor desplegando r,c
5. mayor por renglon
6. menor por renglon
7. inicializar con multiplos de 5
8. inicializar con valores random
0.Salir''')
    return int(input())

def main():
    matriz = crear_matriz(5,5)
    print(matriz)
    
    opcion = menu()
    
    while opcion != 0:
        if opcion == 1:
            print('La suma =', suma(matriz))
        elif opcion == 2:
            print('El promedio =', promedio(matriz))
        elif opcion == 3:
            pass
        elif opcion == 4:
            pass
        elif opcion == 5:
            pass
        elif opcion == 6:
            pass
        elif opcion == 7:
            matriz = inicializar(matriz)
            desplegar(matriz)
        elif opcion == 8:
            pass
        else:
            print("Error opcion no existe.")
    
        opcion = menu()

main()