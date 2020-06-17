#Piedra papel o tijera
import random
playerName = input()
playerNumber = int(input())
computerName = input()
computerNumber = int(input())

    

def despliega_tiro(jugador, tiro):
    if tiro == 1:
        print(jugador + " tiro Piedra")
    elif tiro == 2:
        print(jugador + " tiro Papel")
    else:
       print(jugador + " tiro Tijera")
    
def piedra_papel_tijera(tJ, tC):
    despliega_tiro(playerName, playerNumber)
    despliega_tiro(computerName, computerNumber)
    
    if (tJ == 1 and tC == 3) or (tJ == 2 and tC == 1) or (tJ == 3 and tC == 2):
        print("ganaste")
    elif tJ == 1 and tC == 2 or (tJ == 2 and tC == 3) or (tJ == 3 and tC == 1):
         print("perdiste")
    elif tJ == tC:
        print('empate')
    else:
        print('enter valid numbers')
        
        
piedra_papel_tijera(playerNumber, computerNumber)        
        
