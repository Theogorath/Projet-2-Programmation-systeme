#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "interractif.h"
#define clear() printf("\033[H\033[2J")


 main(int argc, char* argv[])
{
    //permet de connaitre la taille de la console
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    clear ();
    srand(time(NULL));
    //random des coordonnees de l'avion au lancement
    //int a=rand()%w.ws_col - 3;
    //int b=rand()%w.ws_row - 3;

    int imgAleatoire=rand()%4+1; // permet de choisir une des 4 images de facon aléatoire

    int x= atoi(argv[1]); // coordonnees de l'image en paramètres
    int y= atoi(argv[2]);

    char direction=0;
    int lastDirection=0; //permet de connaitre la derniere direction choisie

    struct IMG ImgTest1 ;
    struct IMG ImgTest2 ;
    struct IMG ImgTest3 ;
    struct IMG ImgTest4 ;

    lireFichier("aviond.pbm", & ImgTest1 ) ;
    lireFichier("aviong.pbm", & ImgTest2 ) ;
    lireFichier("avionh.pbm", & ImgTest3 ) ;
    lireFichier("avionb.pbm", & ImgTest4 ) ;

//====================================================================
    //Choisir une image aleatoire au lancement
    if (imgAleatoire==1){
        affImage( ImgTest1,x,y ) ;
        lastDirection=1;
    }
    else if (imgAleatoire==2){
        affImage( ImgTest2,x,y ) ;
        lastDirection=2;
    }
    else if (imgAleatoire==3){
        affImage( ImgTest3,x,y ) ;
        lastDirection=3;
    }
    else if (imgAleatoire==4){
        affImage( ImgTest4,x,y ) ;
        lastDirection=4;
    }
//===================================================================
    while (1){
            //passer de l'autre coté de la console
            if(x>w.ws_col){ //droite
                x=0;
            }
            else if (x<0){ //gauche
                x=w.ws_col-1;
            }
            else if (y<0){ //haut
                y=w.ws_row-1;
            }
            else if (y>w.ws_row){ //bas
                y=0;
            }

        scanf ("%c" , &direction);
        //Change la direction et les coordonnees de l'avion
        if (direction=='d'){
            x=x+1;
            clear();
            affImage( ImgTest1,x,y ) ;
            lastDirection=1;
        }
        else if (direction=='g'){
            x=x-1;
            clear();
            affImage( ImgTest2,x,y ) ;
            lastDirection=2;
        }
        else if (direction=='h'){
            y=y-1;
            clear();
            affImage( ImgTest3,x,y ) ;
            lastDirection=3;
        }
        else if (direction=='b'){
            y=y+1;
            clear();
            affImage( ImgTest4,x,y ) ;
            lastDirection=4;
        }
        else if (direction=='q'){

            break;
        }
        else {       //Si aucune direction n'est choisie
            switch (lastDirection){
            case 1 : //Si l'avion allait a droite
                x=x+1;
                clear();
                affImage( ImgTest1,x,y ) ;
                break;
            case 2 : //Si l'avion allait a gauche
                x=x-1;
                clear();
                affImage( ImgTest2,x,y ) ;
                break;
            case 3 : //Si l'avion allait en haut
                y=y-1;
                clear();
                affImage( ImgTest3,x,y ) ;
                break;
            case 4 : //Si l'avion allait en bas
                y=y+1;
                clear();
                affImage( ImgTest4,x,y ) ;
                break;
            }

        }

    }
//=================================================

}

