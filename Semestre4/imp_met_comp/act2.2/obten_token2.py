# -*- coding: utf-8 -*-

# Implementación de un scanner mediante la codificación de un Autómata
# Finito Determinista como una Matríz de Transiciones
# Autor: Dr. Santiago Conant, Agosto 2014 (modificado en Agosto 2015)

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
CMC = 109  # comillas cierran
BLC = 110  # caracter booleano (t/f)
OPB = 111
ERR = 200  # Error léxico: palabra desconocida
ERS = 201  # Error sintactico: palabra desconocida


# Matriz de transiciones: codificación del AFD
# [renglón, columna] = [estado no final, transición]
# Estados > 99 son finales (ACEPTORES)
# Caso especial: Estado 200 = ERROR
#       dig   #    (    )  raro  esp  $    “     ” BUlCHAR Char
MT = [[  1,   5, LRP, RRP,   7,   0, END,   3, ERR,   2,   2], # edo 0 - estado inicial
      [  1, ERR, INT, INT, ERR, INT, INT, ERR, ERR, ERR, ERR], # edo 1 - dígitos enteros
      [ERR, ERR, ATO, ATO, ERR, ATO, ATO, ERR, ERR,   2,   2], # edo 2 - atomo
      [  3, ERR, ERR, ERR, ERR,   3, ERR, ERR,   4,   3,   3], # edo 3 - string first part
      [ERR, ERR, ERR, STR, ERR, STR, STR, ERR, ERR, ERR, ERR], # edo 3 - string second part
      [ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR, ERR,   6, ERR], # edo 5 - boolean first part
      [ERR, ERR, ERR, BUL, ERR, BUL, BUL, ERR, ERR, ERR, ERR], # edo 5 - boolean second part
      [ERR, ERR, ERR, ERR,   4, ERR, ERR, ERR, ERR, ERR, ERR], # edo 6 - error lexico
      [ERR, ERR, ERR, ERR,   4, ERR, ERR, ERR, ERR, ERR, ERR]] # edo 6 - error sintactico

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
            #print("read: ", _c)
            if edo < 100 and edo != 0: lexema += _c
        if edo == INT:    
            _leer = False # ya se leyó el siguiente caracter
            print("Entero", lexema)
            return INT
        elif edo == ATO:   
            _leer = False # ya se leyó el siguiente caracter
            print("Atomo", lexema)
            return ATO
        elif edo == STR:   
            _leer = False # ya se leyó el siguiente caracter
            print("String", lexema)
            return STR
        elif edo == BUL:   
            _leer = False # ya se leyó el siguiente caracter
            print("Booleano", lexema)
            return BUL
        elif edo == LRP:   
            lexema += _c  # el último caracter forma el lexema
            print("Delimitador", lexema) 
            return LRP
        elif edo == RRP:  
            lexema += _c  # el último caracter forma el lexema
            print("Delimitador", lexema)
            return RRP
        elif edo == END:
            print("Fin de expresion")
            return END
        else:   
            leer = False # el último caracter no es rar
            print("ERROR! palabra ilegal", lexema)
            return ERR
            
        
    

