#include <stdio.h>
#include <stdlib.h>
//#include "declaration.h"

//original
/*int main(){
	FILE* picture = NULL;
	picture = fopen("/STATICSAVER/ex1.pbm", "r");


	return 0;
}*/

//plOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP  ^^.

int main(){

	double column1, column2;//Temp variables for readingline from data file
	char line[999999]; //width of line parameter for fgets
	//a trouver la taille a alloué a line[] (tableau de char)
	//peut se faire par *char

	FILE *picture;
	picture = fopen("/STATICSAVER/ex1.pbm", "r");//Open data file
	int before = 2; //for skipping the first 2 lines of data file
	int skip = 0;

	while (fgets(line, sizeof line, picture) != NULL) //get each line from data file till EOF
	{
		if (skip < before)//skip first 2 lines
		{
			skip++;
		}
		else{
			//read the 2 data values on line from file into  column vaiables.
			//sscanf(line, "%lf %lf", &column1, &column2);
			
			//doc pour lire sscanf https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
			

		}

	}

	fclose(picture);

	return 0;
}