//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char *argv[])
//{
//
//    //input file to read from
//    FILE* input = fopen(argv[2], "r");
//    //buffer declaration
//    char *pixBuffer;
//    //output file to write to
//    FILE* output = fopen(argv[3], "w");
//    //declare character variable
//    int ch;
//    //while there isn't a P character and it isn't the end of the input file...
//    while((ch = fgetc(input)) != EOF && ch !='P');
//    //if the end of the file is reached...
//    if(ch == EOF)
//        {
//            //if incorrect file type or error reading from file, produce error
//            if(feof(input))
//            {
//                fprintf(stderr, "Incorrect file type\n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//        //while the end of file hasn't been reached and file type is not 3 or 6
//        while((ch = fgetc(input)) != EOF && ch !='3' && ch != '6');
//        if(ch == EOF)
//        {
//            //if incorrect file type or error reading from file, produce error
//            if(feof(input))
//            {
//                fprintf(stderr, "Incorrect file type\n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//
//        //"magic number"
//        int magicNum = ch;
//        //to check whitespace
//        while((ch = fgetc(input)) != EOF && isspace(ch));
//        if(ch == EOF)
//        {
//
//            if(feof(input))
//            {
//                fprintf(stderr, "End of file reached\n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//
//        //declare width variable
//        int width;
//        //transverse horizontal
//        int status = fscanf(input, "%d", &width);
//        if(status == EOF)
//        {
//
//            if(feof(input))
//            {
//                fprintf(stderr, "End of file reached \n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//
//        if(status < 1 )
//        {
//            fprintf(stderr, "Invalid argument\n");
//        }
//
//        int height;
//        int sHeight = fscanf(input, "%d", &height);
//        while((ch = fgetc(input)) != EOF && isspace(ch));
//        if(ch == EOF)
//        {
//            if(feof(input))
//            {
//                fprintf(stderr, "End of file reached \n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//            return 1;
//
//        }
//
////        int height;
////        int status = fscanf(input, "%d", &height);
//        if(sHeight == EOF)
//        {
//            if(feof(input))
//            {
//                fprintf(stderr, "End of file reached \n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//
//        if(status < 1 )
//        {
//            fprintf(stderr, "Invalid argument\n");
//        }
//
//        int maxColor;
//        int sColor = fscanf(input, "%d", &maxColor);
//        if(sColor == EOF)
//        {
//            //copy for the other stuff
//            if(feof(input))
//            {
//                fprintf(stderr, "End of file reached \n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//
//        if(status < 1 )
//        {
//            fprintf(stderr, "Invalid argument\n");
//        }
//
//        if(ch == EOF)
//        {
//            if(feof(input))
//            {
//                fprintf(stderr, "End of file reached \n");
//
//            }
//            else if(ferror(input))
//            {
//                fprintf(stderr, "Error reading file\n");
//            }
//
//            return 1;
//
//        }
//        else if(isspace(ch)){
//            fprintf(stderr, "Error reading file\n");
//        }
//
//        int i;
//        int j;
//        size_t size = width * height * 3;
//        pixBuffer = (unsigned char *)malloc(size);
//        if(ch == '6'){
//            fscanf(input, "%d", &(pixBuffer[(i * width + j)*3 + 1]));
//                    while((ch = fgetc(input)) != EOF && isspace(ch));
//                    if(ch == EOF)
//                    {
//                        if(feof(input))
//                        {
//                            fprintf(stderr, "End of file reached \n");
//
//                        }
//                        else if(ferror(input))
//                        {
//                            fprintf(stderr, "Error reading file\n");
//                        }
//                        return 1;
//
//                    }
//                    while((ch != EOF && isspace(ch))){
//                        fread(pixBuffer, 1, size, input);
//                        fwrite(input, 1, sizeof(input), output);
//                    }
//        }
//        else if(ch == '3'){
//            for(i = 0; i < width; i ++){
//                for(j = 0; j < height; j++){
//                    //this is red
//                    //read in file to buffer
//                    fscanf(input, "%d", &(pixBuffer[(i * width + j)*3]));
//                    while((ch = fgetc(input)) != EOF && isspace(ch));
//                    if(ch == EOF)
//                    {
//                        if(feof(input))
//                        {
//                            fprintf(stderr, "End of file reached \n");
//
//                        }
//                        else if(ferror(input))
//                        {
//                            fprintf(stderr, "Error reading file\n");
//                        }
//                        return 1;
//
//                    }
//                    //green
//                    fscanf(input, "%d", &(pixBuffer[(i * width + j)*3 + 1]));
//                    while((ch = fgetc(input)) != EOF && isspace(ch));
//                    if(ch == EOF)
//                    {
//                        if(feof(input))
//                        {
//                            fprintf(stderr, "End of file reached \n");
//
//                        }
//                        else if(ferror(input))
//                        {
//                            fprintf(stderr, "Error reading file\n");
//                        }
//
//                        return 1;
//
//                    }
//                    //blue
//                    fscanf(input, "%d", &(pixBuffer[(i * width + j)*3 +2]));
//                    while((ch = fgetc(input)) != EOF && isspace(ch));
//                    if(ch == EOF)
//                    {
//                        //copy for the other stuff
//
//                        if(feof(input) && i < (width-1) && j < (height - 1))
//                        {
//                            fprintf(stderr, "P is not a thing \n");
//
//                        }
//                        else if(ferror(input))
//                        {
//                            fprintf(stderr, "DENIED\n");
//                        }
//
//                        return 1;
//
//                    }
//                }
//                //write "new" file to output.ppm
//                fprintf(output,"%d", magicNum);
//                fprintf(output,"%d", width);
//                fprintf(output, "%d", height);
//                fprintf(output, "%d", pixBuffer);
//            }
//        }
//
//        fclose(input);
//        fclose(output);
//        return 0;
//
//}
