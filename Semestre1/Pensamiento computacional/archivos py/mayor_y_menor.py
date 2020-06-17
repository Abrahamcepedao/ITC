#Autor - Abraham Cepeda Oseguera A00827666
#Grupo - 11 Campus Monterrey
#Septiembre 23 2019

#import
import sys

#function
def mayor(iN):
    numMenor = sys.maxsize + 1
    numMayor = -sys.maxsize - 1
    
    for i in range(iN):
        num = int(input())
        if num < numMenor:
            numMenor = num
        if num > numMayor:
            numMayor = num
    print(numMayor)
    print(numMenor)
    
#call function
iN = int(input())
if iN > 0:
    mayor(iN)
else:
    print('npv')