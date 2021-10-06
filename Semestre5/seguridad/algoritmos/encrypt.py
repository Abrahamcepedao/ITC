word = list(input("Enter word: "))
num = int(input("Enter num: "))

lettersArray = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"]
lettersDict = {
    "a": 0,
    "b": 1,
    "c": 2,
    "d": 3,
    "e": 4,
    "f": 5,
    "g": 6,
    "h": 7,
    "i": 8,
    "j": 9,
    "k": 10,
    "l": 11,
    "m": 12,
    "n": 13,
    "ñ": 14,
    "o": 15,
    "p": 16,
    "q": 17,
    "r": 18,
    "s": 19,
    "t": 20,
    "u": 21,
    "v": 22,
    "w": 23,
    "x": 24,
    "y": 25,
    "z": 26
}


isUpper = []

for letter in word:
    isUpper.append(letter.isupper())

for i in range(0, len(word)):
    word[i] = lettersArray[(lettersDict[word[i].lower()] + num)  % len(lettersArray)]
    if isUpper[i]:
        word[i] = word[i].upper()

print("".join(word))