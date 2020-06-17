#def leer_matriz():
#    # Lee la cantidad de renglones y columnas en un mismo renglon 
#    lista = input().split()
#    for iR in range(len(lista)):
#        lista[iR] = int(lista[iR])
#    renglones = lista[0]
#    columnas = lista[1]
#
#    # Lee del teclado la matriz
#    matriz = []
#    for iR in range(renglones):
#        # Lee el string y crea una lista de strings
#        lista = input().split()
#        # cada elemento de la lista lo convierte a entero
#        for iC in range(columnas):
#            lista[iC] = int(lista[iC])
#        matriz.append(lista)
#    return matriz
#
#def despliega(matriz):
#    for renglon in matriz:
#        for valor in renglon:
#            print(valor, end = '  ')
#        print( )
#        
#matriz = leer_matriz()
#despliega(matriz)

#Declarar función
#def columna_mayor(matrix):
#    #calcular renglones y colmnas
#    ren = len(matrix)
#    col = len(matrix[0])
#    #inicializar matriz que contendrá los números mayores
#    mayores = []
#    for ey in range(col):
#        #Declarar el primer número de cada columna como el mayor para después compararlos
#        maximo = matrix[0][ey]
#        for ex in range(ren):
#            #Si el número actual es mayor que el máximo se actualiza el valor de máximo
#            if maximo < matrix[ex][ey]:
#                maximo = matrix[ex][ey]
#        mayores.append(maximo)
#    return mayores

def main():
    #recibir dimensiones de la matriz
    r = int(input())
    c = int(input())
    #inicializar matriz con esas dimensiones (puros ceros) para luego cambiar los valores
    matriz = [[0]*c for i in range(r)]
    #for necesario para cambiar valores de cada posición
    for e in range(r):
        for y in range(c):
            matriz[e][y] = int(input())
    #imprimir y llamar funcion columna mayor
    diagonal(matriz, '$)'      
main()


def diagonal(matrix, car):
    #calcular renglones y colmnas
    ren = len(matrix)
    col = len(matrix[0])
    if ren == col:
        for i in range(ren):
            matrix[i][i] = car
    return matrix

matriz = [[4, 5, 7],
                [1, 3, 4],
                [3, 9 ,10]]
print(diagonal(matriz, '$'))
#matrix = [[4, 5, 7, 8],
#                [1, 3, 4, 6],
#                [3, 9 ,10, 5]]
    