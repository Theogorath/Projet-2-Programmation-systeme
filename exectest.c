#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	printf("Programme lance %s de type %s.\n", argv[0], argv[1]);
	printf("Le fichier selectione est %s\n", argv[2]);
	return 0;
}