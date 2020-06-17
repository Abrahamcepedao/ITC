#Body mass index
print('Peso en kg')
peso = float(input())
print('Altura en m')
altura = float(input())
bmi = peso / (altura ** 2)

#Ubicación bmi
if bmi < 20:
    print('PESO BAJO')
elif bmi >= 20 and bmi < 25:
    print('NORMAL')
elif bmi >= 25 and bmi < 30:
    print('SOBREPESO')
elif bmi >= 30 and bmi < 40:
    print('OBESIDAD')    
else:
    print('OBESIDAD MORBIDA')