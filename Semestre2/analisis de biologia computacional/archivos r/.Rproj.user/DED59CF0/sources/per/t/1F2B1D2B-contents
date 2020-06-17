# <----------------------Load data---------------------->
load("Multi_Cancer_Data.RData", verbose = TRUE)
df <- data.frame(multi_cancer_data)

# <----------------------Cambiar nombre de columnas---------------------->
# <------Caso tumor------>
for(i in 1:190){
  name <-colnames(df)[i]
  name <-gsub("Tumor__","",name)
  names<-strsplit(name, '_')
  name <- names[[1]][1]
  colnames(df)[i] <- name
}
# <------Caso normal------>
for (i in 191:280) {
  name <-colnames(df)[i]
  name <-gsub("Normal__","",name)
  names<-strsplit(name, '_')
  name <- names[[1]][1]
  colnames(df)[i] <- name
}

# <----------------------Crear dataframes---------------------->
# <------Dataframes iniciales------>
df_tumor <- df[,which(colnames(df)=="Colorectal")]
df_normal <- df[,which(colnames(df)=="Colon")]

# <------Dataframes de promedios------>
v_tumor <- data.frame(row.names(df_tumor), rep(NA, length(df_tumor[[1]]))) 
v_normal <- data.frame(row.names(df_normal), rep(NA, length(df_tumor[[1]])))

# <------Calcular y almacenar promedios------>
for (i in 1:length(df_tumor[[1]])) {
  v_tumor[[2]][i] <- mean(as.numeric(df_tumor[i,]))
  v_normal[[2]][i] <- mean(as.numeric(df_normal[i,]))
}

# <------Ordenar de mayor a menor los promedios------>
v_tumor <- v_tumor[order(v_tumor$Promedio, decreasing = TRUE),]
v_normal <- v_normal[order(v_normal$Promedio, decreasing = TRUE),]

# <------Obtener los 20 mayores promedios------>
twenty_tumor <- v_tumor[1:20,]
twenty_normal <- v_normal[1:20,]

# <------Dataframe de genes iguales------>
equal <- data.frame(rep(NA,20),rep(NA,20),rep(NA,20))
colnames(equal) <- c("Gene", "Tumor", "Normal")

# <------Determinar los genes iguales------>
count <- 1
for (i in 1:20) {
  if (twenty_tumor[i,1] %in% twenty_normal[,1]){
    equal[count,1] <- as.character(twenty_tumor[i,1])
    equal[count,2] <- twenty_tumor[i,2]
    equal[count,3] <- twenty_normal[twenty_normal$Gene == as.character(twenty_tumor[i,1]),2]
    count <- count + 1
  }
}

# <------Remover NAs------>
equal <- na.omit(equal)

# <------Dataframe de comparacion de genes------>
tumor_in_normal <- data.frame(twenty_tumor[,1],rep(NA,20),rep(NA,20),rep(NA,20))
colnames(tumor_in_normal) <- c("Gene", "Normal", "Tumor", "Diferencia")
normal_in_tumor <- data.frame(twenty_normal[,1],rep(NA,20),rep(NA,20),rep(NA,20))
colnames(normal_in_tumor) <- c("Gene", "Tumor", "Normal", "Diferencia")

# <------Realizar comparacion y almacenar datos------>
for (i in 1:20) {
  tumor_in_normal[i,2] <- v_normal[v_normal$Gene == twenty_tumor[i,1],2]
  tumor_in_normal[i,3] <- twenty_tumor[i,2]
  tumor_in_normal[i,4] <- abs(twenty_tumor[i,2]-tumor_in_normal[i,2])
  normal_in_tumor[i,2] <- v_tumor[v_tumor$Gene == twenty_normal[i,1],2]
  normal_in_tumor[i,3] <- twenty_normal[i,2]
  normal_in_tumor[i,4] <- abs(twenty_normal[i,2]-normal_in_tumor[i,2])
}

# <------Ordenar los genes de mayor a menor------>
tumor_in_normal <- tumor_in_normal[order(tumor_in_normal$Diferencia, decreasing = TRUE),]
normal_in_tumor <- normal_in_tumor[order(normal_in_tumor$Diferencia, decreasing = TRUE),]



