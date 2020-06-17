#litros pintura
from math import ceil
metrosCuadrados = int(input())
metrosCubridos = int(input())
cantidadLitros = ceil(metrosCuadrados / metrosCubridos)
print(cantidadLitros)