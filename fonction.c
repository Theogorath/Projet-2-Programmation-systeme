
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "fonction.h"
#define HISTORIQUE "historique.txt"
void numberOfType(){
    // declaration et initialisation des variables
    FILE* file = NULL;
    int readCharacter = 0;
    int type = 0;
    int staticNumber = 0, dynamicNumber = 0, interactifNumber = 0;
    system("clear");//nettoyage du terminal
    file = fopen(HISTORIQUE,"r");//ouvrir le fichier historique.txt en droit de lecture et recuperer sa valeur
    if(file == NULL){//verifie si le fichier c est bien ouvert
        printf("erreur lors de l'ouverture du fichier historique.txt");//message d erreur d ouverture du fichier
    }else{
        while(readCharacter != EOF){//lit le fichier jusqu'au caractere de fin
            readCharacter = fgetc(file);//lit un caractere du fichier
                if(readCharacter == 59){//si le caractere est un point virgule 59 code ascii du ';'
                    type = fgetc(file);// prend le caractere apres le point virgule
                    if(type == 49){//si le caractere est 1
                        staticNumber++;//augmente le nombre de statique de 1
                    }else if(type == 50){//si le caractere est 2
                        dynamicNumber++;//augmente le nombre de dynamique de 1
                }else if(type == 51){//si le caractere est 3
                        interactifNumber++;//augmente le nombre d interactif de 1
                }
            fgetc(file);

            }
        }
    }
    //affiche le resultat obtenus
    printf("Il y a eu :\n\
           %d ecrans statiques\n\
           %d ecrans dynamiques\n\
           %d ecrans interactifs\n\
           lancer, pour un total de %d ecrans\n",staticNumber,dynamicNumber,interactifNumber,staticNumber+dynamicNumber+interactifNumber);
    //ferme le fichier
    fclose(file);
}
void typeSorting(){
    //declaration et initialsation des variables
    FILE* file = NULL;
    char strTemp[255];
    char currentChar;
    int line, count;
    system("clear");//nettoyage ecran
    file = fopen(HISTORIQUE,"r");//ouvrir le fichier historique.txt en droit de lecture et recuperer sa valeur
    if(file == NULL){//verifie si le fichier c est bien ouvert
        printf("erreur lors de l'ouverture du fichier historique.txt");//message d erreur d ouverture du fichier
    }else{
        for(line = 0; fgets(strTemp, 255, file) != NULL; line++){}//compteur de nombre de ligne
        int tabHis[line+1][2];//creation du tabHis
        rewind(file);//remet le curseur en debut de fichier
        for(count = 0; count < line; count++){//lit tout les fichier lgne par ligne
            while(currentChar != 59){//tant que le caractere lut n est pas un ; ascii 59
                currentChar = fgetc(file);//lit un caracter est le stocke dans le cureentChar
            }
            currentChar = fgetc(file);//lit un caractere est le stocke dans le cureentChar
            tabHis[count][0] = currentChar-48;//stocke le caractere
            tabHis[count][1] = count;//stocke le nombre du compteur
            currentChar = fgetc(file);//lit un caractere
            currentChar = fgetc(file);//lit un caractere
        }
        //trie bubble sort
        int i,j,tempValue1, tempValue2;
        for(j = line; j > 0; j--){
            for(i = 0; i < j - 1; i++){
                if(tabHis[i][0] > tabHis[i + 1][0]){
                    tempValue1 = tabHis[i][0];
                    tempValue2 = tabHis[i][1];
                    tabHis[i][0] = tabHis[i+1][0];
                    tabHis[i][1] = tabHis[i+1][1];
                    tabHis[i+1][0] = tempValue1;
                    tabHis[i+1][1] = tempValue2;
                }
            }
        }
        //
        for(i = 0; i < line; i++){
            rewind(file);//remet le cusrseur au debut du fichier
            for(j = 0; j <= tabHis[i][1]; j++){
                fgets(strTemp, 255, file);//STOCKE la ligne du compteur
            }
            printf("%s", strTemp);//affiche le resultat
        }
    }
}
void decreasingDateSort(){
    FILE* file = NULL;
    char line[255]="";
    system("clear");//nettoyage du terminal
    file = fopen(HISTORIQUE,"r");//ouvrir le fichier historique.txt en droit de lecture et recuperer sa valeur
    if(file == NULL){//verifie si le fichier c est bien ouvert
        printf("erreur lors de l'ouverture du fichier historique.txt");//message d erreur d ouverture du fichier
    }else{
        while(fgets(line,255,file)!=NULL){
            printf("%s",line);
        }
    }
    fclose(file);
}
void increasingDateSort(){
    //declaration et initialsation des variables
    FILE* file = NULL;
    char strTemp[255];
    int line;
    int x, y =0;
    system("clear");//nettoyage ecran
    file = fopen(HISTORIQUE,"r");//ouvrir le fichier historique.txt en droit de lecture et recuperer sa valeur
    if(file == NULL){//verifie si le fichier c est bien ouvert
        printf("erreur lors de l'ouverture du fichier historique.txt");//message d erreur d ouverture du fichier
    }else{
        for(line = 0; fgets(strTemp, 255, file) != NULL; line++){}//compteur de nombre de ligne
        char *tab[line];

        for(x=line;x>0; x--)
        {
            rewind(file);
            for(y = 0;   y < x; y++ ){
                fgets(strTemp, 255, file);
            }
            printf("%s", strTemp);
        }
    }
}
