# read - lee todo el archivo completo - le puedes decir cuantos bytes te lee
"""
El modo en la función de abrir le dice a Python qué quieres hacer con el archivo. Existen múltiples modos que puede especificar al tratar con archivos de texto.

'w'- Modo de escritura : este modo se utiliza cuando el archivo necesita
ser modificado y la información cambiada o agregada.
Tenga en cuenta que esto borra el archivo existente para crear uno nuevo.
El puntero del archivo se coloca al principio del archivo.

'r'- Modo de lectura : este modo se utiliza cuando la información en el
archivo solo debe leerse y no debe modificarse de ninguna manera.
El puntero del archivo se coloca al principio del archivo.

'a'- Modo de anexar : este modo agrega información al final del archivo
automáticamente. El puntero del archivo se coloca al final del archivo.

'r+'- Modo de lectura / escritura : se usa cuando va a realizar cambios
en el archivo y leer información del mismo.
El puntero del archivo se coloca al principio del archivo.


'a+' - Modo anexar y leer : se abre un archivo para permitir que se agreguen
datos al final del archivo y también permite que el programa lea la
información. El puntero del archivo se coloca al final del archivo.


'x' - Modo de creación exclusivo : este modo se utiliza exclusivamente para
crear un archivo. Si ya existe un archivo con el mismo nombre, la función
de llamada fallará.

En Python, la mejor práctica para abrir y cerrar archivos es usar la
palabra reservada with  .

Esta palabra reservada cierra el archivo automáticamente después de que
se completa el bloque de código anidado:

"""
# read() leerá todo el archivo
with open('archivos.py') as archivo:
    s = archivo.read()
    print(s)

# readlines - lee todo el archivo y lo divide en varias líneas. 
with open('archivos.py', 'r') as archivo:
    lineas = archivo.readlines()
    print(lineas)
    for linea in lineas:
        print(linea, end ='')
        
# readline - analizar datos en un archivo al leerlos línea por línea.   
with open('archivos.py') as archivo:
    while True:
        s = archivo.readline()
        if s == '':
            break
        print(s, end ='')  
            
# lee linea por linea - procesa linea por linea
# La forma más fácil de procesar un archivo de texto completo línea por línea
with open('archivos.py') as archivo:
    for linea in archivo:
        print(linea, end ='')

