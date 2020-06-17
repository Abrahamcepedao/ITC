def piramide ():
    
    letras= "ABCDEFGHIJKLMNSOPQRSTUVWXYZ"
    lineas=int(input())
    if lineas>0 and lineas<27:
        print(" "*(lineas -1) + "A")
        for i in range (1, lineas):
            word=""
            word=" "*(lineas-1-i)
            for a in range (i+1):
                word= word+letras[a]
            for e in range (i-1,-1,-1):
                 word= word+letras[e]
            print (word)
    else:
        print("invalid")
piramide()

