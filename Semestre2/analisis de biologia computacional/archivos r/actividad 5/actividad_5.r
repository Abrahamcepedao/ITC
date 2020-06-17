library(readr)
cosmic_data <- read_csv("cosmic_data.csv")
cosmic_data <- cosmic_data[which(cosmic_data$`Sample Type` == "Tumour Sample"),]
cosmic_data <- cosmic_data[-which(cosmic_data$`Somatic Status` == "Variant of unknown origin"),]
View(cosmic_data)

#cosmic_pos <- sort(as.numeric(unique(c(cosmic_data$s, cosmic_data$end))))

gnomad_data <- read_csv("gnomad_data.csv")
View(gnomad_data)
table(gnomad_data$Annotation)

aux_loc <- unlist(strsplit(x=cosmic_data$`Genomic Co-ordinates`, split=":"))[seq(from=2, to=nrow(cosmic_data)*2, by=2)]
aux_loc2 <- unlist(strsplit(x=aux_loc, split="\\.\\."))
cosmic_data$start <- aux_loc2[seq(from=1, to=nrow(cosmic_data)*2, by=2)]
cosmic_data$end <- aux_loc2[seq(from=2, to=nrow(cosmic_data)*2, by=2)]
cosmic_pos <- sort(as.numeric(unique(c(cosmic_data$start, cosmic_data$end))))
gnomAD_pos <- sort(unique(gnomad_data$Position))
allele_count_gnomad <- gnomad_data[which(gnomad_data$`Allele Count`> 1000),c(1:5,9,10,12,14:16)]
allele_count_cosmic <- sort(table(cosmic_data$`AA Mutation`), decreasing = T)