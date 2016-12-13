#include "image.h"

main()
{   struct IMG ImgTest1/*, ImgTest2*/ ;
    lireFichier("ex2.pbm", & ImgTest1 ) ;
    //lireFichier("ex3.pbm", & ImgTest2 ) ;
    // centrer l'image
    affImage( ImgTest1, 10, 5 ) ;
    //affImage( ImgTest2, 25, 0 ) ;
}
