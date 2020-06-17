n = int(input())
lista_fichas = list(map(int,input().split()))
lista_pares = []
lista_nones = []
lista_suma = [] 
if len(lista_fichas) == 1:
    if lista_fichas[0] % 2 == 0:
        print(0)
    else:
        print(lista_fichas[0])
elif len(lista_fichas) == 2:
    if lista_fichas[0] % 2 == 0:
        if lista_fichas[1] % 2 == 0:
            print(0)
        elif lista_fichas[1] % 2 != 0:
            print(lista_fichas[1])
    else:
        if lista_fichas[1] % 2 == 0:
            print(lista_fichas[0])
        else:
            print(0)
else:
    for i in range(len(lista_fichas)):
        if lista_fichas[i] % 2 == 0:
            lista_pares.append(lista_fichas[i])
        else:
            lista_nones.append(lista_fichas[i])
    for i in range(len(lista_pares)):
        for j in range(len(lista_nones)):
            lista_suma.append(lista_pares[i] + lista_nones[j])
    lista_suma.sort()
    print(lista_suma[len(lista_suma) - 1])
