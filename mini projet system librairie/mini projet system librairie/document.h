#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void new_document(){	
	printf("pour ajouter un nouveau document s\'il vous plait suivre les etape suivantes\n le titre:");
	
	FILE *pFile;
	FILE *fp;
	fp = fopen ("documents/document/nombre_de_livre.txt","r");
    
	int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
	char direction[100]="documents/document/informations/";
	char n[10];
	
	itoa(nombre,n,10);
	strcat(direction,n);
	strcat(direction,".txt");
	
	pFile = fopen(direction,"w");
	fp = fopen ("documents/document/nombre_de_livre.txt","w");
	fprintf(fp,"%d",nombre+1);
	fclose(fp);
	fprintf(pFile,"code_unique: %d\n",nombre);
	char* nom;
	gets(nom);
	fprintf(pFile,"titre: %s\n",nom);
	printf("lalocalisation(salle/rayon):");
	gets(nom);
	fprintf(pFile,"la_localisation(salle/rayon): %s\n",nom);
	printf("le code unique est %d\n",nombre);
	printf("le nombre d'exemplaire:");
	gets(nom);
	fprintf(pFile,"nombre_exemplaire: %s\n",nom);
	do{
	printf("donner le  type(articles/livres/magasines):");
	gets(nom);
	}
	while(((strcmp(nom,"articles") and strcmp(nom,"livres" ))and strcmp(nom,"magasines")));
	fprintf(pFile,"type: %s\n",nom);
	if(strcmp(nom,"articles")==0){
	printf("nom de l'auteur':");
	gets(nom);
	fprintf(pFile,"nom_de_l_auteur: %s\n",nom);
	printf("date de publication:");
	gets(nom);
	fprintf(pFile,"date_de_publication: %s\n",nom);
	}
	else if(strcmp(nom,"livres")==0){
	printf("nom  de l auteur:");
	gets(nom);
	fprintf(pFile,"nom_de_l_auteur: %s\n",nom);
	printf("nom de l editeur:");
	gets(nom);
	fprintf(pFile,"nom_de_l_edition: %s\n",nom);
	printf("la date d edition:");
	gets(nom);
	fprintf(pFile,"la_date_d_edition: %s\n",nom);
	}
	else{
	printf("la frequence de parution:");
	gets(nom);
	fprintf(pFile,"la_frequence_de_parution: %s\n",nom);
	}
	fprintf(pFile,"le_nombre_des_emprunts_effectuer: 0\n");
	fclose(pFile);
}

