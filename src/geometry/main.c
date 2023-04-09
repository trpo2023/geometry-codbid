#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER_SIZE 127

int main(int argc, char* argv[])
{
    FILE* fp;
    if (argc != 2) {
        printf("Requires 1 argument\n");
        exit(1);
    }
    char buffer[MAX_BUFFER_SIZE];
    char* name = argv[1];
    if ((fp = fopen(name, "r")) == NULL) {
        printf("Incorrect file path or the file cannot be opened\n");
        exit(1);
    }
    while (!feof(fp)) {
        fgets(buffer, 127, fp);
        if (is_Correct(buffer) == 1) {
            printf("Incorrect str: '%s'\n", strtok(buffer, "\n"));
        }
    }
}
