#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 500
#define OUTPUT_MODE 0700
int main(int argc, char *argv[]) {
    int in_fd, out_fd;
    int rd_size = 1, wr_size;
    char buf[BUF_SIZE];

    if (argc != 3)
    {
        printf("Number of arguments cannot be greater than 3, insert a input and output after the execute file.");
        exit(1);
    }
        

    in_fd = open(argv[1], O_RDONLY);

    if (in_fd < 0)
    {
        printf("Input file invalid.");
        exit(2);
    }
        

    out_fd = creat(argv[2], OUTPUT_MODE);

    if (out_fd < 0)
    {
        printf("Output file invalid.");
        exit(3);
    }
        

    while (rd_size > 0) {
        rd_size = read(in_fd, buf, BUF_SIZE);

        if (rd_size <0)
        {
            printf("Buffer has an invalid number of characters. Restart code or check input/output files.");
            exit(4); 
        }
            

        wr_size = write(out_fd, buf, rd_size);

        if (wr_size<=0) 
        {
            close(in_fd);
            close(out_fd);
            exit(5);
        }
    }
}