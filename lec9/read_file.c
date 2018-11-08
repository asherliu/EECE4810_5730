#include <stdio.h>

int main(int args, char **argv) {

    FILE *fp;
    char buff[1024];

    fp = fopen("./test.txt", "r");
    if(fp != NULL)
    {

        while(fscanf(fp, "%s", buff)>0)
        {
            printf("%s ", buff );
        }
        fclose(fp);
        printf("\n");
    }
    else
    {
        fprintf(stderr, "./test.txt not open\n");
    }
    return 0;
}
