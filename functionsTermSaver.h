#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

char* randomSelectStaticImage(void);
int argumentsCheck(char* argvulu);
void hourDateStorage(void);
void typeStorage(char* type);
void staticImageStorage(char* usedImage);
void sizeDynamicStorage(char* imhSize);
void planeCoordonatesStorage(int posX, int posY);