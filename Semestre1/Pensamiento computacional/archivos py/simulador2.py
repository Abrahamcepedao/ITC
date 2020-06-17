import random
import sys
def create_matrix(ren, col):
    matrix = [[0] * col for i in range(ren)]
    return matrix

def display_matrix(matrix):
    for iR in range(len(matrix)):
        for iC in range(len(matrix[iR])):
            print(f'{matrix[iR][iC]:<5}', end=" ")
        print()
    return matrix
        
def initialize_matrix_5(matrix):
    value = 0
    for iR in range(len(matrix)):
        for iC in range(len(matrix[iR])):
            matrix[iR][iC] = value
            value = value + 5
    return matrix

def initialize_matrix_rand(matrix):
    matrix = [[random.randint(1, 201) for i in range(len(matrix[0]))]  for i in range(len(matrix))]
    return matrix

def sum_matrix(matrix):
    acum = 0
    for iR in range(len(matrix)):
        for iC in range(len(matrix[iR])):
            acum += matrix[iR][iC]
    return acum
    
    
def average_matrix(matrix):
    acum = 0
    count = 0
    for iR in range(len(matrix)):
        count += len(matrix[iR])
        for iC in range(len(matrix[iR])):
            acum += matrix[iR][iC]
    return acum/count

def max_matrix(matrix):
    max_val = -sys.maxsize - 1
    for iR in range(len(matrix)):
        maxx_val = -sys.maxsize - 1
        for iC in range(len(matrix[iR])):
            if matrix[iR][iC] > maxx_val:
                maxx_val = matrix[iR][iC]
                mess = iC + 1
        print(maxx_val, mess)
        if maxx_val > max_val:
            max_val = maxx_val
            emp = iR + 1
            mes = mess
    print(emp, max_val, mes)
    
def min_matrix(matrix):
    min_val = sys.maxsize + 1
    for iR in range(len(matrix)):
        minn_val = sys.maxsize + 1
        for iC in range(len(matrix[iR])):
            if matrix[iR][iC] < minn_val:
                minn_val = matrix[iR][iC]
                mess = iC + 1
        print(minn_val, mess)
        if minn_val < min_val:
            min_val = minn_val
            empl = iR + 1
            mes = mess
    print(empl, min_val, mes)

def christmas_tree(matrix):
    for iR in range(len(matrix)):
        matrix[iR] = (' ' * (len(matrix) - iR) + '*' * (iR + 1) + '*' * iR + ' ' * (len(matrix) - 1))
    for iR in range(len(matrix)):
        for iC in range(len(matrix[iR])):
            print(f'{matrix[iR][iC]}', end=" ")
        print()
            

def menu():
    print('''1. sumar
2. promedio
3. mayor desplegando r,c
4. menor desplegando r,c
5. mayor por renglon
6. menor por renglon
7. inicializar con multiplos de 5
8. inicializar con valores random
9. arbolito navidad
0.Salir''')
    return int(input())

def main():
    matrix = create_matrix(5,5)
    display_matrix(matrix)
    
    option = menu()
    
    while option != 0:
        if option == 1:
            print('The sum =', sum_matrix(matrix))
        elif option == 2:
            print('The average =', average_matrix(matrix))
        elif option == 3:
            max_matrix(matrix)
        elif option == 4:
            min_matrix(matrix)
        elif option == 5:
            pass
        elif option == 6:
            pass
        elif option == 7:
            matrix = initialize_matrix_5(matrix)
            display_matrix(matrix)
        elif option == 8:
            matrix = initialize_matrix_rand(matrix)
            display_matrix(matrix)
        elif option == 9:
            christmas_tree(matrix)
            initialize_matrix_5(matrix)
        else:
            print("Error, non-existent option")
        print(input('Enter to continue'))
        option = menu()

main()