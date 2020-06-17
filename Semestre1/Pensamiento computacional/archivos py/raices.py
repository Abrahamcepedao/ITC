#raices
from math import sqrt
dA = float(input())
dB = float(input())
dC = float(input())
if  (dB ** 2) - (4 * dA * dC) < 0:
    dX1 = "ERROR DE EJECUCIÓN"
    dX2 = "ERROR DE EJECUCIÓN"
else:
    dX1 = (-dB + sqrt((dB ** 2) - (4 * dA * dC))) / 2 * dA
    dX2 = (-dB - sqrt((dB ** 2) - (4 * dA * dC))) / 2 * dA   
print(dX1)
print(dX2)
