library(RISmed)
search <- EUtilsSummary("hepatitis[TI] AND (virus[TI] AND child[TIAB]")
records <- EUtilsGet(search)
pubmed_data <- data.frame('Title' = ArticleTitle(records), 'Abstract' = AbstractText(records), 'PID' = ArticleId(records))
#strsplit

#---------------------------------------------------
#a) Compara todas las muestras de cáncer contra todos los normales.

#b) Compara las muestras de cada cáncer contra su respectivo normal. En el caso de leucemia o linfoma, usa las muestras normales que dicen “Germinal” y “peripheral blood”; para glioblastoma usa “whole brain” y para meduloblastoma usa “cerebellum”. Describe también por qué se deben hacer así estas comparaciones.

#c) Compara si los genes con medias más diferentes en las comparaciones de cánceres individuales son similares al de la comparación de todas las muestras. Comenta en especial para el caso de cáncer colorectal.



load("Multi_Cancer_Data.RData", verbose = TRUE)
df <- data.frame(multi_cancer_data)

#print(colnames(dataFile))
tumors <- df[,1:190]
normal <- df[,191:280]
#write.csv(tumors,"tumors.csv", row.names = FALSE)
#write.csv(normal,"normal.csv", row.names = FALSE)

#obtiene promedios
meandt <-as.data.frame(t(apply((tumors),MARGIN=2,FUN=mean)))
meann <-as.data.frame(t(apply((normal),MARGIN=2,FUN=mean)))
#print(length(meann))


#a)
totalm_dt= 0
for(i in 1:190){
  totalm_dt<-totalm_dt+ meandt[1,i]
}
totalm_dn <-0
for(j in 1:90){
  totalm_dn<-totalm_dn+ meann[1,j]
}

totalm_dt <- totalm_dt/190
totalm_dn <- totalm_dn/90
diff_avg <- totalm_dt-totalm_dn

cat("\nPROMEDIO TUMORES:",totalm_dt,"| PROMEDIO NOMRALES:",totalm_dn,"| DIFERENCIA:",diff_avg,"\n", sep="\t")

#test

#renombrar columnas
for(i in 1:190){
  #gets col name
  name <-colnames(meandt)[i]
  name <-gsub("Tumor__","",name)
  names<-strsplit(name, '_')
  name <-names[[1]][1]
  #print(name)
  colnames(meandt)[i] <- name
}
write.csv(meandt,"renamed_T.csv", row.names = FALSE)

for(i in 1:90){
  #gets col name
  name <-colnames(meann)[i]
  name <-gsub("Normal__","",name)
  names<-strsplit(name, '_')
  name <-names[[1]][1]
  #print(name)
  colnames(meann)[i] <- name
}

#type_list = unique(colnames(meann))
type_list_n = unique(colnames(meann))
type_list_t = unique(colnames(meandt))
type_list = unique(c(type_list_n,type_list_t))

vector_tumor = rep(c(0), times=20)
vector_tumorc = rep(c(0), times=20)
count = 1
acum = 0

for(i in 1:190){
  for(j in 1:length(type_list)){
    if(colnames(meandt[i]) == type_list[j]){
      vector_tumorc[j] = vector_tumorc[j] + 1
      vector_tumor[j] = vector_tumor[j] + meandt[i]
    }
  }
}

for (i in 1:length(type_list)) {
  n = vector_tumor[i]
  c = vector_tumorc[i]
  prom = as.numeric(n) / as.numeric(c)
  vector_tumor[i] = prom
}

# normal
vector_normal = rep(c(0), times=20)
vector_normalc = rep(c(0), times=20)
count = 1
acum = 0

for(i in 1:90){
  for(j in 1:length(type_list)){
    if(colnames(meann[i]) == type_list[j]){
      vector_normalc[j] = vector_normalc[j] + 1
      vector_normal[j] = vector_normal[j] + meann[i]
    }
  }
}

for (i in 1:length(type_list)) {
  n = vector_normal[i]
  c = vector_normalc[i]
  prom = as.numeric(n) / as.numeric(c)
  vector_normal[i] = prom
}

cat("Tipo \t Normal \t Tumor \t Diferencia")
for (i in 1:20){
  cat(type_list[[i]], "\t", vector_normal[[i]], "\t", vector_tumor[[i]], "\t", as.numeric(vector_normal[i])-as.numeric(vector_tumor[i]), "\n")
}

