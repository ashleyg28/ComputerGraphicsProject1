/*
    Ashley Green
    16 September 2016
    CS 430
    Project 1
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //declare pixel buffer
    char *pixBuffer;
    //declare width and height variables
    int width;
    int height;
    //ignore argv[0]
    //input file to read from
    FILE* input = fopen(argv[2], "rb");
    //output file to write to
    FILE* output = fopen(argv[3], "wb");
    //return error if file isn't there
    if(input == NULL)
    {
        fprintf(stderr, "ERROR:  File(s) does not exist. \n");
    }
    /*
        "gather" first character and if it isn't equal to P then
        it isn't the correct file format
        write out to standard error
    */
    int chr = fgetc(input);
    if(chr != 'P')
    {
        fprintf(stderr, "ERROR: Type is not PPM. \n");
    }
    //check if p3 or p6 format
    chr = fgetc(input);
    if(chr == '3')
    {
        //p3 to p6
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
        //for loop to fill pixel buffer
        int i;
        for(i = 0; i < width * height * 3; i ++)
        {
            fscanf(input, "%d", &pixBuffer[i]);
        }
        //close input file
        fclose(input);
        //write header and pixel buffer to output image file
        fprintf(output, "P6 %d %d %d ", width, height, 255);
        fwrite(pixBuffer, sizeof(unsigned char), width * height * 3, output);
        //close output file
        fclose(output);
    }
    //P6 - P3
    if(chr == '6')
    {
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
        fgetc(input); //to do: skip whitespace
        //width
        int width;
        fscanf(input, "%d",&width);
        fgetc(input); //to do: skip whitespace
        //height
        int height;
        fscanf(input, "%d", &height);
        fgetc(input); //to do: skip whitespace
        //max number
        int maxNum;
        fscanf(input, "%d", &maxNum);
        fgetc(input); //to do: skip whitespace
//        int red, green, blue;
//        unsigned int pixel;
//        /* packing */
//        pixel = 0xff << 24 | blue << 16 | green << 8 | red;
////        fscanf(output,"%d",&green);
////        fscanf(output,"%d",&blue);
//        blue = (pixel >> 16) & 0xff;
//        green = (pixel >> 8) & 0xff;


        //pixel buffer
        unsigned char *pixBuffer;
        pixBuffer = malloc(width * height * 3);
//        fprintf(output, "%d", green);
        //for loop i = width * height * depth
        int i;
        for(i = 0; i < width * height * 3; i ++)
        {
//            fscanf(input, "%d", &pixBuffer[i]);
            fread(pixBuffer, 1, sizeof(pixBuffer), input);
        }
//        int j;
//        for(j = 0; j < width * height * 3; j ++)
//        {
//            red = pixel & 0xff;
//            fscanf(input, "%d", &red);
//        }
        fclose(input);
//        fprintf(output, "%d", red);
        //header
        fprintf(output, "P3 %d %d %d", width, height,255);
        //just prints black, no color
//        fprintf(output, "%d", pixBuffer);

        fclose(output);
    }


    return 0;
}
