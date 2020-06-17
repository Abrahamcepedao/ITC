'''
    ¿De qué forma conviene abrir el archivo para el reporte de Cuentas de Correo?
    
    Información del archivo - 
    eli.gon@int.mx
    dan.iva.vaz.esc@int.mx
    and.cha.ang@int.mx
    val.cañ.gal@int.mx
    dan.vaz@int.mx
    ana.vic.de.los.san@int.mx
    
    
    - Método Read([bytes])-
    El método read nos permite leer un archivo completo, salvo que indiquemos
    los bytes entonces solo leerá hasta los bytes determinados.
    
    Resultado:
    eli.gon@int.mx
    dan.iva.vaz.esc@int.mx
    and.cha.ang@int.mx
    val.cañ.gal@int.mx
    dan.vaz@int.mx
    ana.vic.de.los.san@int.mx


    - Método Readline([bytes])-
    El método readline lee una línea por vez. Si colocamos un solo readline nos
    leerá una sola línea y si no especificamos a partir de donde sera
    la primera por defecto. 
    
    Resultado:
    eli.gon@int.mx
    
    
    - Método Readlines() -
    Lee todas las líneas en forma de lista separando las líneas con
    el carácter de escape para los saltos de línea \n
    
    Resultado:
    ['eli.gon@int.mx\n', 'dan.iva.vaz.esc@int.mx\n', 'and.cha.ang@int.mx\n',
    'val.cañ.gal@int.mx\n', 'dan.vaz@int.mx\n', 'ana.vic.de.los.san@int.mx\n']    
    
    '''

def main():
    """si abrimos el archivo en el modo w
    - Crea un archivo llamado salidaINT.txt
    si ya existe LO BORRA!!!
    si no existe lo crea!!

"""
    with open('salidaINT.txt','w') as archivoSalida:
        print("Hola","Urme", "Bienvenido al curso de Verano", sep = '-',file = archivoSalida)
        print("Maria Paula","Oscar", sep = '-',file = archivoSalida)
        print("Magnolia", "Harold", sep = '-',file = archivoSalida)
        print("Cristian", "Diego", sep = '-',file = archivoSalida)
        print("Jesus", "Karlita", sep = '-',file = archivoSalida)

def creaUnArchivo():
    cantidad = int(input("Teclea la cantidad de alumnos a ingresar:"))
    with open('salidaINT2.txt','w') as archivoSalida:
        for alumno in range(cantidad):
            s = input("Teclea el nombre del alumnos:")
            print(s, file = archivoSalida)
            
def añadeAUnArchivo():
    cantidad = int(input("Teclea la cantidad de alumnos a ingresar:"))
    with open('salidaINT2.txt','a') as archivoSalida:
        for alumno in range(cantidad):
            s = input("Teclea el nombre del alumno:")
            print(s, file = archivoSalida)

def leerUnArchivo():
    cantidad = int(input("Teclea la cantidad de alumnos a ingresar:"))
    with open('salidaINT2.txt') as archivoEntrada:
        for alumno in range(cantidad):
            s = input("Teclea el nombre del alumno:")
            print(s, file = archivoEntrada)
            
main()
añadeAUnArchivo()

