#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libgeometry/parser.h"
#define PI 3.14
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
        Circle* circle = parse(buffer);
        if ( circle->error_index )
        {
            printf("Error in column %d:\n", circle->error_index);
            printf("%s\n", strtok(buffer, "\n"));
            printf("%*s%c\n\n", circle->error_index, "", '^');
        } 
        else 
        {
            printf("%s\n", strtok(buffer, "\n"));
            printf("Area = %.2lf\n", PI * (circle->r * circle->r));
            printf("Perimeter = %.2lf\n\n", 2 * PI * circle->r);
        }
    }
}

