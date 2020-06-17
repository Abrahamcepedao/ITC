#Hernán Salinas Ibarra - A01570409
#Proyecto Integrador: Memorama
#Temática: Animales en español y alemán

#Crear Matriz Visible (tablero) con 0-35
def crearMatrizVis(ren,col):
    matriz = [[0]*6 for i in range (6)]
    cont = 0
    for iR in range (ren):
        for iC in range (col):
            matriz[iR][iC] = cont
            cont = cont + 1
        print()
    return matriz

#Desplegar Matriz Visible (tablero) en forma de memorama
def desplegarMatrizVis(matriz):
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            print(f'{matriz[iR][iC]:<10}' , end='')
        print()

#Desplegar Matriz Invisible (juego) con nombres de animales en español y alemán en forma de memorama
def desplegarMatrizInv(matriz):
    for iR in range(len(matriz)):
        for iC in range(len(matriz[iR])):
            print(f'{matriz[iR][iC]:<10}' , end='')
        print()
        
#Matriz 2D para elementos del memorama
def crearMatrizInv():
    matriz = [['Gato','Katze', 'Perro', 'Hund', 'Oso',
    'Bär'], ['Caballo','Pferd','Pato','Ente','Tortuga',
    'Schildkröt'],['Leon','Löwe','Elefante','Elefant',
    'Girafa','Giraffe'],['Zorro','Fuchs','Lobo','Wolf',
    'Venado','Hirsch'],['Pescado','Fisch','Pajaro','Vogel',
    'Obeja','Schaf'],['Conejo','Kaninchen','Cerdo',
    'Schwein','Gallina','Huhn']]
    return matriz

#Revolver las cartas
def revolverMatrizInv(matrizInv):
    import random
    random.shuffle(matrizInv)
    for sublist in matrizInv:
        random.shuffle(sublist)
    print ("Cartas Revueltas")
    return matrizInv

