#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include "functionsTermSaver.h"

int main(int argc, char* argv[]){
	switch (argc){
		case 1://cas où le nombre d'arguments est egal à 1
			srand(time(NULL));
			switch (rand() % 3){
				case 0://execute le screen saver statique avec une image choisie au hasard
					hourDateStorage();
					typeStorage("1");
					char fileName[80];
					strcpy(fileName, randomSelectStaticImage());//fileName prend la valeur de randomSelectStaticImage() c'est a dire le nom du fichier choisi
					char filePath[120];//on va concatener des chaines de caracteres pour obtenir le chemin absolu vers les fichiers
					strcpy(filePath, getenv("EXIASAVER1_PBM"));//on utilise la variable d'environnement creee pour cela
					strcat(filePath, "/");
					strcat(filePath, fileName);
					staticImageStorage(fileName);
					char* argumentsForStatic[] = { "staticScreen", filePath, NULL };//argument pour l'execvp
					pid_t pid = fork();//on cree un processus fils
					switch (pid){
						case -1://dans le cas ou le fork() echou
							printf("error !\n");
							perror("fork");
							return EXIT_FAILURE;
							break;
						case 0://dans le cas du processus fils
							execvp("staticScreen", argumentsForStatic);
							break;
						default://dans le cas du processus pere
							wait(NULL);
							break;
					}
					break;
				case 1:

					puts("blblblb dyn rand\n");


					break;
				case 2:

					puts("blblblb int rand\n");


					break;
				default:
					break;
			}
			break;
		case 2://cas ou le nombre d'arguments est egal à = 2
			if (strcmp(argv[1], "1") == 0){		//si la chaine de caratère du deuxième argument
				hourDateStorage();					//exécute le screen saver statique avec une image choisie au hasard
				typeStorage("1");
				char fileName[80];
				strcpy(fileName, randomSelectStaticImage());
				char filePath[120];
				strcpy(filePath, getenv("EXIASAVER1_PBM"));
				strcat(filePath, "/");
				strcat(filePath, fileName);
				staticImageStorage(fileName);
				char* argumentsForStatic[] = { "staticScreen", filePath , NULL };
				pid_t pid = fork();
				switch (pid){
					case -1:
						printf("error !\n");
						perror("fork");
						return EXIT_FAILURE;
						break;
					case 0:
						execvp("staticScreen", argumentsForStatic);
						break;
					default:
						wait(NULL);
						break;
				}
			}
			else if (strcmp(argv[1], "2") == 0){

				puts("blblblb dyn\n");

			}
			else if (strcmp(argv[1], "3") == 0){

				puts("blblblb int\n");

			}
			break;
		case 3://cas ou le nombre d'arguments est egal à = 3
			if (strcmp(argv[1], "1") == 0){
				hourDateStorage();
				typeStorage("1");
				staticImageStorage(argv[2]);
				if (argumentsCheck(argv[2]) == 1){
					break;
					return EXIT_FAILURE;
				}
				char filePath[120];
				strcpy(filePath, getenv("EXIASAVER1_PBM"));
				strcat(filePath, "/");
				strcat(filePath, argv[2]);
				char* argumentsForStatic[] = { "staticScreen", filePath, NULL };
				pid_t pid = fork();
				switch (pid){
					case -1:
						printf("error !\n");
						perror("fork");
						return EXIT_FAILURE;
						break;
					case 0:
						execvp("staticScreen", argumentsForStatic);
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