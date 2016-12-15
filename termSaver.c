#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/ioctl.h>
#include "functionsTermSaver.h"

int main(int argc, char* argv[]){
	switch (argc)
	{
		case 1://cas où le nombre d'arguments est egal à 1
			srand(time(NULL));
			switch (rand() % 3)
			{
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
					switch (pid)
					{
						case -1://dans le cas ou le fork() echou
							printf("error !\n");
							perror("fork");
							return 2;
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
					hourDateStorage();
					typeStorage("2");
					sizeDynamicStorage(getenv("EXIASAVER2_TAILLE"));
					char* argumentsForDynamic[] = { "dynamamicScreen", getenv("EXIASAVER2_SLEEP"), NULL };
					pid_t pid1 = fork();
					switch (pid1)
					{
						case -1:
							printf("error !\n");
							perror("fork");
							return 2;
							break;
						case 0:
							execvp("dynamicScreen", argumentsForDynamic);
							break;
						default:
							wait(NULL);
							break;
					}
					break;
				case 2:
					hourDateStorage();
					typeStorage("3");
					struct winsize w;
					ioctl(0, TIOCGWINSZ, &w);
					srand(time(NULL));
					//random des coordonnees de l'avion au lancement
					int a = rand() % w.ws_col - 3;
					int b = rand() % w.ws_row - 3;
					char firstParam[90];
					char secondParam[40];
					sprintf(firstParam, "%d", a);
					sprintf(secondParam, "%d", b);
					char* argumentsForInteractive[] = { "interactiveScreen", firstParam, secondParam, NULL };
					pid_t pid2 = fork();
					switch (pid2)
					{
						case -1:
							printf("error !\n");
							perror("fork");
							return 2;
							break;
						case 0:
							execvp("interactiveScreen", argumentsForInteractive);
							break;
						default:
							wait(NULL);
							break;
					}
					break;
				default:
					break;
			}
			break;
		case 2://cas ou le nombre d'arguments est egal à = 2
			if (strcmp(argv[1], "1") == 0)
			{		//si la chaine de caratère du deuxième argument
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
				switch (pid)
				{
					case -1:
						printf("error !\n");
						perror("fork");
						return 2;
						break;
					case 0:
						execvp("staticScreen", argumentsForStatic);
						break;
					default:
						wait(NULL);
						break;
				}
			}
			else if (strcmp(argv[1], "2") == 0)
			{
				hourDateStorage();
				typeStorage("2");
				sizeDynamicStorage(getenv("EXIASAVER2_TAILLE"));
				char* argumentsForDynamic[] = { "dynamamicScreen", getenv("EXIASAVER2_SLEEP"), NULL };
				pid_t pid1 = fork();
				switch (pid1)
				{
					case -1:
						printf("error !\n");
						perror("fork");
						return 2;
						break;
					case 0:
						execvp("dynamicScreen", argumentsForDynamic);
						break;
					default:
						wait(NULL);
						break;
				}

			}
			else if (strcmp(argv[1], "3") == 0)
			{
				hourDateStorage();
				typeStorage("3");
				struct winsize w;
				ioctl(0, TIOCGWINSZ, &w);
				srand(time(NULL));
				//random des coordonnees de l'avion au lancement
				int a = rand() % w.ws_col - 3;
				int b = rand() % w.ws_row - 3;
				char firstParam[90];
				char secondParam[40];
				sprintf(firstParam, "%d", a);
				sprintf(secondParam, "%d", b);
				char* argumentsForInteractive[] = { "interactiveScreen", firstParam, secondParam, NULL };
				pid_t pid = fork();
				switch (pid)
				{
					case -1:
						printf("error !\n");
						perror("fork");
						return 2;
						break;
					case 0:
						execvp("interactiveScreen", argumentsForInteractive);
						break;
					default:
						wait(NULL);
						break;
				}
			}
			break;
		case 3://cas ou le nombre d'arguments est egal à = 3
			if (strcmp(argv[1], "1") == 0)
			{
				hourDateStorage();
				typeStorage("1");
				staticImageStorage(argv[2]);
				if (argumentsCheck(argv[2]) == 1)
				{
					break;
					return EXIT_FAILURE;
				}
				char filePath[120];
				strcpy(filePath, getenv("EXIASAVER1_PBM"));
				strcat(filePath, "/");
				strcat(filePath, argv[2]);
				char* argumentsForStatic[] = { "staticScreen", filePath, NULL };
				pid_t pid = fork();
				switch (pid)
				{
					case -1:
						printf("error !\n");
						perror("fork");
						return 2;
						break;
					case 0:
						execvp("staticScreen", argumentsForStatic);
						break;
					default:
						wait(NULL);
						break;
				}
			}
			break;
		case 4://cas pour le type interactif qui demande 2 parametre de plus
			if (strcmp(argv[1], "3") == 0)
			{
				hourDateStorage();
				typeStorage("3");
				planeCoordonatesStorage(atoi(argv[2]), atoi(argv[3]));
				char* argumentsForInteractive[] = { "interactiveScreen", argv[2], argv[3], NULL };
				pid_t pid = fork();
				switch (pid)
				{
					case -1:
						printf("error !\n");
						perror("fork");
						return 2;
						break;
					case 0:
						execvp("interactiveScreen", argumentsForInteractive);
						break;
					default:
						wait(NULL);
						break;
				}
			}
			break;
		default:
			break;
	}
	return 0;
}