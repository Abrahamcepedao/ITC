n, m = input().split()
n = int(n)
m = int(m)
numeros = []
for i in range(n):
    lista_numeros = list(map(int,input().split()))
    numeros.append(lista_numeros)
letras = []
for i in range(n):
    lista_letras = list(map(str,input().split()))
    letras.append(lista_letras)
px, py, suma = 0, 0, 0
while numeros[py][px] != 0:
    suma += numeros[py][px]
    numeros[py][px] = 0
    if letras[py][px] == 'A':
        if py == 0:
            py += 1
        else:
            py -= 1
    elif letras[py][px] == 'B':
        if py == n-1:
            py -= 1
        else:
            py += 1
    elif letras[py][px] == 'D':
        if px == m-1:
            px -= 1
        else:
            px += 1
    else:
        if px == 0:
            px += 1
        else:
            px -= 1  
if py == 0:
    if px == 0:
        suma = suma + 100
print(suma)
