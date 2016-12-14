#include<stdio.h>
//#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char*argv[]){
    //Dclaration des variable
	int menuChoice;
	//Initialisation des variables
	menuChoice = 0;
	system("clear");//vide le terminal
	if(argc == 2 && strcmp(argv[1],"-stats") ==0){//verifie si il y a deux argument et si le deuxieme arg est egale a -stats
		system("clear");//vide le terminal
		//affiche un menue de choix
		puts("##########################\n");
		puts("            MENU          \n");
		puts("##########################\n");
		puts("<1> trier par date en ordre croissant\n");
		puts("<2> trier par date en ordre decroissant\n");
		puts("<3> Trier par type\n");
		puts("<4> Trier par value\n");
		puts("<5> Nombre de fois que les ecran on ete lancer\n");
		puts("<6> Quitter");
		//recupere le choix taper
		scanf("%d",&menuChoice);
        switch(menuChoice){//selon le choix taper on fait :
            //trier par date croissante
            case 1:
                puts("trier par date croissante");
                break;
            //trier par date decroissante
            case 2:
                puts("trier par date decroissante");
                break;
            //trier par type
            case 3:
                puts("trier par type");
                break;
            //trier par value
            case 4:
                puts("trier par value");
                break;
            //trier par nombre de type
            case 5:
                puts("Nombre de lancement des ecrans");
                break;
            // quit le lanceur
            case 6:
                system("clear");
                puts("BYE");
                break;
            //si on se trompe
            default:
                puts("erreur lors du choix");
                sleep(3);
                system("./launcher -stats");
                break;
        }
	}else if(argc == 2 ){//sinon si il y a deux argument
		switch(atoi(argv[1])){//lancer le programme suivant suivant le second argument
			//ecran statique
			case 0:
				puts("ecranStatique via termsaver avec parametre");
				break;
            //ecran dynamique
			case 1:
				puts("ecranDynamique via termsaver avec parametre");
				break;
            //ecran interactif
			case 2:
				puts("ecranInteractif via termsaver avec parametre");
				break;
            // si l argument on c est tromper sur l'argument
			default:
				puts("erreur lors du choix de l ecran a lancer mettre le man");
				return 1;
				break;
        }
    }else {//sinon lancer le termSaver
        puts("lancer le term saver et faire l'historique");
		}
	return 0;
}
