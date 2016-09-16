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
    FILE* input = fopen(argv[2], "r");
    //output file to write to
    FILE* output = fopen(argv[3], "w");

    int chr = fgetc(input);

    //return error if files aren't there
    if(input == NULL)
    {
        fprintf(stderr, "ERROR:  File(s) does not exist. \n");
    }
    else if(output == NULL)
    {
        fprintf(stderr, "ERROR:  File(s) does not exist. \n");
    }
    else if(chr != 'P')
    {
        fprintf(stderr, "ERROR: Type is not PPM. \n");
    }
    //p3 or p6 format
    int format = atoi(argv[1]);

    if(format == 3)
    {
        //p3 to p6
//        printf("test 1\n");
        width = 819;
        height = 460;
        size_t size = width * height * 3;
        pixBuffer = (unsigned char *)malloc(size);

//        while(input != EOF)
//        {
//            newFile = fputc(pixBuffer, output);
//
//
//        }

    }

    if(format == 6)
    {
        //p6 to p3
//        printf("test 2\n");
//        int size = atoi(pixBuffer);
//        printf(pixBuffer);
//        width = 819;
//        height = 460;
//        size_t size = width * height * 3;
        pixBuffer = (unsigned char* )malloc(sizeof(input));
        //counter
        int i = 0;
        int c = fgetc(input);
        while(c == ' ')
        {
//            pixBuffer[i] = c;
//            c = fgetc(input);
//            i += 1;
//              result = fread(pixBuffer, 1, sizeof(pixBuffer), input);
              fprintf(input, "%d", output);
              fprintf(input, "%s", "hello", output);
              fputc(pixBuffer,output);
//
        }

        fprintf(output, "%c", pixBuffer);



    }

    fclose(input);
    fclose(output);
    return 0;
}
