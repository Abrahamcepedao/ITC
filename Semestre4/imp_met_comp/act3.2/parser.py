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
import dominate
from dominate.tags import *
import obten_token as scanner


def createWebpage():
    global items
    global types
    global errorType

    classes = {
        "100": "int",
        "103": "del",
        "104": "del",
        "105": "end",
        "106": "str",
        "107": "bul",
        "108": "ato",
        "200": "err",
    }

    typess = ["atomo", "entero", "string", "booleano", "parentesis", "fin", "error"]

    f = open('resaltador.html', 'w')

    doc = dominate.document(title='Resaltador de syntaxis')

    with doc.head:
        link(rel='stylesheet', href='resalta_sintaxis.css')

    with doc.body:
        with div(id="container").add(div()):
            h1("Resaltador Sintaxis - Abraham Cepeda", cls="title")

        with div(id="container").add(div(id="innerContainer")):
            for i in range(len(typess)):
                with div(id="itemContainer"):
                    div(id="circle", cls=typess[i])
                    h2(typess[i])
            """ with div(id="itemContainer"):
                for i in range(len(typess)):
                    div(id="rectangle", cls=typess[i]) """
            

        if errorType == "":
            with div(id='container').add(p()):
                for i in range(len(items)):
                    span(items[i], cls=classes[str(types[i])])
        else:
            with div(id='container').add(p()):
                span(errorType, cls=classes["200"])

    f.write(str(doc))
    f.close()

# Empata y obtiene el siguiente token
def match(tokenEsperado):
    global token
    global tokenItem
    if token == tokenEsperado:
        tokenData = scanner.obten_token()
        token = tokenData[0]
        tokenItem = tokenData[1]
    else:
        error("token equivocado")

# Función principal: implementa el análisis sintáctico
def parser():
    global token
    global tokenItem 
    global count
    global items
    global types
    global errorType
    items = () #all the words
    types = []  #type of each word
    errorType = ""
    


    count = 0
    tokenData = scanner.obten_token() # inicializa con el primer token
    token = tokenData[0]
    tokenItem = tokenData[1]
    exp()
    if token == scanner.END:
        print("Expresion bien construida!!")
        createWebpage()
    else:
        error("expresion mal terminada")

# Módulo que reconoce expresiones
def exp():
    global count
    global items
    global types
    global errorType
    newList = list(items)
    newList.append(tokenItem)
    items = tuple(newList)

    types.append(token)

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
        match(token)
        exp()
    elif token == scanner.RRP:
        count = count - 1
        if count < 0:
            errorType = ">> ERROR SINTÁCTICO <<"
            error("Orden incorrecto de paréntesis")
        else:
            match(token)
            exp()
    elif token == scanner.END:
        if count != 0:
            errorType = ">> ERROR SINTÁCTICO <<"
            error("Orden incorrecto de paréntesis")
        print("Fin de espresion")
    else:
        errorType = ">> ERROR LEXICO <<"
        error("expresion mal iniciada")

# Termina con un mensaje de error
def error(mensaje):
    createWebpage()
    print("ERROR:", mensaje)
    sys.exit(1)
    
        
parser()
