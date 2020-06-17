#cupCake price calculator
print('Introduce de amount of dollars')
dollars = int(input())
print('Introduce de amount of cents')
cents = int(input())
print('Introduce de amount of cupcakes')
cupCakes = int(input())
totalCents = (cents * cupCakes) % 100
totalDollars = dollars * cupCakes + ((cents * cupCakes) // 100)
print(totalDollars, totalCents)
