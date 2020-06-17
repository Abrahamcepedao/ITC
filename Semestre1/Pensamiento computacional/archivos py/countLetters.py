def contar_caracteres():
    word = input('teclea nombre: ')
    letter = input('teclea letra: ')
    count = 0
    for i in word:
        if i == letter:
            count = count + 1
    return count
print(contar_caracteres())
