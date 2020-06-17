print('Teclea cantidad de Hombres:')
cantH = int(input())
print('Teclea cantidad de Mujeres:')
cantM = int(input())
total = cantH + cantM
pH =  cantH/total *100
pM = cantM/total*100
print('Porcentaje Mujeres= ', pM, '%', sep=' ')
print('Porcentaje Hombres= ', pH, '%', sep=' ')
