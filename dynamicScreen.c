#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/ioctl.h>

int main(int argc, char* argv[])
{
	//obtenir l'heure courante
	time_t courant;// courant est �gale � l'heure
	char chaine[10];
	//sizeof "HH:MM:SS" cr�er une chaine de taille d�finie 
	int a;// permet de centre l'affichage sinon on aura une erreure de segmentation
		  // n : periode d'affichage de l'heure. i : nbre de secondes dans la boucle
	int n;
	if (argc == 2)
	{
		n = atoi(argv[1]);//temps d'attente
	}
	else
	{
		n = 10;//pour tester l'executable sans parametre
	}
	int i;
	courant = time(NULL);
	i = courant % n;// d�calage entre l'heure courante et n 
	while (1)
	{
		//convertir l'heure locale au format HH:MM:SS
		if (((courant - i) % n) == 0)
		{
			system("clear");// effacer � chaque  tour de boucle l'heure pr�c�dente
			strftime(chaine, sizeof(chaine), "%H:%M:%S\n", localtime(&courant));
			//recupere l'heure du systeme et l'actualis� tout les n secondes
			printf("%*s\n\n\n\n\n\n\n\n\n\n\n\n", a, chaine);
			printf("cet �cran sera actualis� dans %d secondes ", n);
			fflush(stdout);//force l'�criture de l'espace donn�es en m�moire tampon
		}
		printf(".");
		fflush(stdout);
		sleep(1);
		courant = time(NULL);
	}
	return 0;
}