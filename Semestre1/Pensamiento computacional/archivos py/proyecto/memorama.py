#Proyecto integrador - Memorama
#Abraham Cepeda Oseguera
#A00827666
from random import shuffle
#Create a uni
def create_matrix(x, y):
    numbers = []
    for num in range(int(x*y+1)):
        numbers.append(num % (x*y/2))
    shuffle(numbers)
    create_memorama(numbers,x,y)
    
def create_memorama(numbers,x,y):
    memorama = [[0] * y for _ in range(x)]
    count = -1
    for ex in range(x):
        for ey in range(y):
            count += 1
            memorama[ex][ey] = numbers[count]
    play_memorama(memorama,x,y)
    
def get_number(positions_matrix,x,y,count):
    num = int(input('Player' + str(count) + ': enter the first number (0 - ' + str(x*y-1) + '): '))
    num2 = int(input('Player' + str(count) + ': enter the second number (0 - ' + str(x*y-1) + '): '))
    ren = num // y
    col = num % y
    ren2 = num2 // y
    col2 = num2 % y
    while (num == num2) or (num < 0) or (num2 < 0) or (num > (x*y-1)) or (num2 > (x*y-1)):
        print('Enter valid numbers')
        num = int(input('Player' + str(count) + ': enter the first number (0 - ' + str(x*y-1) + '): '))
        num2 = int(input('Player' + str(count) + ': enter the second number (0 - ' + str(x*y-1) + '): '))
        ren = num // y
        col = num % y
        ren2 = num2 // y
        col2 = num2 % y
    while positions_matrix[ren][col] != '-' or positions_matrix[ren2][col2] != '-':
        print('Number has already been unfold')
        num = int(input('Player' + str(count) + ': enter the first number (0 - ' + str(x*y-1) + '): '))
        num2 = int(input('Player' + str(count) + ': enter the second number (0 - ' + str(x*y-1) + '): '))
        ren = num // y
        col = num % y
        ren2 = num2 // y
        col2 = num2 % y
    return [ren, col, ren2, col2]
    
    
def play_memorama(memorama,x,y):
    positions_matrix = [["-"] * y for _ in range(x)]
    ptsP1 = 0
    ptsP2 = 0
    count = 1
    while any('-' in sublist for sublist in positions_matrix):
        for ex in range(x):
            for ey in range(y):
                print(' ' * 5 + str(positions_matrix[ex][ey]) + ' ' * 5, end="")
            print()
        if count % 2 != 0:
            player_turn = 1
        else:
            player_turn = 2
        ren, col, ren2, col2 = get_number(positions_matrix,x,y,player_turn)
        print(memorama[ren][col], 'and', memorama[ren2][col2])
        if memorama[ren][col] == memorama[ren2][col2]:
            print('You got it right!')
            positions_matrix[ren][col] = memorama[ren][col]
            positions_matrix[ren2][col2] = memorama[ren2][col2]
            if count % 2 != 0:
                ptsP1 = ptsP1 + 1
            else:
                ptsP2 = ptsP2 + 1
        else:
            print('Better luck next time')
        count = count + 1
    if ptsP1 > ptsP2:
        print('Player1 is the winner!!')
    elif ptsP1 < ptsP2:
        print('Player2 is the winner!!')
    else:
        print('It is a tie!')

def main():
    x = int(input("x-axis: "))
    y = int(input("y-axis: "))
    while (x * y) % 2 != 0:
        print("x*y must return an even number")
        x = int(input("x-axis: "))
        y = int(input("y-axis: "))
    create_matrix(x,y)
main()
