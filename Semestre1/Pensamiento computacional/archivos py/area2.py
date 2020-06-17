#Area de triangulo
from math import sqrt, pi, sin, radians
anguloA = float(input())
anguloB = float(input())
ladoC = float(input())
anguloC = 180 - (anguloA + anguloB)                
radianA = radians(anguloA)
radianB = radians(anguloB)
radianC = radians(anguloC)
ladoA = ladoC * (sin(radianA)/sin(radianC))              
ladoB = ladoC * (sin(radianB)/sin(radianC))
x = (ladoA + ladoB + ladoC) / 2
areaT = sqrt(x * (x - ladoA) * (x - ladoB) * (x - ladoC))
print(areaT)
                
                