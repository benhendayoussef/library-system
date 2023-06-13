#define clear system("cls")
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>



void gotoxy(int x,int y){

for(int i=0;i<y;i++)
printf("\n");
for(int j=0;j<y;j++)
printf(" ");



}

void affiche(char *te,int x,int y){
	static int actual_x,actual_y;
	if(y!=actual_y)actual_x=0;
	for(actual_y;actual_y<y;actual_y++){
		printf("\n");
	}
	for(actual_x;actual_x<x;actual_x++){
		printf(" ");
	}
	printf("%s",te);
}


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void affiche_logo(char direct[]){
	FILE * logo;
	logo = fopen(direct,"r");
	while(!feof(logo)){
	char ligne[200];
	fgets(ligne,255,logo);
	int i=0;
	Color(15,15);
	printf("............................");
	do{
		if(ligne[i]=='#'){
		Color(1,1);
		}
		else{
			Color(15,15);
		}
	printf("%c",ligne[i]);
	i++;	
	}while(ligne[i]!='\0');
	}
	
	
			Color(15,0);
}




