def sumaPares(num):
    snum = str(num)
    suma = 0
    for i in range(len(snum)):
        if int(snum[i]) % 2 == 0:
            suma = suma + int(snum[i])
    print(suma)
def main():
    num = int(input())
    sumaPares(num)
main()