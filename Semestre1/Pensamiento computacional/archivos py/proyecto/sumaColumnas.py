def sumaColumnas():
    ren = int(input())
    col = int(input())
    numeros_matrix = [[0] * col for _ in range(ren)]
    for x in range(ren):
        for y in range(col):
            numeros_matrix[x][y] = int(input())
    suma_matrix = []
    for y in range(col):
        suma = 0
        for x in range(ren):
            suma += numeros_matrix[x][y]
        suma_matrix.append(suma)
    print(suma_matrix)
sumaColumnas()
        
