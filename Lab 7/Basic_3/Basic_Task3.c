#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUF_SIZE 600
#define OUTPUT_MODE 0700
int main(int argc, char *argv[]) {
    int in_fd, out_fd;
    int rd_size = 1, wr_size;
    char buf[BUF_SIZE];
    bool flag;
    int bufCount = 0;
    int countVowel = 0;
    int charCount = 0;
    int sentenceCount = 0;
    int asciiVowel[10] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};

    if (argc != 3)
    {
        printf("Number of arguments cannot be greater than 3, insert a input and output after the execute file.\n");
        exit(1);
    }
        

    in_fd = open(argv[1], O_RDONLY);

    if (in_fd < 0)
    {
        printf("Input file invalid.\n");
        exit(2);
    }
        

    out_fd = creat(argv[2], OUTPUT_MODE);

    if (out_fd < 0)
    {
        printf("Output file invalid.\n");
        exit(3);
    }
        

    while (rd_size > 0) {
        rd_size = read(in_fd, buf, BUF_SIZE);

        //How many characters being read at a time
        printf("\nReading %d", rd_size);
        printf(" characters.\n");

        int length = sizeof(asciiVowel)/sizeof(asciiVowel[0]);

        //Increments charCount if it is not a space(ascii value 32)
        for(int i = 0; i < rd_size; i++)
        {
            if(buf[i] != 32)
            {
                if(buf[i] == 46 || buf[i] == 33 || buf[i] == 63)
                    sentenceCount += 1;  
                
                charCount += 1;          
                
                int j = 0;
                for(j; j < length; j++)
                {
                    if(buf[i] == asciiVowel[j])
                        countVowel += 1;
                }                
            }         
        }

        //Every time buffer fills up counter rises
        if(rd_size == 600)
        {
            printf("Buffer filled.\n");
            bufCount += 1;
        }

        if (rd_size <0)
        {
            printf("\nBuffer has an invalid number of characters. Restart code or check input/output files.\n");
            exit(4); 
        }
            

        wr_size = write(out_fd, buf, rd_size);

        if (wr_size<=0) 
        {
            close(in_fd);
            close(out_fd);
            printf("\n--/--/--/--/--/--/--\n");
            printf("\nBuffer filled %d times.\n", bufCount); 
            printf("\nSEntence %d\n", sentenceCount); 
            printf("\nCharacters discounting spaces %d\n", charCount); 
            printf("\nVowel characters %d\n", countVowel); 
            printf("\nConsonants and other characters besides space %d\n", (charCount - countVowel));
            printf("\n--/--/--/--/--/--/--\n");
            exit(5);
        }
    }
}