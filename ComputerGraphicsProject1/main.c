#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char tgStr[255];
    //create pointer to the file and "open", "read"
    //imgPtrIn : image pointer input
    //imgPtrIn will be input.ppm var
    FILE *imgPtrIn = fopen("image.ppm", "rb");
    //gather the first character (byte) from the image file
    int chr = fgetc(imgPtrIn);
    //if the character isn't equal to p, then it isn't a ppm file
    //other "errors" will go here
    if(chr != 'P')
    {
        //output error message to standard error
        fprintf(stderr, "Type is not PPM. \n");
    }

    //read file line by line
    while(fgets(tgStr, 255, imgPtrIn))
    {
        //ex:
        //fwrite(where from, size of element, num elements, stream);
        //will be output.ppm var
//        FILE *imgPtrOut;
//        imgPtrOut = fopen(outfilename, "wb");
//


//        printf(tgStr);
    }



    fclose(imgPtrIn);

    return 0;
}
