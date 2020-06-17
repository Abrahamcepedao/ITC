test = int(input())
for num in range(test):
    pattern = input('enter pattern:')
    letters = input('enter letters:')
    lettersArray = [i for i in letters]
    count = 0
    for i in range(len(pattern)):
        if pattern[i] in lettersArray:
            count += 1
            lettersArray.remove(pattern[i])
    if count == len(pattern):
        print('Yes')
    else:
        print('No')
