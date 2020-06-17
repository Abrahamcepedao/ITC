#dias mes
#print('Introduce el número de mes')
number = int(input())
if number in [1, 3, 5, 7, 10, 12]:
    print("31")
elif number == 2:
    print("28")
elif number in [4, 6, 8, 9, 11]:
    print("30")
else:
    print("0")