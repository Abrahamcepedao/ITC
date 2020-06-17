#Pensamiento computacional

#Porcentajes
print('Teclea cantidad de Hombres:')
cantH = int(input())
print('Teclea cantidad de Mujeres:')
cantM = int(input())
total = cantH + cantM
porcH = total / cantH *100
porcM = total / cantM *100
print('Porcentaje Hombres=', porcH, '%')
print('Porcentaje Mujeres=', porcM, '%')


#Lustros
print('Introduce tu año de nacimiento')
nacimiento = int(input())
añoActual = 2019
lustro = (añoActual - nacimiento) / 5.0
print(lustro)

#Area triangulo
print('Introduce la altura')
altura = int(input())
print('Introduce la base')
base = int(input())
area = altura * base / 2
print(area)

#Metros a pies
print("introduce los metros")
metros = int(input())
pies = metros*100/2.54/12
print(pies)

#Precio positivo
print("introduce un precio")
precio = int(input())
if precio > 0:
        print('precio válido')
else:
        print('precio no válido')
        
        
#Velocidad promedio
print('introduce la distancia recorrida')
distancia = int(input())
print('introduce la duración del viaje')
tiempo = int(input())
velocidad = distancia/tiempo
print("tu velocidad promedio es:", velocidad)

#Mayoría de edad
print('introduce tu edad')
edad = int(input())
if edad >= 18:
        print('ya puedes sacar tu INE')
else:
        print('espérate unos añitos mas')
        


        

