# Scanner - Actividad Integradora 3.2 Resaltador de sitaxis (evidencia de competencia)
# Autor: Abraham Cepeda Oseguera, Viernes 16 de abril del 2021

import sys

# tokens
INT = 100  # Número entero
LRP = 103  # Delimitador: paréntesis izquierdo
RRP = 104  # Delimitador: paréntesis derecho
END = 105  # Fin de la entrada
STR = 106  # Letter
BUL = 107  # (#) para leer booleanos
ATO = 108  # atomo
CMO = 109  # comillas abren
CMC = 110  # comillas cierran
BLC = 111  # caracter booleano (t/f)
ERR = 200  # Error léxico: palabra desconocida


# Matriz de transiciones: codificación del AFD
# [renglón, columna] = [estado no final, transición]
# Estados > 99 son finales (ACEPTORES)
# Caso especial: Estado 200 = ERROR
#       dig   #    (    )  raro  esp  $    “     ” BUlCHAR Char
MT = [[  1,   5, LRP, RRP,   7,   0, END,   3, ERR,   2,   2], # edo 0 - estado inicial
      [  1, ERR, INT, INT, ERR, INT, INT, ERR, ERR, ERR, ERR], # edo 1 - dígitos enteros
      [ERR, ERR, ATO, ATO, ERR, ATO, ATO, ERR, ERR,   2,   2], # edo 2 - atomo
      [  3, ERR, ERR, ERR, ERR,   3, ERR, ERR,   4,   3,   3], # edo 3 - string first part
      [ERR, ERR, ERR, STR, ERR, STR, STR, ERR, ERR, ERR, ERR], # edo 4 - string second part
      [ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR,   6, ERR], # edo 5 - boolean first part
      [ERR, ERR, ERR, BUL, ERR, BUL, BUL, ERR, ERR, ERR, ERR], # edo 6 - boolean second part
      [ERR, ERR, ERR, ERR,   7, ERR, ERR, ERR, ERR, ERR, ERR]] # edo 7 - error lexico 

#alfabeto
LETTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
#numeros
NUMBERS = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']

# Filtro de caracteres: regresa el número de columna de la matriz de transiciones
# de acuerdo al caracter dado
def filtro(c):
    """Regresa el número de columna asociado al tipo de caracter dado(c)"""
    if c in NUMBERS: # dígitos
        return 0
    elif c == '#': # booleano
        return 1
    elif c == '(': # delimitador (
        return 2
    elif c == ')': # delimitador )
        return 3
    elif c == ' ' or ord(c) == 9 or ord(c) == 10 or ord(c) == 13 or c == "\n": # blancos
        return 5
    elif c == '$': # fin de entrada
        return 6
    elif c == '“': # apertura comillas
        return 7
    elif c == "”": # cerradura comillas
        return 8
    elif c == 't' or c == 'f': # caracter booleano
        return 9
    elif c in LETTERS: 
        return 10 # caracter de identificador
    else: # caracter raro
        return 4

_c = None    # siguiente caracter
_leer = True # indica si se requiere leer un caracter de la entrada estándar

# Función principal: implementa el análisis léxico
def obten_token():
    """Implementa un analizador léxico: lee los caracteres de la entrada estándar"""
    global _c, _leer
    edo = 0 # número de estado en el autómata
    lexema = "" # palabra que genera el token
    while (True):
        while edo < 100:    # mientras el estado no sea ACEPTOR ni ERROR
            if _leer: _c = sys.stdin.read(1)
            else: _leer = True
            edo = MT[edo][filtro(_c)]
            if edo < 100 and edo != 0: lexema += _c
        if edo == INT:    
            _leer = False # ya se leyó el siguiente caracter
            return (INT, lexema)
        elif edo == ATO:   
            _leer = False # ya se leyó el siguiente caracter
            return (ATO, lexema)
        elif edo == STR:   
            _leer = False # ya se leyó el siguiente caracter
            return (STR, lexema)
        elif edo == BUL:   
            _leer = False # ya se leyó el siguiente caracter
            return (BUL, lexema)
        elif edo == LRP:   
            lexema += _c  # el último caracter forma el lexema
            return (LRP, lexema)
        elif edo == RRP:  
            lexema += _c  # el último caracter forma el lexema
            return (RRP, lexema)
        elif edo == END:
            return (END, "$")
        else:   
            leer = False # el último caracter no es rar
            return (ERR, "ERROR")
            
        
    

