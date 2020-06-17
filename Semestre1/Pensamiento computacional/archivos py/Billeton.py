#Billeton
print('Introduce un número')
numero = int(input())
cien = numero // 100
numero = numero % 100
cincuenta =  numero // 50
numero = numero % 50
veinte =  numero // 20
numero = numero % 20
diez =  numero // 10
numero = numero % 10
cinco =  numero // 5
numero = numero % 5
dos =  numero // 2
numero = numero % 2
uno = numero // 1
print(cien, "Billetes de $100")
print(cincuenta, "Billetes de $50")
print(veinte, "Billetes de $20")
print(diez, "Monedas de $10")
print(cinco, "Monedas de $5")
print(dos, "Monedas de $2")
print(uno, "Monedas de $1")
