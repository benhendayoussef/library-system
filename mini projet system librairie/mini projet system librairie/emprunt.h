#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void ajouter_une_semaine(int*j,int*m,int*a){
	int day=*j;
	int mois=*m;
	int ann=*a;
	int journee[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(ann%4==0)journee[1]=29;
	if((day+7)>journee[mois-1]){
		if(mois<12){
			day=(day+7)%journee[mois-1];
			mois++;
		}
		else{
			day=(day+7)%journee[mois-1];
			mois=1;
			ann++;
			
			
		}
		
		
	}
	else{
		day+=7;
	}
*j=day;
*m=mois;
*a=ann;
}

char* date_limite_de_restitution(char date[255],int nbre_semaine){
int month,jour,ans;
switch(date[0]){
	case'J':if(date[1]=='a')month=1;
			 else if(date[2]=='l')month=7;
			 	
			 else{
			 	month=6;
			 }break;
	case'F':month=2;break;
	case'M':if(date[2]=='i')month=5;
			else month=3;break;
	case'A':if(date[1]=='p')month=4;
			else month=8;break;
	case'S':month=9;break;
	case'O':month=10;break;
	case'N':month=11;break;
	case'D':month=12;break;
default :break;	
}





int i=-1;
do{i++;
}while(date[i]!=' ');
i++;
if(date[i]==' '){
	jour=date[i+1]-48;}
else{
	jour=(date[i]-48)*10+date[i+1]-48;}
i+=3;
ans=(date[i]-48)*1000+(date[i+1]-48)*100+(date[i+2]-48)*10+(date[i+3]-48);


////////////////////////////////////////////////////////calcul de  la semaine prochaine/////////////////////////////////////////////////
for(int i=0;i<nbre_semaine;i++){
ajouter_une_semaine(&jour,&month,&ans);

}


char result[255];

strcpy(result,"");

	char par[10];
	itoa(jour,par,10);

	strcat(result,par);

	strcat(result,"  ");

	itoa(month,par,10);
	strcat(result,par);
	strcat(result,"  ");
	itoa(ans,par,10);
	strcat(result,par);
	
	

///////////////////////////////////////////////////////
return (char*)result;


}

