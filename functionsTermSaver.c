#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include "functionsTermSaver.h"

char* randomSelectStaticImage(void){//fonction utilisée pour sélectionner une image aléatoirement pour le type statique
	DIR* rep = NULL;
	struct dirent* ent = NULL;
	rep = opendir(getenv("EXIASAVER1_PBM"));//ouvre le repertoire ou se situent les images du type statique
	int i = 0 /* i représente le compteur de fichier du répertoire rep */, j = 0;
	char** fileTable = NULL;//on prépare un tableau de char*
	while ((ent = readdir(rep)) != NULL){//on lit tous les fichiers du repertoire
		if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){//on ne prend pas en compte les fichier "." et ".."
			i++;
		}
	}
	fileTable = malloc(i * sizeof(char*));//on alloue la mémoire necessaire pour stocker le nombre exaxte de fichier du repertoire
	rewinddir(rep);//on revient au début du repertoire
	for (j = 0; j < i; j++){//boucle pour remplir toutes les cases du tableau
		ent = readdir(rep);
		if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){//on ne prend pas "." et ".."
			fileTable[j] = ent->d_name;
		}
		else{
			j--;//si le fichier lu est "." ou ".." on decrement j pour ne pas avoir de case pointant vers NULL en trop
		}
	}
	srand(time(NULL));
	int randomValue = rand() % i;//pour choisir une case du tableau au hasard
	rewinddir(rep);
	closedir(rep);//on ferme le repertoire
	return fileTable[randomValue];//on retourne une chaine de caractères au hasard correspondant au nom d'un des fichiers
}

int argumentsCheck(char* argvulu){//fonction pour empecher d'envoyer un mauvais parametre
	int i = 0;
	DIR* rep = NULL;
	struct dirent* ent = NULL;
	rep = opendir(getenv("EXIASAVER1_PBM"));
	while ((ent = readdir(rep)) != NULL){
		if (strcmp(argvulu, ent->d_name) == 0){//parcourt tous les fichiers du repertoire et compare le parametre du nom et le nom des fichier
			i++;//si le parametre du nom correspond bien au nom d'un fichier i est incremente
		}
	}
	if (i > 0){
		return 0;//si i > 0 on renvoi 0 pour dire qu'il n'y a pa eu de probleme
	}
	else{
		printf("Le fichier choisi n'existe pas.\nVeuillez un choisir un autre.\nVoici la liste des fichiers dans le repertoire %s :\n", getenv("EXIASAVER1_PBM"));
		system("ls $EXIASAVER1_PBM");
		return 1;//sinon on revoi une erreur
	}
}

void hourDateStorage(void){//fonction ecrivant la date et l'heure au format jj/mm/aa hh:mm:ss; dans le fichier historique
	time_t seconds;//variable pour les secondes
	struct tm now;//structure tm d'allias now
	time(&seconds);
	now = *localtime(&seconds);
	FILE* history = NULL;
	history = fopen("/home/exia/PROJET2/history.txt", "a");//on ouvre le fichier historique et on ecrit à la fin du fichier
	fprintf(history, "%d/%d/%d %d:%d:%d;", now.tm_mday, now.tm_mon + 1, (now.tm_year - 100) + 2000, now.tm_hour, now.tm_min, now.tm_sec);
	fclose(history);
}

void typeStorage(char* type){//fonction ecrivant le type de screen saver lance dans le fichier historique
	FILE* history = NULL;
	history = fopen("/home/exia/PROJET2/history.txt", "a");
	fprintf(history, "%s;", type);
	fclose(history);
}

void staticImageStorage(char* usedImage){//fichier ecrivant l'image utilisee pour le screen saver statique dans le fichier historique
	FILE* history = NULL;
	history = fopen("/home/exia/PROJET2/history.txt", "a");
	fprintf(history, "%s&\n", usedImage);
	fclose(history);
}