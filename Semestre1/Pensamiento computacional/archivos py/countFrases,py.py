def contar_frases():
    phrase = input('type phrase: ')
    word = input('type word: ')
    contador = 0
    pos = 0
    while phrase.find(word, pos) != -1:
            phrase.find(word, pos)
            pos = pos + len(word)
            contador = contador + 1
    return contador
print(contar_frases())