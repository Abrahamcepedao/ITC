#calculadora
def calculadora(num1, operador, num2):
    if operador == "+":
        print(num1, operador, num2, "=", (num1 + num2) , sep='')
    elif operador == "-":
        print(num1, operador, num2, "=", (num1 - num2) , sep='')
    elif operador == "*":
        print(num1, operador, num2, "=", (num1 * num2) , sep='')
    elif operador == "**":
        print(num1, operador, num2, "=", (num1 ** num2) , sep='')
    elif operador == "//":
        if num2 == 0:
            print("ERROR")
        else:
            print(num1, operador, num2, "=", (num1 // num2) , sep='')    
    elif operador == "/":
        if num2 == 0:
            print("ERROR")
        else:
            print(num1, operador, num2, "=", (num1 / num2) , sep='')
    elif operador == "%":
        if num2 == 0:
            print("ERROR")
        else:
            print(num1, operador, num2, "=", int((num1 % num2)) , sep='')
    else:
        print("ERROR")

#definir main
def main():
    #leer datos
    number1 = float(input())
    operador = input()
    number2 = float(input())
    calculadora(number1, operador, number2)
    
#llamar a main    
main()