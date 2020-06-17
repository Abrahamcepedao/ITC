#Autor - Abraham Cepeda Oseguera A00827666
#Grupo - 11 Campus Monterrey
#Septiembre 23 2019
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def piramide():
    ren = int(input())
    if ren > 0 and ren < 27:
        print(' '*(ren-1) + 'A')
        for i in range(ren-1):
            word = ''
            word =' ' * (ren - (i+2))
            for j in range(i+2):
                word += letters[j]
            for k in range(i, -1, -1):
                word += letters[k]
            print(word)
    else:
        print('enter valid number')
piramide()
