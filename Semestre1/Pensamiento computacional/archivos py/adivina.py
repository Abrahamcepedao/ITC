for i in range(10):
    print(i)
def adivina(iN):
    # Inicializar variables
    count = 0
    serie = 8
    numeros = ""
    #hacer calculo de la serie
    while count < iN:
        serie = serie + count
        count = count + 1
        #imprimir cada elemento
        numeros = numeros + str(serie) + ","
    #leer número del usuario
    userNum = int(input())
    #checar si acertó o no
    while userNum != (serie + count):
         userNum = int(input())
    print(numeros + "?Felicidades")
n = int(input())
adivina(n)

