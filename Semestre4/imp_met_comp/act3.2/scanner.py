# Implementación de un scanner mediante la codificación de un Autómata
# Finito Determinista como una Matríz de Transiciones
# Autor: Dr. Santiago Conant, Agosto 2014 (modificado en Agosto 2015)

import sys

# tokens
INT = 100  # Número entero
FLT = 101  # Número de punto flotante
OPB = 102  # Operador binario
LRP = 103  # Delimitador: paréntesis izquierdo
RRP = 104  # Delimitador: paréntesis derecho
END = 105  # Fin de la entrada
ASG = 106  # Operador de asignación
CMA = 107  # Coma
VAR = 108  # Identificador una sola letra
#VRD = 109   Identificador de varias letras
ERR = 200  # Error léxico: palabra desconocida

# Matriz de transiciones: codificación del AFD
# [renglón, columna] = [estado no final, transición]
# Estados > 99 son finales (ACEPTORES)
# Caso especial: Estado 200 = ERROR
#      dig   op   (    )  raro  esp  .   $    =      ,   CHAR
MT = [[  1, OPB, LRP, RRP,   4,   0, 4, END, ASG,   CMA, 5], # edo 0 - estado inicial
      [  1, INT, INT, INT, INT, INT, 2, INT, INT,   INT, ERR], # edo 1 - dígitos enteros
      [  3, ERR, ERR, ERR,   4, ERR, 4, ERR, ERR,   ERR, ERR], # edo 2 - primer decimal flotante
      [  3, FLT, FLT, FLT, FLT, FLT, 4, FLT, FLT,   FLT, ERR], # edo 3 - decimales restantes flotante
      [ERR, ERR, ERR, ERR,   4, ERR, 4, ERR, ERR,   ERR, ERR], # edo 4 - estado de error
      [  6, VAR, VAR, VAR,   4, VAR, ERR, VAR, VAR, VAR, 6], # edo 5 - primera letra del identificador
      [  6, VAR, VAR, VAR,   4, VAR, ERR, VAR, VAR, VAR, 6]] # edo 6 - Identificador

      # a()

LETTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
NUMBERS = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
# Filtro de caracteres: regresa el número de columna de la matriz de transiciones
# de acuerdo al caracter dado
def filtro(c):
    """Regresa el número de columna asociado al tipo de caracter dado(c)"""
    if c in NUMBERS: # dígitos
        return 0
    elif c == '+' or c == '-' or c == '*' or \
         c == '/': # operadores
        return 1
    elif c == '(': # delimitador (
        return 2
    elif c == ')': # delimitador )
        return 3
    elif c == ' ' or ord(c) == 9 or ord(c) == 10 or ord(c) == 13: # blancos
        return 5
    elif c == '.': # punto
        return 6
    elif c == '$': # fin de entrada
        return 7
    elif c == '=': # asignacion
        return 8
    elif c == ",":
        return 9
    elif c in LETTERS or c == "_": 
        return 10 # caracter de identificador
    else: # caracter raro
        return 4

# Función principal: implementa el análisis léxico
def scanner():
    """Implementa un analizador léxico: lee los caracteres de la entrada estándar"""
    edo = 0 # número de estado en el autómata
    lexema = "" # palabra que genera el token
    tokens = []
    leer = True # indica si se requiere leer un caracter de la entrada estándar
    while (True):
        while edo < 100:    # mientras el estado no sea ACEPTOR ni ERROR
            if leer: c = sys.stdin.read(1)
            else: leer = True
            #print("edo: ", edo)
            edo = MT[edo][filtro(c)]
            #print("c: ", c)
            #print("filtro(C):", filtro(c)) 
            #print("new estado:", edo)
            
            if edo < 100 and edo != 0: lexema += c
            if edo == 200: lexema = c
        if edo == INT:    
            leer = False # ya se leyó el siguiente caracter
            print("Entero", lexema)
        elif edo == FLT:   
            leer = False # ya se leyó el siguiente caracter
            print("Flotante", lexema)
        elif edo == VAR:   
            leer = False # ya se leyó el siguiente caracter
            print("Variable", lexema)
        elif edo == FLT:   
            leer = False # ya se leyó el siguiente caracter
            print("Flotante", lexema)
        elif edo == OPB:   
            lexema += c  # el último caracter forma el lexema
            print("Operador", lexema)
        elif edo == LRP:   
            lexema += c  # el último caracter forma el lexema
            print("Delimitador", lexema) 
        elif edo == ASG:   
            lexema += c  # el último caracter forma el lexema
            print("Asignación", lexema)
        elif edo == RRP:  
            lexema += c  # el último caracter forma el lexema
            print("Delimitador", lexema)
        elif edo == ERR:   
            leer = False # el último caracter no es raro
            print("ERROR! palabra ilegal", lexema)
        tokens.append(edo)
        if edo == END: return tokens
        lexema = ""
        edo = 0
        
scanner()

        
    