void creer_emprunt(){
		
	printf("pour creer un nouveau emprunt s\'il vous plait suivre les etape suivantes:\n donner votre identificateur: ");
	FILE *pFile;
	FILE *fp;
    int nombre;
    char n[10];
    char strnombre[10];
    fp = fopen ("documents/emprunt/nombre_d_emprunt.txt","r");

	fscanf(fp,"%d",&nombre);
	fclose(fp);
	fp = fopen ("documents/emprunt/nombre_d_emprunt.txt","w");
	fprintf(fp,"%d",nombre+1);
	fclose(fp);
	scanf ("%s",n);
	char direction[100]="documents/emprunt/en_cours/";
	
	
	
	itoa(nombre,strnombre,16);
	
	
	strcat(direction,strnombre);
	strcat(direction,".txt");
	pFile = fopen(direction,"w");

///////////le remplissage  de la fiche;
	char direction2[100]="documents/adherant/informations/";
	strcat(direction2,n);
	char n2[255];
	strcpy(n2,n);
	strcat(direction2,".txt");
char texte[255];
	fp=fopen(direction2,"r");
	for(int i=0;i<3;i++){
	
	fgets(texte,255,fp);
	fprintf(pFile,"%s",texte);
	
}

	fgets(texte,255,fp);
	fgets(texte,255,fp);
	fprintf(pFile,"%s",texte);
	////////////////////////////////////////verification de la permission//////////////////////////////////////////////////
	char etat[255];
	fscanf(fp,"%s",etat);
	fscanf(fp,"%s",etat);
	if(strcmp(etat,"retardataire")==0){
		printf("vous ne pouvez pas emprunter un livre puisque vous  etes retardataire");
		return;
	}
	else {
	fgets(etat,255,fp);
	fgets(etat,255,fp);

	fscanf(fp,"%s",etat);
	fscanf(fp,"%s",etat);
	
		if(((strcmp(texte,"type: visiteur\n")==0) and (strcmp(etat,"0")!=0))or((strcmp(texte,"type: etudiant\n")==0) and (strcmp(etat,"2")>=0))or((strcmp(texte,"type: enseignant\n")==0) and ((strcmp(etat,"4")>=0))))
{
		printf("vous ne pouvez pas emprunter un livre puisque vous avez atteindre le nombre maximale de document permis");
		return;		

}

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	fclose(fp);
printf("quel est le code  unique du document a  emprunter: ");
scanf("%s",n);


char direction3[100]="documents/document/informations/";
	strcat(direction3,n);
	strcat(direction3,".txt");
	fp=fopen(direction3,"r");
char texte2[255];
for(int i=0;i<2;i++){
	
	fgets(texte2,255,fp);
	fprintf(pFile,"%s",texte2);
	
}




fprintf(pFile,"la_date_de_debut_d_emprunt_est:%s\n",__DATE__);

if(strcmp(texte,"type: enseignant\n")==0){

fprintf(pFile,"la_date_limite_de_restitution_est: %s\n",date_limite_de_restitution((char*)__DATE__,3));
}
else{
fprintf(pFile,"la_date_limite_de_restitution_est: %s\n",date_limite_de_restitution((char*)__DATE__,1));	
}

	fclose(fp);
	fclose(pFile);

/////////////////////////////////////////////augmenter le nbre des emprunts effectuer pour les adherants//////////////////////////////////

	FILE * fp2;

	char direction4[100]="documents/adherant/informations/";
	strcat(direction4,n2);
	strcat(direction4,".txt");
	fp2=fopen(direction4,"r");
	FILE * temp;
	char temprary_direction[100]="documents/fichier temporaire/temp.txt";
	temp=fopen(temprary_direction,"w");
	char transfert[255];
	for(int i=0;i<7;i++){
	fgets(transfert,255,fp2);
	fprintf(temp,"%s",transfert);
	}
	fscanf(fp2,"%s",transfert);
	fprintf(temp,"%s ",transfert);
	fscanf(fp2,"%s",transfert);
	int number=atoi(transfert);
	number++;
	itoa(number,transfert,10);
	fprintf(temp,"%s",transfert);
	
	fclose(fp2);
	fclose(temp);
	fp2=fopen(direction4,"w");
	temp=fopen(temprary_direction,"r");
	for(int i=0;i<8;i++){
	fgets(transfert,255,temp);
	fprintf(fp2,"%s",transfert);
	}
	fclose(fp2);
	fclose(temp);
	//remove("documents/fichier temporaire/temp.txt");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////augmenter le nbre des emprunts effectuer pour les documents/////////////////////////////////
	strcpy(direction4,"documents/document/informations/");
	strcat(direction4,n);
	strcat(direction4,".txt");
	fp2=fopen(direction4,"r");
	strcpy(temprary_direction,"documents/fichier temporaire/temp.txt");
	temp=fopen(temprary_direction,"w");
	for(int i=0;i<4;i++){
	fgets(transfert,255,fp2);
	fprintf(temp,"%s",transfert);
	}
	fscanf(fp2,"%s",transfert);
	
	fprintf(temp,"%s ",transfert);
	fscanf(fp2,"%s",transfert);
	//printf("%s",transfert);
	fprintf(temp,"%s",transfert);
	if(strcmp(transfert,"articles")==0){
	for(int i=0;i<3;i++){
	fgets(transfert,255,fp2);
	fprintf(temp,"%s",transfert);
	}	
	}
	else if(strcmp(transfert,"livres")==0){
	
	for(int i=0;i<4;i++){
	fgets(transfert,255,fp2);
	
		//printf("%s",transfert);
	fprintf(temp,"%s",transfert);
	}
}	
	else{
		fgets(transfert,255,fp2);
		fprintf(temp,"%s",transfert);
		//printf("%s",transfert);
		fgets(transfert,255,fp2);
		fprintf(temp,"%s",transfert);
	}
	fscanf(fp2,"%s",transfert);
	
	fprintf(temp,"%s ",transfert);
	
	fscanf(fp2,"%s",transfert);
	//printf("%s",transfert);
	
	number=atoi(transfert);
	number++;
	itoa(number,transfert,10);
	fprintf(temp,"%s",transfert);


	
	
	fclose(fp2);
	fclose(temp);
	fp2=fopen(direction4,"w");
	temp=fopen(temprary_direction,"r");
	char old_transfert[255];
	
	for(int i=0;i<9;i++){
	fgets(transfert,255,temp);

		if(strcmp(transfert,old_transfert)==0)break;
	strcpy(old_transfert,transfert);
	fprintf(fp2,"%s",transfert);
	}
	fclose(fp2);
	fclose(temp);

}

int compare_date(char fdate[255],char date[255]){
int month,jour,ans;
switch(date[0]){
	case'J':if(date[1]=='a')month=1;
			 else if(date[2]=='l')month=7;
			 	
			 else{
			 	month=6;
			 }break;
	case'F':month=2;break;
	case'M':if(date[2]=='i')month=5;
			else month=3;break;
	case'A':if(date[1]=='p')month=4;
			else month=8;break;
	case'S':month=9;break;
	case'O':month=10;break;
	case'N':month=11;break;
	case'D':month=12;break;
default :break;	
}
int i=-1;
do{i++;
}while(date[i]!=' ');
i++;
if(date[i]==' '){
	jour=date[i+1]-48;}
else{
	jour=(date[i]-48)*10+date[i+1]-48;}
i+=3;
ans=(date[i]-48)*1000+(date[i+1]-48)*100+(date[i+2]-48)*10+(date[i+3]-48);
	
int fmonth,fjour,fans;
i=-1;
do{i++;
}while(fdate[i]!=' ');
i++;
if(fdate[i]==' '){
	fmonth=fdate[i+1]-48;}
else{
	fmonth=(fdate[i]-48)*10+fdate[i+1]-48;}
if(fdate[1]!=' ')
{
fjour=(fdate[0]-48)*10+fdate[1]-48;
}
else{
fjour=fdate[0]-48;
}
i+=3;
fans=(fdate[i]-48)*1000+(fdate[i+1]-48)*100+(fdate[i+2]-48)*10+(fdate[i+3]-48);


///////////////////////
if(((fans<=ans) and (fmonth<=month)) and (fjour<=jour)){
	return 0;
	
}
return 1;


///////////////////////




}

void ecrire_retardataire(char dir[255]){
	FILE * sf;
	sf=fopen(dir,"r");
	FILE * tempor;
	tempor =fopen("documents/fichier temporaire/temp.txt","w");
	char te[255];
	
	for(int i=0;i<5;i++){
		fgets(te,255,sf);
		fprintf(tempor,"%s",te);
	}
	fgets(te,255,sf);
	fprintf(tempor,"etat: retardataire\n");
	for(int i=0;i<2;i++){
		fgets(te,255,sf);
		fprintf(tempor,"%s",te);
	}
	fclose(tempor);
	fclose(sf);
	
	sf=fopen(dir,"w");
	tempor =fopen("documents/fichier temporaire/temp.txt","r");
	for(int i=0;i<8;i++){
		fgets(te,255,tempor);
		fprintf(sf,"%s",te);
	}
	
fclose(sf);
fclose(tempor);	
	
	
	
}

void ecrire_ok_pour_tous(){
	FILE * sf;
	int number;
	FILE * nomb;
	nomb= fopen ("documents/adherant/nombre_de_participants.txt","r");
    
	fscanf (nomb,"%d",&number);
	fclose(nomb);

	for(int j=1;j<number;j++){
	

	char direction[255];
	strcpy(direction,"documents/adherant/informations/");
	char  ident[255];
	itoa(j,ident,10);
	strcat(direction,ident);
	strcat(direction,".txt");
	if(access( direction, F_OK ) != -1){
	
	sf=fopen(direction,"r");
	FILE * tempor;
	tempor =fopen("documents/fichier temporaire/temp.txt","w");
	char te[255];
	
	for(int i=0;i<5;i++){
		fgets(te,255,sf);
		fprintf(tempor,"%s",te);
	}
	fgets(te,255,sf);
	fprintf(tempor,"etat: OK\n");
	for(int i=0;i<2;i++){
		fgets(te,255,sf);
		fprintf(tempor,"%s",te);
	}
	fclose(tempor);
	fclose(sf);
	
	sf=fopen(direction,"w");
	tempor =fopen("documents/fichier temporaire/temp.txt","r");
	for(int i=0;i<8;i++){
		fgets(te,255,tempor);
		fprintf(sf,"%s",te);
	}

fclose(sf);
fclose(tempor);
}
	
}

}

void regler_le_nombre_d_emprunt_pour_adherant(char identite[255]){

	FILE * fp;
	FILE * temporaire;
	char dir[255]="documents/adherant/informations/";
	char txt[255];
	strcat(dir,identite);
	strcat(dir,".txt");
	fp=fopen(dir,"r");
	temporaire=fopen("documents/fichier temporaire/temp.txt","w");
	for(int i=0;i<6;i++){
		fgets(txt,255,fp);
		fprintf(temporaire,"%s",txt);
	}
	fscanf(fp,"%s",txt);
	fprintf(temporaire,"%s",txt);
	int num;
	fscanf(fp,"%d",&num);
	
	fprintf(temporaire," %d\n",num+1);
	fscanf(fp,"%s",txt);
	
	fprintf(temporaire,"%s",txt);
	fscanf(fp,"%d",&num);
	fprintf(temporaire," %d\n",num-1);
	
	
	fclose(fp);
	fclose(temporaire);
	fp=fopen(dir,"w");
	temporaire=fopen("documents/fichier temporaire/temp.txt","r");
	for(int i=0;i<8;i++){
		fgets(txt,255,temporaire);
		fprintf(fp,"%s",txt);
		
	}
	fclose(fp);
	fclose(temporaire);
	
	
}

void mise_a_jour(){
	
	
	ecrire_ok_pour_tous();
	
	FILE *fp;
	FILE *pFile;
    fp = fopen ("documents/emprunt/nombre_d_emprunt.txt","r");
    int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
	for(int i=1;i<nombre;i++){
		

	
	char direction[100]="documents/emprunt/en_cours/";
	char n[10];
	itoa(i,n,10);
	strcat(direction,n);
	strcat(direction,".txt");
	char texte[255];
	if(access( direction, F_OK ) != -1){
	pFile = fopen(direction,"r");
	fscanf(pFile,"%s",texte);
	fscanf(pFile,"%s",texte);
	char identifiant[50];
	strcpy(identifiant,texte);	
	for(int j=0;j<6;j++){
	
	fgets(texte,255,pFile);
}
	fscanf(pFile,"%s",texte);
	fgets(texte,255,pFile);
	if(compare_date(texte,(char*)__DATE__)==1){
	//////////////////ecrire retardataire////////////////////////////.
	char direction2[100]="documents/adherant/informations/";
	strcat(direction2,identifiant);
	strcat(direction2,".txt");
	ecrire_retardataire(direction2);
	////////////////////////////////////////////////////////////////	
   }	
  }
 }
}

void  effacer_emprunt(){
char id[255];
char  code_unique[255];
printf("donner le identifiant de l adherant");
scanf("%s",id);
printf("donner le code unique du document");
scanf("%s",code_unique);
////////////////////la recherche  de l emprunt avec l identifiant et le code unique du document donnée.
	FILE *fp;
    fp = fopen ("documents/emprunt/nombre_d_emprunt.txt","r");
    int nombre;
    fscanf (fp,"%d",&nombre);
	fclose(fp);
for(int i=1;i<=nombre;i++){
	char direction[100]="documents/emprunt/en_cours/";
	char n[10];
	char texte[255];
	itoa(i,n,10);
	strcat(direction,n);
	strcat(direction,".txt");
	if(access( direction, F_OK ) != -1){

	fp=fopen(direction,"r");
	fscanf(fp,"%s",texte);
	fscanf(fp,"%s",texte);
	if(strcmp(texte,id)==0){
		for(int j=0;j<4;j++){
			fgets(texte,255,fp);
		}
	fscanf(fp,"%s",texte);
	fscanf(fp,"%s",texte);
	if(strcmp(texte,code_unique)==0){
		///////////////////////////////////////////////////////////////////////on a trouver le fichier//////////////////////
		fclose(fp);
		remove(direction);	
		regler_le_nombre_d_emprunt_pour_adherant((char*)id);
	
	
	
	break;	
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	}
		
	}
	
}
if(i==nombre){
	printf("les information que vous avez entrer sont fausses");
fclose(fp);
}
}
	
}

