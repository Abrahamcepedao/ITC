def adivina(iN):
    # Inicializar variables
    serie = 8
    suma = 0
    numeros = ""
    #hacer calculo de la serie
    for i in range (iN):
        serie = serie + suma
        suma = suma + 1
        #imprimir cada elemento
        numeros = numeros + str(serie) + ","
    #leer número del usuario
    userNum = int(input())
    #checar si acertó o no
    for userNum != (serie + count):
         userNum = int(input())
    print(numeros + "?Felicidades")
n = int(input())
adivina(n)