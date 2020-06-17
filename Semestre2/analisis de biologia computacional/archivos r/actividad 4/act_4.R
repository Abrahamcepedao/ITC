load("TCGA_COADREAD_comp_data.RData", verbose = TRUE)
df <- data.frame(tcga_coadread)
type <- data.frame(tcga_coadread_class)
dataNew <- data.frame(matrix(0, nrow = length(df[[1]]), ncol = 2))
countYoung <- 0
countOld <- 0
for (i in 1:length(df)) {
  if(type[[1]][i] == "Young"){
    dataNew[[1]] = dataNew[[1]] +  df[[i]]
    countYoung <- countYoung + 1
  } else{
    dataNew[[2]] = dataNew[[2]] +  df[[i]]
    countOld <- countOld + 1
  }
} 
for(i in 1:length(dataNew[[1]])){
  dataNew[[1]][i] = dataNew[[1]][i]/countYoung
  dataNew[[2]][i] = dataNew[[2]][i]/countOld
}
#write.csv(dataNew,"dataNew.csv", row.names = TRUE)