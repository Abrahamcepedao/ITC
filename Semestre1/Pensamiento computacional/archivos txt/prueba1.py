'''
Realiza la siguiente secuencia de acciones en un programa


'''

def archivitos():
    #Crea una lista de palabras (cada palabra es introducida por el usuario)
    lista = []
    
    #Leer la cantidad de palabras
    iN = int(input("Cantidad de palabras a ingresar:"))
    
    for iK in range(1, iN + 1):
        palabrita = input(f'Teclea la palabra {iK}:')
        lista.append(palabrita)
    print(lista)
    with open("palabras.txt", "w") as archivo:
        for palabrita in lista:
#            archivo.write(palabrita)
            #print(palabrita, file = archivo)
            
    lista = []
    
    with open('palabras.txt', 'r') as archivo:
        for linea in archivo:
            lista.append(linea[:-1])
            
    print(lista)
    lista.sort()
    print('lista en forma ascendente')
    print(lista)
    lista.sort(reverse = True)
    print('lista en forma descendente')
    print(lista)
    
    #guardar palabras ordenadas
    with open('palabras.txt', 'w') as archivo:
        for palabra in lista:
            archivo.write(palabra + '\n')
    
    lista = []
    
    #leer archivo y guardar datos en lista
    with open('palabras.txt' , 'r') as archivo:
        for linea in archivo: #linea tiene \n
            lista.append(linea[:-1])
            
    print(lista)
    lista.sort(key = str.lower)
    print(lista)

            
archivitos()