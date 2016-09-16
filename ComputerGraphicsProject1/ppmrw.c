#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //declare pixel buffer
    char *pixBuffer;
    int width;
    int height;

    //ignore argv[0]
    //input file to read from
    FILE* input = fopen(argv[2], "rb");
    //output file to write to
    FILE* output = fopen(argv[3], "wb");

//    int chr = fgetc(input);

    //return error if files aren't there
    if(input == NULL)
    {
        fprintf(stderr, "ERROR:  File(s) does not exist. \n");
    }

//    else if(chr != 'P')
//    {
//        fprintf(stderr, "ERROR: Type is not PPM. \n");
//    }
    int chr = fgetc(input);
    if(chr != 'P')
    {
        fprintf(stderr, "ERROR: Type is not PPM. \n");
    }
    //p3 or p6 format
    chr = fgetc(input);
//    printf("%c", chr);

    if(chr == '3')
    {
        //p3 to p6
        printf("P3 format found\n");
        //read in next number
        //file handle, format specifier, address of value
        //comments
        /*
            #created by gimp \n
            c = fgetc()
            if(c=="#"){while(){ fgetcs until I come to new line}}
        */
//        int chr = fgetc(input);
        fgetc(input); //to do: skip whitespace
        //check for comments after any number
        char c = fgetc(input);
        if(c == '#')
        {
            while(c != '\n')
            {
                //c = fgetc
                c = fgetc(input);

            }
        }
        //width
        int width;
        fscanf(input, "%d",&width);
        //height
        int height;
        fscanf(input, "%d", &height);

        //max number
        int maxNum;
        fscanf(input, "%d", &maxNum);

        fgetc(input); //hack for whitespace - go back and make while loop for header
        //pixel buffer
        unsigned char *pixBuffer;
        pixBuffer = malloc(width * height * 3);
        //for loop i = width * height * depth
        int i;
        for(i = 0; i < width * height * 3; i ++)
        {
            fscanf(input, "%d", &pixBuffer[i]);
        }
        fclose(input);

        //header
        fprintf(output, "P6 %d %d %d ", width, height, 255);
        fwrite(pixBuffer, sizeof(unsigned char), width * height * 3, output);

        fclose(output);

    }


    return 0;
}