#Leer tiro 1 del jugador 1
def leerTiro1(matrizVis, matrizInv,puntos1,jugador1):
    if matrizVis == matrizInv: #En caso de que ya se descubrieron todas las cartas
        print("Juego finalizado, presione 0 para conocer el ganador")
        return matrizVis,puntos1
    
    else: #Para desplegar Matriz Visible (tablero)
        for iR in range(len(matrizVis)):
            for iC in range(len(matrizVis[iR])):
                print(f'{matrizVis[iR][iC]:<10}' , end='')
            print()
        print(jugador1, "a escoger")
        print("Cantidad de puntos para", jugador1, ":" , puntos1)
        tiro1 = int(input("Tiro 1: "))
        tiro2 = int(input("Tiro 2: "))
        
        if (tiro1 > 35 or tiro1 <0) or (tiro2 >35 or tiro2<0): #Escoger cartas dentro del memorama
            print("Carta no existente. Vuelve a escoger cartas dentro del memorama")
            leerTiro1(matrizVis, matrizInv,puntos1,jugador1)
            
        else: #Cambiar renglones y columnas a solo un numero
            ren1 = tiro1//6
            col1= tiro1%6
            ren2 = tiro2//6
            col2 = tiro2%6
            pos1 = matrizInv[ren1][col1]
            pos2 = matrizInv[ren2][col2]
        
            if pos1 == pos2: #Prohibir la misma carta, empezar el tiro de nuevo
                print("No se puede escoger la misma carta, intenta de nuevo")
                leerTiro1(matrizVis, matrizInv,puntos1,jugador1)
                
            else: #Prohibir carta ya descubierta, empezar el tiro de nuevo
                if (pos1 == matrizVis[ren1][col1] or pos1 == matrizVis[ren2][col2]) or (pos2 == matrizVis[ren1][col1] or pos2 == matrizVis[ren2][col2]):
                    print("Esta carta ya ha sido descubierta, seleccione otra vez")
                    leerTiro1(matrizVis, matrizInv,puntos1,jugador1)
                else: #En caso de que tiro sea acertado, sumar punto y volver a tirar
                    
                    if (pos1 == 'Gato' or pos1 == 'Katze') and (pos2 == 'Gato' or pos2 == 'Katze') or (pos1 == 'Perro' or pos1 == 'Hund') and (pos2 == 'Perro' or pos2 == 'Hund') or (pos1 == 'Oso' or pos1 == 'Bär') and (pos2 == 'Oso' or pos2 == 'Bär') or (pos1 == 'Caballo' or pos1 == 'Pferd') and (pos2 == 'Caballo' or pos2 == 'Pferd') or (pos1 == 'Pato' or pos1 == 'Ente') and (pos2 == 'Pato' or pos2 == 'Ente') or (pos1 == 'Tortuga' or pos1 == 'Schildkröt') and (pos2 == 'Tortuga' or pos2 == 'Schildkröt') or (pos1 == 'Leon' or pos1 == 'Löwe') and (pos2 == 'Leon' or pos2 == 'Löwe') or (pos1 == 'Elefante' or pos1 == 'Elefant') and (pos2 == 'Elefante' or pos2 == 'Elefant') or (pos1 == 'Girafa' or pos1 == 'Giraffe') and (pos2 == 'Girafa' or pos2 == 'Giraffe') or (pos1 == 'Zorro' or pos1 == 'Fuchs') and (pos2 == 'Zorro' or pos2 == 'Fuchs') or (pos1 == 'Lobo' or pos1 == 'Wolf') and (pos2 == 'Lobo' or pos2 == 'Wolf') or (pos1 == 'Venado' or pos1 == 'Hirsch') and (pos2 == 'Venado' or pos2 == 'Hirsch') or (pos1 == 'Pescado' or pos1 == 'Fisch') and (pos2 == 'Pescado' or pos2 == 'Fisch') or (pos1 == 'Pajaro' or pos1 == 'Vogel') and (pos2 == 'Pajaro' or pos2 == 'Vogel') or (pos1 == 'Obeja' or pos1 == 'Schaf') and (pos2 == 'Obeja' or pos2 == 'Schaf') or (pos1 == 'Conejo' or pos1 == 'Kaninchen') and (pos2 == 'Conejo' or pos2 == 'Kaninchen') or (pos1 == 'Cerdo' or pos1 == 'Schwein') and (pos2 == 'Cerdo' or pos2 == 'Schwein') or (pos1 == 'Gallina' or pos1 == 'Huhn') and (pos2 == 'Gallina' or pos2 == 'Huhn'):
                        matrizVis[ren1][col1] = matrizInv [ren1][col1]
                        matrizVis[ren2][col2] = matrizInv [ren2][col2]
                        desplegarMatrizVis(matrizVis)
                        print("Correcto, selecciona otro par")
                        puntos1 = puntos1 + 1
                        leerTiro1(matrizVis,matrizInv,puntos1,jugador1)
                
                    else: #En caso de que tiro sea errado, se despliega los elementos y se acaba el turno
                        puntos1 = puntos1 + 0
                        y = matrizVis[ren1][col1]
                        z = matrizVis[ren2][col2]
                        matrizVis[ren1][col1] = matrizInv [ren1][col1]
                        matrizVis[ren2][col2] = matrizInv [ren2][col2]
                        for iR in range(len(matrizVis)):
                            for iC in range(len(matrizVis[iR])):
                                print(f'{matrizVis[iR][iC]:<10}' , end='')
                            print()
                        print("Incorrecto")
                        matrizVis[ren1][col1] = y
                        matrizVis[ren2][col2] = z
                    #retornar Matriz Visible (tablero) y puntos para el jugador 2   
                    return matrizVis, puntos1
        
