#file <- 'nuevo_ingreso.csv'
dataa <- read.csv('nuevo_ingreso.csv')

# <-----b)----->
tumores = length(unique(dataa$DESCRIPCION.DIAGNOSTICO)) 
print("<----Cantidad de tumores diferentes---->")
print(tumores) 

estados = sort(table(dataa$ESTADO))
diezEstados = estados[(length(estados)-9):length(estados)] 
print("<----Diez estados con mayor número de casos---->")
rev(diezEstados) 

municipios = sort(table(dataa$MUNICIPIO))
diezMunicipios = municipios[(length(municipios)-9):length(municipios)]  
print("<----Diez municipios con mayor número de casos---->")
rev(diezMunicipios) 

# <-----c)----->
tumorColonRecto = length(dataa$DESCRIPCION.DIAGNOSTICO[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO"])
print("<----Número de casos de tumor de colon o recto---->")
print(tumorColonRecto)

tumorColonJovenes = length(dataa$DESCRIPCION.DIAGNOSTICO[dataa$EDAD <= 29 & (dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO")])
print("<----Número de casos de tumor de colon o recto en jóvenes (menor a 29 años)---->")
print(tumorColonJovenes)

tumorColonJovenesA = length(dataa$DESCRIPCION.DIAGNOSTICO[dataa$EDAD < 50 & (dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO")])
print("<----Número de casos de tumor de colon o recto en jóvenes adultos (menor a 50 años)---->")
print(tumorColonJovenesA)

tumorCRE = rev(sort(table(dataa$ESTADO[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO"])))
print("<----Número de casos de tumor de colon o recto por estado---->")
print(tumorCRE[1:10])

tumorCRM = rev(sort(table(dataa$MUNICIPIO[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON" | dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL RECTO"])))
print("<----Número de casos de tumor de colon o recto por municipio---->")
print(tumorCRM[1:10])