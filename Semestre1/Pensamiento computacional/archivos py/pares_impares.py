numeros = []
num = input()
while num != "*":
    numeros.append(int(num))
    num = input()
pares = 0
impares = 0
for i in range(len(numeros)):
    if numeros[i] %2==0:
        pares = pares + 1
    elif numeros[i]%2!=0:
        impares= impares +1
print("pares=", pares, "impares=", impares)