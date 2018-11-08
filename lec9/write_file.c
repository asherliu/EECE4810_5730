#include <stdio.h>

int main(int args, char **argv) {
    FILE *fp;

    fp = fopen("./test.txt", "w+");
    if(fp !=NULL)
    {
    fprintf(fp, "This is testing for fprintf...\n");
    fclose(fp);
    }
    else
    {
        fprintf(stderr, "./test.txt not open\n");
    }

    return 0;
}
