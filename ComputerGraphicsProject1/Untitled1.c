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
//        printf("height =%d\n", height);
        //max number
        int maxNum;
        fscanf(input, "%d", &maxNum);
//        printf("maxNum =%d\n", maxNum);
        fgetc(input); //hack for whitespace - go back and make while loop for header

        //pixel buffer
        unsigned int *pixBuffer;
        pixBuffer = (unsigned int *)malloc(width * height * 3);
        //for loop i = width * height * depth
        int i;
        for(i = 0; i < width * height * 3; i ++)
        {
            fscanf(input, "%d", pixBuffer);
//            fwrite(pixBuffer, sizeof(int), sizeof(pixBuffer), output);
        }
//        printf("%d", pixBuffer);
        int c = fgetc(input);
        int i = 0;
        while(c = ' ')
        {
            pixBuffer[i] = c;
            i += 1;
        }





//        while(input != EOF)
//        {
//            fscanf(pixBuffer, 1, sizeof(pixBuffer), input);
//        }
//        fscanf(input, "%d", &pixBuffer);
//        while()
//        {
//
//        }
    }

//    if(format == 6)
//    {
//        //p6 to p3
////        printf("test 2\n");
////        int size = atoi(pixBuffer);
////        printf(pixBuffer);
////        width = 819;
////        height = 460;
////        size_t size = width * height * 3;
//        pixBuffer = (unsigned char* )malloc(sizeof(input));
//        //counter
//        int i = 0;
//        int c = fgetc(input);
//        while(c == ' ')
//        {
////            pixBuffer[i] = c;
////            c = fgetc(input);
////            i += 1;
////              result = fread(pixBuffer, 1, sizeof(pixBuffer), input);
//              fprintf(input, "%d", output);
//              fprintf(input, "%s", "hello", output);
////              fputc(pixBuffer,output);
////
//        }
//
//        fprintf(output, "%c", pixBuffer);
//
//
//
//    }

    fclose(input);
//    fclose(output);
//    fprintf(stderr, "Program terminated\n");
    return 0;
}