def leerTiro2(matrizVis, matrizInv,puntos2,jugador2):
    if matrizVis == matrizInv: #En caso de que ya se descubrieron todas las cartas
        print("Juego finalizado, presione 0 para conocer el ganador")
        return matrizVis,puntos2
    
    else: #Para desplegar Matriz Visible (tablero)
        for iR in range(len(matrizVis)):
            for iC in range(len(matrizVis[iR])):
                print(f'{matrizVis[iR][iC]:<10}' , end='')
            print()
        print(jugador2, "a escoger")
        print("Cantidad de puntos para", jugador2,":", puntos2)
        tiro1 = int(input("Tiro 1: "))
        tiro2 = int(input("Tiro 2: "))
        
        if (tiro1 > 35 or tiro1 <0) or (tiro2 >35 or tiro2<0): #Escoger cartas dentro del memorama
            print("Carta no existente. Vuelve a escoger cartas dentro del memorama")
            leerTiro2(matrizVis, matrizInv,puntos2,jugador2)
        else: #Cambiar renglones y columnas a solo un numero
            ren1 = tiro1//6
            col1= tiro1%6
            ren2 = tiro2//6
            col2 = tiro2%6
            pos1 = matrizInv[ren1][col1]
            pos2 = matrizInv[ren2][col2]
            
            if pos1 == pos2: #Prohibir la misma carta, empezar el tiro de nuevo
                print("No se puede escoger la misma carta, intenta de nuevo")
                leerTiro2(matrizVis, matrizInv,puntos2,jugador2)
            
            else:
                #Prohibir carta ya descubierta, empezar el tiro de nuevo
                if (pos1 == matrizVis[ren1][col1] or pos1 == matrizVis[ren2][col2]) or (pos2 == matrizVis[ren1][col1] or pos2 == matrizVis[ren2][col2]):
                    print("Esta carta ya ha sido descubierta, seleccione otra vez")
                    leerTiro2(matrizVis, matrizInv,puntos2,jugador2)
                else:
                    #En caso de que tiro sea acertado, sumar punto y volver a tirar
                    if (pos1 == 'Gato' or pos1 == 'Katze') and (pos2 == 'Gato' or pos2 == 'Katze') or (pos1 == 'Perro' or pos1 == 'Hund') and (pos2 == 'Perro' or pos2 == 'Hund') or (pos1 == 'Oso' or pos1 == 'Bär') and (pos2 == 'Oso' or pos2 == 'Bär') or (pos1 == 'Caballo' or pos1 == 'Pferd') and (pos2 == 'Caballo' or pos2 == 'Pferd') or (pos1 == 'Pato' or pos1 == 'Ente') and (pos2 == 'Pato' or pos2 == 'Ente') or (pos1 == 'Tortuga' or pos1 == 'Schildkröt') and (pos2 == 'Tortuga' or pos2 == 'Schildkröt') or (pos1 == 'Leon' or pos1 == 'Löwe') and (pos2 == 'Leon' or pos2 == 'Löwe') or (pos1 == 'Elefante' or pos1 == 'Elefant') and (pos2 == 'Elefante' or pos2 == 'Elefant') or (pos1 == 'Girafa' or pos1 == 'Giraffe') and (pos2 == 'Girafa' or pos2 == 'Giraffe') or (pos1 == 'Zorro' or pos1 == 'Fuchs') and (pos2 == 'Zorro' or pos2 == 'Fuchs') or (pos1 == 'Lobo' or pos1 == 'Wolf') and (pos2 == 'Lobo' or pos2 == 'Wolf') or (pos1 == 'Venado' or pos1 == 'Hirsch') and (pos2 == 'Venado' or pos2 == 'Hirsch') or (pos1 == 'Pescado' or pos1 == 'Fisch') and (pos2 == 'Pescado' or pos2 == 'Fisch') or (pos1 == 'Pajaro' or pos1 == 'Vogel') and (pos2 == 'Pajaro' or pos2 == 'Vogel') or (pos1 == 'Obeja' or pos1 == 'Schaf') and (pos2 == 'Obeja' or pos2 == 'Schaf') or (pos1 == 'Conejo' or pos1 == 'Kaninchen') and (pos2 == 'Conejo' or pos2 == 'Kaninchen') or (pos1 == 'Cerdo' or pos1 == 'Schwein') and (pos2 == 'Cerdo' or pos2 == 'Schwein') or (pos1 == 'Gallina' or pos1 == 'Huhn') and (pos2 == 'Gallina' or pos2 == 'Huhn'):
                        matrizVis[ren1][col1] = matrizInv [ren1][col1]
                        matrizVis[ren2][col2] = matrizInv [ren2][col2]
                        desplegarMatrizVis(matrizVis)
                        print("Correcto, selecciona otro par")
                        puntos2 = puntos2 + 1
                        leerTiro2(matrizVis,matrizInv,puntos2,jugador2)
                        
                    else:
                        #En caso de que tiro sea errado, se despliega los elementos y se acaba el turno
                        puntos2= puntos2 + 0
                        y = matrizVis[ren1][col1]
                        z = matrizVis[ren2][col2]
                        matrizVis[ren1][col1] = matrizInv [ren1][col1]
                        matrizVis[ren2][col2] = matrizInv [ren2][col2]
                        for iR in range(len(matrizVis)):
                            for iC in range(len(matrizVis[iR])):
                                print(f'{matrizVis[iR][iC]:<10}' , end='')
                            print()
                        print("Incorrecto")
                        matrizVis[ren1][col1] = y
                        matrizVis[ren2][col2] = z
                    #retornar Matriz Visible (tablero) y puntos para el jugador 2
                    return matrizVis,puntos2
        
