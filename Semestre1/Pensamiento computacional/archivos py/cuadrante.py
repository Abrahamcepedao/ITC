#Cuadrante
print('Introduce un valor')
number = int(input())
if number < 0 or number > 360:
    print('excede')
elif number in [0, 90, 180, 270, 360]:
    print('eje')
elif number > 0 and number < 90:
    print('1')
elif number > 90 and number < 180:
    print('2')    
elif number > 180 and number < 270:
    print('3')
elif number > 270 and number < 360:
    print('4')        