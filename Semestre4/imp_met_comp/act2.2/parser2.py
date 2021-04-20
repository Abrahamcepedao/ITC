# Implementación de un parser
# Reconoce expresiones mediante la gramática:
# EXP -> EXP op EXP | EXP -> (EXP) | cte
# la cual fué modificada para eliminar ambigüedad a:
# EXP  -> cte EXP1 | (EXP) EXP1
# EXP1 -> op EXP EXP1 | vacío
# los elementos léxicos (delimitadores, constantes y operadores)
# son reconocidos por el scanner
#
# Autor: Dr. Santiago Conant, Agosto 2014 (modificado Agosto 2015)

import sys
import obten_token2 as scanner

# Empata y obtiene el siguiente token
def match(tokenEsperado):
    global token
    if token == tokenEsperado:
        token = scanner.obten_token()
    else:
        error("token equivocado")

# Función principal: implementa el análisis sintáctico
def parser():
    global token 
    global count
    count = 0
    token = scanner.obten_token() # inicializa con el primer token
    exp()
    if token == scanner.END:
        print("Expresion bien construida!!")
    else:
        error("expresion mal terminada")

# Módulo que reconoce expresiones
def exp():
    global count
    if token == scanner.INT:
        match(token) # reconoce Constantes
        exp()
    elif token == scanner.ATO:
        match(token)
        exp()
    elif token == scanner.STR:
        match(token)
        exp()
    elif token == scanner.BUL:
        match(token)
        exp()
    elif token == scanner.LRP:
        count = count + 1
        print("count 1", )
        match(token)
        exp()
    elif token == scanner.RRP:
        count = count - 1
        if count < 0:
            error("Orden incorrecto de paréntesis")
        else:
            match(token)
            exp()
    elif token == scanner.END:
        if count != 0:
            error("Orden incorrecto de paréntesis")
        print("Fin de espresion")
    else:
        error("expresion mal iniciada")

# Termina con un mensaje de error
def error(mensaje):
    print("ERROR:", mensaje)
    sys.exit(1)
    
        
parser()
