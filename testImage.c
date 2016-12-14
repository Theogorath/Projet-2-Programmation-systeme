#include <stdlib.h>
#include <stdio.h>
#include "image.h"

 int main(int argc, char* argv[])
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    struct IMG ImgTest1 ;
    lireFichier(argv[1], & ImgTest1 ) ;

    // centrer l'image

    affImage( ImgTest1, (w.ws_col/2)-(ImgTest1.largeur/2), (w.ws_row/2)-(ImgTest1.longueur/2) ) ;

    //printf ("columns %d\n", w.ws_col);
    //printf ("lines %d\n", w.ws_row);
	scanf("%c");
	system("clear");
	return 0;
}

