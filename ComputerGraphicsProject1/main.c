#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tgStr[25];
    //create image pointer and "open", "read" into program
    FILE * imgPtr = fopen("image.ppm", "r");
    //gather the first character from the image file
    int chr = fgetc(imgPtr);
    //if the character isn't equal to p, then it isn't a ppm file
    //other "errors" will go here
    if(chr != 'P')
    {
        //output error message to standard error
        fprintf(stderr, "Type is not PPM. \n");
    }

    //read file line by line
    while(fgets(tgStr, 25, imgPtr))
    {
//          printf(tgStr);
        if(imgPtr = 6)
        {
            //printf("test\n");
            imgPtr = fopen("image.ppm", "w");
            fputs("test",imgPtr);
            //printf(imgPtr);

        }
    }


    fclose(imgPtr);

    return 0;
}
