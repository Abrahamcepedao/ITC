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
for i in range(m):
    if letras[0][i] == 'A':
        letras[0][i] = 'B'
for i in range(n):
    if letras[i][0] == 'I':
        letras[i][0] = 'D'
for i in range(n):
    if letras[i][m-1] == 'D':
        letras[i][m-1] = 'I'
for i in range(m):
    if letras[n-1][i] == 'B':
        letras[n-1][i] = 'A'
'''if 'A' in letras[0]:
    letras[0] = [letra.replace('A', 'B') for letra in letras[0]]
if 'B' in letras[n-1]:
    letras[n-1] = [letra.replace('B', 'A') for letra in letras[n-1]]
for i in range(n):
    if letras[i][0] == 'I':
        letras[i][0] = 'D'
    if letras[i][m-1] == 'D':
        letras[i][m-1] = 'I'''
px = 0
py = 0
suma = 0
count = 0
acum_suma = [0]
while count < 5 and suma < 100:
    suma += numeros[py][px]
    acum_suma.append(suma)
    if acum_suma[-2] == acum_suma[-1]:
        count = count + 1
    else:
        count = 0
    numeros[py][px] = 0
    if letras[py][px] == 'A':
        py -= 1
    elif letras[py][px] == 'B':
        py += 1
    elif letras[py][px] == 'D':
        px += 1
    else:
        px -= 1
    if py == 0 and px == 0:
        suma = suma + 100
print(suma)
        
        
        