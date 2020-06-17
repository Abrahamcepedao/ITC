#distancia dos puntos
from math import sqrt
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
distancia = float(sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2)))
print(f'distancia={distancia:.2f}')
