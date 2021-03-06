#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "fonction.h"
#define HISTORIQUE "history.txt"
int main(int argc, char*argv[]){
    //Declaration des variable
	int menuChoice;
	//Initialisation des variables
	menuChoice = 0;
	system("clear");//vide le terminal
	if(argc == 2 && strcmp(argv[1],"-stats") ==0){//verifie si il y a deux argument et si le deuxieme arg est egale a "-stats"
		system("clear");//vide le terminal
		//affiche un menue de choix
		puts("##########################\n");
		puts("            MENU          \n");
		puts("##########################\n");
		puts("<1> trier par date en ordre croissant\n");
		puts("<2> trier par date en ordre decroissant\n");
		puts("<3> Trier par type\n");
		puts("<4> Nombre de fois que les ecran on ete lancer\n");
		puts("<5> Quitter");
		//recupere le choix tape
		scanf("%d",&menuChoice);
        switch(menuChoice){//selon le choix tape on fait :
            //trier par date croissante
            case 1:
                increasingDateSort();
                break;
            //trier par date decroissante
            case 2:
                decreasingDateSort();
                break;
            //trier par type
            case 3:
                typeSorting();
                break;
            //nombre de type
            case 4:
                 numberOfType();
                break;
            // quitte le lanceur
            case 5:
               system("clear");
                puts("BYE");
                break;
            //si on se trompe
            default:
                puts("erreur lors du choix");
                sleep(3);
                char* launcher[] = {"exiaSaver", argv[1], NULL};//declaration locale de l'argument pour l'execvp ci-dessous
                execvp("exiaSaver", launcher);//execute une nouvelle fois exiaSaver
                break;
        }
	}else if(argc == 2 ){//sinon si il y a deux argument
		char* termsaver[] = {"termSaver", argv[1], NULL};
		switch(atoi(argv[1])){//lancer le programme suivant suivant le second argument
			//ecran statique parametre statique
			case 1:
                execvp("termSaver", termsaver);
				//puts("ecranStatique via termsaver avec parametre");
				break;
            //ecran dynamique parametre dynamique
			case 2:
                execvp("termSaver", termsaver);
				break;
            //ecran interactif parametre interactif
			case 3:
				execvp("termSaver", termsaver);
				break;
            // si on a tape un mauvais argument
			default:
				puts("erreur lors du choix de l ecran a lancer mettre le man\n");//on affiche l'erreur
				return 1;//on retourne une erreur
				break;
        }
    }else if(argc == 3){//si il y a trois arguments
		char* termsaver1[] = { "termSaver", argv[1], argv[2], NULL };//argument pour lancer un type statique et afficher l'image voulue
		switch(atoi(argv[1])){//lancer le programme suivant en fonction le second argument
				//ecran statique parametre statique et argv[2]
			case 1:
				
				execvp("termSaver", termsaver1);
				//puts("ecranStatique via termsaver avec parametre");
				break;			
            //ecran interactif parametre interactif et argv[2]
			case 3:
				execvp("termSaver", termsaver1);
				//puts("ecranInteractif via termsaver avec parametre");
				break;
            // si l argument est bizarre on c est tromper sur l'argument
			default:
				puts("erreur lors du choix de l ecran a lancer mettre le man");
				return 1;
				break;
        }
    }else {//sinon lancer le termSaver no parametre
         execvp("termSaver", argv); 
		}
	return 0;
}
