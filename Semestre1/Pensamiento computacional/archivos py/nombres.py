name = input('tu nombre: ')
pos = name.find(' ')
pos2 = name.find(' ', pos + 1)
nombre = name[:pos]
paterno = name[pos+1:pos2]
materno = name[pos2+1:]
print(nombre)
print(paterno)
print(materno)