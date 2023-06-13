#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void new_adherant(){
	
	printf("pour creer un nouveau adherent s\'il vous plait suivre les etape suivantes\n votre nom:");
	FILE *pFile;
	FILE *fp;
    fp = fopen ("documents/adherant/nombre_de_participants.txt","r");
    int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
	char direction[100]="documents/adherant/informations/";
	char n[10];
	itoa(nombre,n,10);
	strcat(direction,n);
	strcat(direction,".txt");
	pFile = fopen(direction,"w");
	fp = fopen ("documents/adherant/nombre_de_participants.txt","w");
	fprintf(fp,"%d",nombre+1);
	fclose(fp);
	fprintf(pFile,"identifiant: %d\n",nombre);
	char* nom;
	gets(nom);
	fprintf(pFile,"nom: %s\n",nom);
	printf("donner votre  prenom:");
	gets(nom);
	fprintf(pFile,"prenom: %s\n",nom);
	printf("votre identificateur est %d\n",nombre);
	printf("donner votre  adresse:");
	gets(nom);
	fprintf(pFile,"adresse: %s\n",nom);
do{
	printf("donner votre  type(etudiant/enseignant/visiteur):");
	gets(nom);
}while(((strcmp(nom,"etudiant") and strcmp(nom,"enseignant"))and strcmp(nom,"visiteur")));
	fprintf(pFile,"type: %s\n",nom);
	fprintf(pFile,"etat: OK\n");
	fprintf(pFile,"nombre_des_emprunts_depassee: 0\n");
	fprintf(pFile,"nombre_des_emprunts_effectuer: 0\n");
	fclose(pFile);

} 





void modifier_adherant(){
	printf("pour modifier le donnees d un adherant  s\'il vous plait suivre les etape suivantes\n");
	FILE * fp;
	printf("entrer l identifiant :\n");
	char nombre[10];
	gets(nombre);
	char direction[100]="documents/adherant/informations/";
	strcat(direction,nombre);
	strcat(direction,".txt");
	if(access( direction, F_OK ) != -1){

	fp = fopen(direction,"r");
	char texte[255];
	char t0[255];
	char t1[255];
	char t2[255];
	for(int i=0;i<5;i++){
	fgets (texte,255,fp);
	printf("%s",texte);}
	fgets(t0,255,fp);
	printf("%s",t0);
	fgets(t1,255,fp);
	
	printf("%s",t1);
	fgets(t2,255,fp);

	printf("%s",t2);
	fclose(fp);
    FILE * pFile;	
	pFile = fopen(direction,"w");
	printf("donner le nouveau nom");
	fprintf(pFile,"identifiant: %s\n",nombre);
	char nom[255];
	gets(nom);
	fprintf(pFile,"nom: %s\n",nom);	
	printf("prenom:");
	gets(nom);
	fprintf(pFile,"prenom: %s\n",nom);
	printf("l identifiant est %s\n",nombre);
	printf("adresse:");
	gets(nom);
	fprintf(pFile,"adresse: %s\n",nom);
	do{
	printf("donner le  type(etudiant/enseignant/visiteur):");
	gets(nom);
	}
	while((strcmp(nom,"etudiant") and strcmp(nom,"enseignant" ))and strcmp(nom,"visiteur"));
	fprintf(pFile,"type: %s\n",nom);
	fprintf(pFile,"%s",t0);	
	fprintf(pFile,"%s",t1);
	fprintf(pFile,"%s",t2);
	fclose(pFile);
}
else{
	printf("il n y a aucun document qui admet ce code unique");
}


}


void read_adherant(){
	FILE * fp;
	printf("entrer le identifiant de l adherant :\n");
	char nombre[10];
	gets(nombre);
	char direction[100]="documents/adherant/informations/";
	strcat(direction,nombre);
	strcat(direction,".txt");
	if(access( direction, F_OK ) != -1){

	fp = fopen(direction,"r");
	char texte[255];
	for(int i=0;i<8;i++){
	
	fgets (texte,255,fp);
	printf("%s",texte);
	
	}
	fclose(fp);
}
else{
	printf("il n y a pas aucun adherant qui admet cette identification");
}
}



void effacer_adherant(){
	printf("entrer le code unique de l adherant a effacer:\n");
	char nombre[10];
	gets(nombre);
	char direction[100]="documents/adherant/informations/";
	strcat(direction,nombre);
	strcat(direction,".txt");
/*	FILE *fp;
	fp = fopen(direction,"w");
	fprintf(fp,"code_unique: %s\ntitre: a_ete_effacer",nombre);
	fclose(fp);
*/	remove(direction);
	
}



void liste_adherant(){
	FILE *fp;
	FILE *pFile;
    fp = fopen ("documents/adherant/nombre_de_participants.txt","r");
    int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
	for(int i=1;i<nombre;i++){
	
	char direction[100]="documents/adherant/informations/";
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
	printf("%d:%s",i,texte);
	
}
}
fclose(pFile);
}



void liste_retardataire(){
	FILE *fp;
	FILE *pFile;
    fp = fopen ("documents/adherant/nombre_de_participants.txt","r");
    int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
	for(int i=1;i<nombre;i++){
	
	char direction[100]="documents/adherant/informations/";
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
	char texte2[255];
	for(int j=0;j<3;j++)
	fgets(texte2,255,pFile);
	fscanf(pFile,"%s",texte2);
	fgets(texte2,255,pFile);
	
	
	if(strcmp(texte2," retardataire\n")==0){
	
	printf("%d:%s",i,texte);
}
}
}
fclose(pFile);
}

