n = int(input())
suma = 0
numeros = []
for i in range(n):
    num = int(input())
    suma += num
    numeros.append(num)
promedio = suma // 2
numeros.sort()
cantidad = 0
monedas = 0
count = n-1
while monedas <= promedio:
    monedas = monedas + numeros[count]
    cantidad += 1
    count -= 1
print(cantidad)