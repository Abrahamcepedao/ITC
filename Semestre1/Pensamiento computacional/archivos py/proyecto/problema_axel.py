n = int(input())
lista_fichas = list(map(int,input().split()))
suma = 0
for i in range(n):
    suma += lista_fichas[i]
if suma % 2 != 0:
    print(suma)
else:
    if n > 1:
        count = 0
        lista_fichas.sort()
        for x in range(n):
            if (suma - lista_fichas[x]) % 2 != 0:
                suma = suma - lista_fichas[x]
                break
        
        '''suma = suma - lista_fichas[count]
        while suma % 2 == 0 and count < n -1:
            count += 1
            suma = suma - lista_fichas[count]'''
        if suma % 2 != 0:
            print(suma)
        else:
            print(0)
    else:
        print(0)



'''n = n - 1
lista_fichas.sort()
if len(lista_fichas) == 1:
    if lista_fichas[0] % 2 == 0:
        print(0)
    else:
        print(lista_fichas[0])
elif lista_fichas[n] % 2 == 0:
        num1 = lista_fichas[n]
        while lista_fichas[n-1] % 2 == 0 and n > -1:
            n -= 1
        num2 = lista_fichas[n-1]
        if num2 % 2 == 0:
            print(0)
        else:
            print(num1 + num2)
else:
        num1 = lista_fichas[n]
        while lista_fichas[n-1] % 2 != 0 and n > -1:
            n -= 1
        num2 = lista_fichas[n-1]
        if num2 % 2 != 0:
            print(0)
        else:
            print(num1 + num2)'''