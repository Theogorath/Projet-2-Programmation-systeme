#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/ioctl.h>
#define GRAPH "\033(0\033%@"
#define NOGRAPH "\033(B"

struct IMG
{   char magic[5] ;
	char** pixels;
	char* nomfichier ;
	int largeur;
	int longueur;
};

// typedef IMG * ptrIMG ;

void lireFichier( char *, struct IMG * ) ;

void affImage( struct IMG , int, int  ) ; // Une image, et positions X et Y
