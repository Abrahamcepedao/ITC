def crealista():
    respuestas=[]
    for x in range(5):
        palabra= input("")
        respuestas.append(palabra)
    return respuestas

def createxto():
    file = open("Data.txt","r")
    numeros = []
    for x in range(5):
        numeros.append(file.readline())
    file.close()
    return numeros
    
def prom(numeros):
    acum = 0
    for x in range(5):
        acum = acum + int(numeros[x])
        result= acum/5
        resulta=str(result)
    return resulta

def main():
    result=prom(createxto())
    resultad=open("Resultados.txt","w+")
    resultad.write(result)
    resultad.close()
    print(result)
main()