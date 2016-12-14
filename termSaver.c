#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>


char* randomSelectStaticImage(void){//fonction utilisée pour sélectionner une image aléatoirement pour le type statique
	DIR* rep = NULL;
	struct dirent* ent = NULL;
	rep = opendir(getenv("EXIASAVER1_PBM"));
	int i = 0 /* i représente le compteur de fichier du répertoire rep */, j = 0;
	char** fileTable = NULL;
	while ((ent = readdir(rep)) != NULL){
		if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){
			i++;
		}
	}
	fileTable = malloc(i * sizeof(char*));
	rewinddir(rep);
	for (j = 0; j < i; j++){
		ent = readdir(rep);
		if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){
			fileTable[j] = ent->d_name;
		}
		else{
			j--;
		}
	}
	srand(time(NULL));
	int randomValue = rand() % i;
	rewinddir(rep);
	closedir(rep);
	return fileTable[randomValue];
}

int argumentsCheck(char* argvulu){
	int i = 0;
	DIR* rep = NULL;
	struct dirent* ent = NULL;
	rep = opendir(getenv("EXIASAVER1_PBM"));
	while ((ent = readdir(rep)) != NULL){
		if (strcmp(argvulu, ent->d_name) == 0){
			i++;
		}
	}
	if (i > 0){
		return 0;
	}
	else{
		printf("Le fichier choisi n'existe pas.\nVeuillez un choisir un autre.\nVoici la liste des fichiers dans le repertoire %s :\n", getenv("EXIASAVER1_PBM"));
		system("ls $EXIASAVER1_PBM");
		return 1;
	}
}

void hourDateStorage(void){
	time_t seconds;
	struct tm now;
	time(&seconds);
	now = *localtime(&seconds);
	FILE* history = NULL;
	history = fopen("/home/exia/PROJET2/history.txt", "a");
	fprintf(history, "%d/%d/%d %d:%d:%d;", now.tm_mday, now.tm_mon + 1, (now.tm_year - 100) + 2000, now.tm_hour, now.tm_min, now.tm_sec);
	fclose(history);
}

void typeStorage(char* type){
	FILE* history = NULL;
	history = fopen("/home/exia/PROJET2/history.txt", "a");
	fprintf(history, "%s;", type);
	fclose(history);
}

void staticImageStorage(char* usedImage){
	FILE* history;
	history = fopen("/home/exia/PROJET2/history.txt", "a");
	fprintf(history, "%s&\n", usedImage);
	fclose(history);
}


int main(int argol, char* argvol[]){
	switch (argol){
		case 1://cas où le nombre d'arguments est égal à 1
			srand(time(NULL));
			switch (rand() % 3){
				case 0://exécute le screen saver statique avec une image choisie au hasard
					hourDateStorage();
					typeStorage("1");
					char fileName[80];
					strcpy(fileName, randomSelectStaticImage());
					staticImageStorage(fileName);
					char* argumentsForStatic[] = { "exectest", "1" , fileName, NULL };
					pid_t pid = fork();
					switch (pid){
						case -1:
							printf("error !\n");
							perror("fork");
							return EXIT_FAILURE;
							break;
						case 0:
							execvp("exectest", argumentsForStatic);
							break;
						default:
							wait(NULL);
							break;
					}
					break;
				case 1:




					break;
				case 2:




					break;
				default:
					break;
			}
			break;
		case 2://cas où le nombre d'arguments est égal à = 2
			if (strcmp(argvol[1], "1") == 0){
				hourDateStorage();
				typeStorage("1");
				char fileName[80];
				strcpy(fileName, randomSelectStaticImage());
				staticImageStorage(fileName);
				char* argumentsForStatic[] = { "exectest", argvol[1], fileName , NULL };
				pid_t pid = fork();
				switch (pid){
					case -1:
						printf("error !\n");
						perror("fork");
						return EXIT_FAILURE;
						break;
					case 0:
						execvp("exectest", argumentsForStatic);
						break;
					default:
						wait(NULL);
						break;
				}
			}
			else if (strcmp(argvol[1], "2") == 0){



			}
			else if (strcmp(argvol[1], "3") == 0){



			}
			break;
		case 3://cas où le nombre d'arguments est égal à = 3
			if (strcmp(argvol[1], "1") == 0){
				hourDateStorage();
				typeStorage("1");
				staticImageStorage(argvol[2]);
				if (argumentsCheck(argvol[2]) == 1){
					break;
					return EXIT_FAILURE;
				}
				char* argumentsForStatic[] = { "exectest", argvol[1], argvol[2], NULL };
				pid_t pid = fork();
				switch (pid){
					case -1:
						printf("error !\n");
						perror("fork");
						return EXIT_FAILURE;
						break;
					case 0:
						execvp("exectest", argumentsForStatic);
						break;
					default:
						wait(NULL);
						break;
				}

				break;
		default:
			break;
			}
	}
	return 0;
}