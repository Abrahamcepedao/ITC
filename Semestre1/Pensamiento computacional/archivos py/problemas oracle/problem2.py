num = int(input())
numbers = input()
numbersArray = []
pos1 = 0
pos2 = 0
while numbers.find(' ') != -1:
    pos2 = numbers.find(' ', pos1)
    numbersArray.append(numbers[pos1:pos2])
    pos1 = pos2
    print(numbersArray)