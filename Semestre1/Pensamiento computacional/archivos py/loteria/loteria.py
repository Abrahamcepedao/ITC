from random import shuffle
from PIL import Image

gallo = Image.open("el gallo.jpg")
diablito = Image.open("el diablito.jpg")
dama = Image.open("la dama.jpg")
catrin = Image.open("el catrin.jpg")
paraguas = Image.open("el paraguas.jpg")
sirena = Image.open("la sirena.jpg")
escalera = Image.open("la escalera.jpg")
botella = Image.open("la botella.jpg")
barril = Image.open("el barril.jpg")
arbol = Image.open("el arbol.jpg")
melon = Image.open("el melon.jpg")
valiente = Image.open("el valiente.jpg")
gorrito = Image.open("el gorrito.jpg")
muerte = Image.open("la muerte.jpg")
pera = Image.open("la pera.jpg")
bandera = Image.open("la bandera.jpg")
bandolon = Image.open("el bandolon.jpg")
violoncelo = Image.open("el violoncello.jpg")
garza = Image.open("la garza.jpg")
pajaro = Image.open("el pajaro.jpg")
mano = Image.open("la mano.jpg")
bota = Image.open("la bota.jpg")
luna = Image.open("la luna.jpg")
cotorro = Image.open("el cotorro.jpg")
borracho = Image.open("el borracho.jpg")
negrito = Image.open("el negrito.jpg")
corazon = Image.open("el corazon.jpg")
sandia = Image.open("la sandia.jpg")
tambor = Image.open("el tambor.jpg")
camaron = Image.open("el camaron.jpg")
jaras = Image.open("las jaras.jpg")
musico = Image.open("el musico.jpg")
arana = Image.open("la arana.jpg")
soldado = Image.open("el soldado.jpg")
estrella = Image.open("la estrella.jpg")
cazo = Image.open("el cazo.jpg")
mundo = Image.open("el mundo.jpg")
apache = Image.open("el apache.jpg")
nopal = Image.open("el nopal.jpg")
alacran = Image.open("el alacran.jpg")
rosa = Image.open("la rosa.jpg")
calavera = Image.open("la calavera.jpg")
campana = Image.open("la campana.jpg")
cantarito = Image.open("el cantarito.jpg")
venado = Image.open("el venado.jpg")
sol = Image.open("el sol.jpg")
corona = Image.open("la corona.jpg")
chalupa = Image.open("la chalupa.jpg")
pino = Image.open("el pino.jpg")
pescado = Image.open("el pescado.jpg")
palma = Image.open("la palma.jpg")
maceta = Image.open("la maceta.jpg")
arpa = Image.open("el arpa.jpg")
rana = Image.open("la rana.jpg")

imagenes = [gallo, diablito, dama, catrin, paraguas, sirena, escalera, botella, barril, arbol, melon, valiente, gorrito, muerte, pera, bandera, bandolon, violoncelo, garza, pajaro, mano, bota, luna, cotorro, borracho, negrito, corazon, sandia, tambor, camaron, jaras, musico, arana, soldado, estrella, cazo, mundo, apache, nopal, alacran, rosa, calavera, campana, cantarito, venado, sol, corona, chalupa, pino, pescado, palma, maceta, arpa, rana]
numeros = [i for i in range(54)]
cartas = [" 'El gallo'", "'El diablito'", "'La dama'", "'El catrín'", "'El paraguas'", "'La sirena'", "'La escalera'", "'La botella'", "'El barril'", "'El árbol'", "'El melón'", "'El valiente'", "'El gorrito'", "'La muerte'", "'La pera'", "'La bandera'", "'El bandolón'", "'El violoncello'", "'La garza'", "'El pájaro'", "'La mano'", "'La bota'", "'La luna'", "'El cotorro'", "'El borracho'", "'El negrito'", "'El corazón'", "'La sandía'", "'El tambor'", "'El camarón'", "'Las jaras'", "'El músico'", "'La araña'", "'El soldado'", "'La estrella'", "'El cazo'", "'El mundo'", "'El apache'", "'El nopal'", "'El alacrán'", "'La rosa'", "'La calavera'", "'La campana'", "'El cantarito'", "'El venado'", "'El sol'", "'La corona'", "'La chalupa'", "'El pino'", "'El pescado'", "'La palma'", "'La maceta'", "'El arpa'", "'La rana'"]

print(cartas)
answer = input('Quieres volver jugar a la loteria <si><no>:?')
while answer == "si":
    shuffle(numeros)
    print(numeros)
    estado = input('Para terminar esta jugada teclea <loteria>:')
    if estado != "loteria":
        print(cartas[numeros[0]])
        try:
            imagenes[numeros[0]].show()
        except:
            print("No se pudo cargar la imágen")
        count = 1
        while (estado != 'loteria') and count < 54:
            estado = input('Para terminar esta jugada teclea <loteria>:')
            print(cartas[numeros[count]])
            try:
                imagenes[numeros[count]].show()
            except:
                print("No se pudo cargar la imágen")
            count += 1 
        answer = input('Quieres volver jugar a la loteria <si><no>:?')
    else:
        answer = input('Quieres volver jugar a la loteria <si><no>:?')




