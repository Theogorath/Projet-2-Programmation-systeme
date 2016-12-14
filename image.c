#include <string.h>
#include <sys/ioctl.h>
#include "image.h"
#define MAX_LEN 80

void lireFichier( char * nomFic, struct IMG * Img )
{
    FILE *fptr = NULL;
    char buf[MAX_LEN];   // read buffer
    int i, j ;          // indice du tableau pixels
    // Test de l'ouverture
    if((fptr = fopen(nomFic,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",nomFic);
        return ;
    }
    // lecture magic number
    fgets( buf, MAX_LEN, fptr) ;
    // supprime le \n :
    buf[strlen(buf)-1] = 0 ;
    strcpy( Img->magic, buf ) ;
    // lire les dimensions
    fgets( buf, MAX_LEN, fptr) ;
    sscanf( buf, "%d %d", &Img->largeur, &Img->longueur ) ;


    // malloc du tableau a 2 dimensions
    Img->pixels = malloc( sizeof(int *) * Img->longueur ) ;
    for( i = 0; i < Img->longueur ; i++ )
    { Img->pixels[i] = malloc( sizeof(int) * Img->largeur ) ;
    }

    // lecture des valeurs
    for( i=0; i<Img->longueur; i++ )
    {   fgets( buf, MAX_LEN, fptr) ;
        for( j=0; j < Img->largeur; j++ )
        {  Img->pixels[i][j] = buf[2*j] ;

        }
    }

}

void affImage( struct IMG Img , int x, int y  )  // Une image, et positions X et Y
{ int i, j, k;
  char c ;
    //printf("%s %d %d\n", Img.magic, Img.largeur, Img.longueur ) ;
    // affichage du tableau :
  // décalage vers Y
  for( i = 0 ; i < y ; i++ ) printf("\n") ;

  for( i=0; i< Img.longueur ; i++ )
  {   for( k=0; k< x; k++ ) printf(" ") ;   // décalage à gche
      for( j=0;j<Img.largeur; j++ )
      {   c = ( Img.pixels[i][j] == '0' ) ? ' ' : '0' ;
          printf("%s%c%s", GRAPH, c, NOGRAPH ) ;
      }
      putc('\n', stdout ) ;
  }
}