void modifier_document(){
	printf("pour modifier un document s\'il vous plait suivre les etape suivantes\n le titre:");
	FILE * fp;
	printf("entrer le code unique du document :\n");
	char nombre[10];
	gets(nombre);
	char direction[100]="documents/document/informations/";
	strcat(direction,nombre);
	strcat(direction,".txt");
	if(access( direction, F_OK ) != -1){

	fp = fopen(direction,"r");
	char texte[255];
	for(int i=0;i<4;i++){
	fgets (texte,255,fp);
	printf("%s",texte);}
	fscanf(fp,"%s",texte);
	printf("%s",texte);
	fscanf(fp,"%s",texte);
	printf("%s",texte);
	if(strcmp(texte,"articles")==0){
	for(int i=-1;i<3;i++){
	fgets (texte,255,fp);
	printf("%s",texte);
	}
	}
	else if(strcmp(texte,"livres")==0){
	for(int i=-1;i<4;i++){
	fgets (texte,255,fp);
	printf("%s",texte);
	}
	}
	else{
	fgets (texte,255,fp);
	printf("%s",texte);
	fgets (texte,255,fp);
	printf("%s",texte);
	fgets (texte,255,fp);
	printf("%s",texte);
	}
	fclose(fp);
    FILE * pFile;	
	pFile = fopen(direction,"w");
	printf("donner le nouveau titre");
	fprintf(pFile,"code_unique: %s\n",nombre);
	char nom[255];
	gets(nom);
	fprintf(pFile,"titre: %s\n",nom);	
	printf("lalocalisation(salle/rayon):");
	gets(nom);
	fprintf(pFile,"la_localisation(salle/rayon): %s\n",nom);
	printf("le code unique est %s\n",nombre);
	printf("le nombre d'exemplaire:");
	gets(nom);
	fprintf(pFile,"nombre_exemplaire: %s\n",nom);
	do{
	printf("donner le  type(articles/livres/magasines):");
	gets(nom);
	}
	while((strcmp(nom,"articles") and strcmp(nom,"livres" ))and strcmp(nom,"magasines"));
	fprintf(pFile,"type: %s\n",nom);
	if(strcmp(nom,"articles")==0){
	printf("nom de l'auteur:");
	gets(nom);
	fprintf(pFile,"nom_de_l_auteur: %s\n",nom);
	printf("date de publication:");
	gets(nom);
	fprintf(pFile,"date_de_publication: %s\n",nom);
	}
	else if(strcmp(nom,"livres")==0){
	printf("nom  de l auteur:");
	gets(nom);
	fprintf(pFile,"nom_de_l_auteur: %s\n",nom);
	printf("nom de l editeur:");
	gets(nom);
	fprintf(pFile,"nom_de_l_edition: %s\n",nom);
	printf("la date d edition:");
	gets(nom);
	fprintf(pFile,"la_date_d_edition: %s\n",nom);
	}
	else{
	printf("la frequence de parution:");
	gets(nom);
	fprintf(pFile,"la_frequence_de_parution: %s\n",nom);
	}
	fprintf(pFile,"le_nombre_des_emprunts_effectuer: 0\n");
	fclose(pFile);
}
else{
	printf("il n y a aucun document qui admet ce code unique");
}


}




void read_document(){
	FILE * fp;
	printf("entrer le code unique du document :\n");
	char nombre[10];
	gets(nombre);
	char direction[100]="documents/document/informations/";
	strcat(direction,nombre);
	strcat(direction,".txt");
	if(access( direction, F_OK ) != -1){

	fp = fopen(direction,"r");
	char texte[255];
	for(int i=0;i<4;i++){
	
	fgets (texte,255,fp);
	printf("%s",texte);
	}
	fscanf(fp,"%s",texte);
	printf("%s",texte);
	fscanf(fp,"%s",texte);
	printf("%s",texte);
	if(strcmp(texte,"articles")==0){
	for(int i=-1;i<3;i++){
	fgets (texte,255,fp);
	printf("%s",texte);
	}
	}
	else if(strcmp(texte,"livres")==0){
	for(int i=-1;i<4;i++){
	fgets (texte,255,fp);
	printf("%s",texte);
	}
	}
	else{
	fgets (texte,255,fp);
	printf("%s",texte);
	fgets (texte,255,fp);
	printf("%s",texte);
	
	fgets (texte,255,fp);
	printf("%s",texte);
	
	}
	
	fclose(fp);
}
else{
	printf("il n y a pas aucun document  qui admet ce code unique");
	
}


}


void effacer_document(){
	printf("entrer le code unique du document a effacer:\n");
	char nombre[10];
	gets(nombre);
	char direction[100]="documents/document/informations/";
	strcat(direction,nombre);
	strcat(direction,".txt");
/*	FILE *fp;
	fp = fopen(direction,"w");
	fprintf(fp,"code_unique: %s\ntitre: a_ete_effacer",nombre);
	fclose(fp);
*/	remove(direction);
	
}



void liste_document(){
	FILE *fp;
	FILE *pFile;
    fp = fopen ("documents/document/nombre_de_livre.txt","r");
    int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
	for(int i=1;i<nombre;i++){
	
	char direction[100]="documents/document/informations/";
	char n[10];
	itoa(i,n,10);
	strcat(direction,n);
	strcat(direction,".txt");
	
	char texte[255];
	if(access( direction, F_OK ) != -1){
	pFile = fopen(direction,"r");
	fgets(texte,255,pFile);
	fscanf(pFile,"%s",texte);
	fgets(texte,255,pFile);

	if(strcmp(texte," a_ete_effacer")!=0)
	printf("%d:%s",i,texte);
	
}
}
fclose(pFile);
}

