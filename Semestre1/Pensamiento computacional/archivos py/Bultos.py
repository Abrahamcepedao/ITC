#Rollos de fresa
import math
print('Introduce los metros de fresa')
metros = float(input())
bulto = math.ceil(metros*35/10.0)
kgSobrantes = float(bulto * 10 - (metros*35))
print(bulto, "Bultos")
print(kgSobrantes, "Kg sobrantes")