def menu(matrizVis,matrizInv): #Menu
    print("¡Bienvenidos al memorama de animales en español y alemán!")
    print ("El objetivo es que aprendan el vocabulario mientras entrenan su cerebro y se divierten.")
    print ("Favor de ingresar sus nombres para continuar...")
    #Nombres de los jugadores
    jugador1 = input("Nombre del jugador 1: ")
    jugador2 = input("Nombre del jugador 2: ")
    print ("Ingresa |1| para desplegar tablero")
    print ("Ingresa |2| para desplegar juego")
    print ("Ingresa |3| para revolver cartas")
    print ("Ingresa |4| para leer tiros del jugador")
    opcion = int(input("Selecciona |3| para revolver las veces que quieras y |4| para empezar: "))
    #Inicializar los puntos para cada jugador
    puntos1 = 0
    puntos2 = 0
    #Ciclo centinela para terminar cuando sea 0
    while opcion != 0:
        if opcion == 1:
            #Desplegar Matriz Visible (tablero)
            desplegarMatrizVis(matrizVis)
        elif opcion == 2:
            #Desplegar Matriz Invisible (juego)
            desplegarMatrizInv(matrizInv)
        elif opcion == 3:
            #Revolver cartas de la Matriz Invisible
            matrizInv = revolverMatrizInv(matrizInv)
        elif opcion == 4:
            #Leer Tiros de los jugadores para modificar la matriz Visible
            matrizVis, puntos1 = leerTiro1(matrizVis,matrizInv,puntos1,jugador1)
            matrizVis, puntos2 = leerTiro2(matrizVis,matrizInv,puntos2,jugador2)
        #Actualizar variable controladora del ciclo centinela
        opcion = int(input("Quieres seguir jugando? Selecciona |4| para seguir, |0| para terminar: "))
    #Finalizar juego en caso de 0
    print ("Juego finalizado")
    
    #Determinar ganador por puntos o empate
    if puntos1>puntos2:
        print (jugador1, "ha ganado con", puntos1, "puntos")
    elif puntos1<puntos2:
        print (jugador2, "ha ganado con", puntos2, "puntos")
    else:
        print ("Empate con" , puntos1 , "puntos cada jugador")
    #Opcion para empezar de nuevo
    jugardeNuevo = int(input("Presione |1| para jugar de nuevo, |2| para terminar el programa: "))
    
    #Reiniciar programa en caso de 1
    if jugardeNuevo == 1:
        main()
    #Finalizar programa en caso de 2    
    else:
        print ("Fin del programa, ¡Gracias por jugar!")
                       
    #main, para crear matrices Visible (tablero) y Invisible (juego)
def main():
    matrizVis = crearMatrizVis (6,6)
    matrizInv = crearMatrizInv()
    #Ir al menu con Matriz Visible (tablero) y Matriz Invisible (juego)
    menu (matrizVis,matrizInv)

#Llamar a la función main para empezar el programa
main()