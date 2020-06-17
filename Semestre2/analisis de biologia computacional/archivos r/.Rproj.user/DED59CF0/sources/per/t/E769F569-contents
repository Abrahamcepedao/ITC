# <----------------------Load data---------------------->
dataa <- read.csv('nuevo_ingreso.csv')
data_colon <- dataa[dataa$DESCRIPCION.DIAGNOSTICO == "TUMOR MALIGNO DEL COLON",]

# <----------------------Filter data---------------------->
# <------Rango de edad------>
cat("Rango de edad: ",range(data_colon$EDAD))

# <------Numero de mujeres------>
data_mujeres <- data_colon[data_colon$SEXO == "Femenino",]
casos_mujeres <- length(data_mujeres[[1]])

# <------Numero de hombres------>
data_hombres <- data_colon[data_colon$SEXO == "Masculino",]
casos_hombres <- length(data_hombres[[1]])


# <------Numero de jovenes------>
data_jovenes <- data_colon[data_colon$EDAD < 50,]
casos_jovenes <- length(data_jovenes[[1]])

# <------Numero de mujeres jovenes------>
data_mujeres_jovenes <- data_jovenes[data_jovenes$SEXO =="Femenino",]
casos_mujeres_jovenes <- length(data_mujeres_jovenes[[1]])

# <------Numero de hombres jovenes------>
data_hombres_jovenes <- data_jovenes[data_jovenes$SEXO == "Masculino",]
casos_hombres_jovenes <- length(data_hombres_jovenes[[1]])

# <------Numero de mayores------>
data_mayores <- data_colon[data_colon$EDAD >= 50,]
casos_mayores <- length(data_mayores[[1]])

# <------Numero de mujeres mayores------>
data_mujeres_mayores <- data_mayores[data_mayores$SEXO == "Femenino",]
casos_mujeres_mayores <- length(data_mujeres_mayores[[1]])

# <------Numero de hombres mayores------>
data_hombres_mayores <- data_mayores[data_mayores$SEXO == "Masculino",]
casos_hombres_mayores <- length(data_hombres_mayores[[1]])

# <------Estados con mayor numero de casos------>
data_estado <- rev(sort(table(data_colon$ESTADO)))
data_estado <- data_estado[1:5]


# <----------------------PLot data---------------------->
pie(c(as.numeric(casos_mayores), as.numeric(casos_jovenes)), labels = c("Mayores", "Jovenes"), main = "Mayores y jovenes")

pie(c(as.numeric(casos_hombres), as.numeric(casos_mujeres)), labels = c("Hombres", "Mujeres"), main = "Mujeres y Hombres (general)")
pie(c(as.numeric(casos_hombres_jovenes), as.numeric(casos_mujeres_jovenes)), labels = c("Hombres", "Mujeres"), main = "Mujeres y Hombres (jovenes)")
pie(c(as.numeric(casos_hombres_mayores), as.numeric(casos_mujeres_mayores)), labels = c("Hombres", "Mujeres"), main = "Mujeres y Hombres (mayores)")


barplot(data_estado)

