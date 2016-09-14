#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //argv[0] -> ignore this
    //buffer goes here
    char buff[256];
    //input
    FILE* input = fopen(argv[2], "r");

    int format = atoi(argv[1]); //"3" - 3
    if(format == 3)
    {

        //p3 stuff
//        while(fgets(buff,256, input))
//        {
            //input
//            FILE* input = fopen(argv[2], "r");


//        }
        printf("test\n");
    }
    if(format == 6)
    {
        //p6 stuff
        printf("test\n");
    }





    //output
//    FILE* output = fopen(argv[3], "w");

    fclose(input);
//    fclose(output);
}



//how to write to file
//        output = fopen("output.ppm","w");
//        fputs("6", output);
//        printf(output);
