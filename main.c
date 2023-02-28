#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float Processing(char* Array, int* p, int* incorrect)
{
    char Temp[10];
    int Index = *p;
    int i_Temp = 0;
    if (*(Array + Index) == 32 || *(Array + Index) == 44) {
        *p = Index + 1;
        return Processing(Array, p, incorrect);
    }
    while (*(Array + Index) != 32 && *(Array + Index) != 44 && *(Array + Index) != 41) {
        if (isdigit(*(Array + Index)) > 0 || *(Array + Index) == 46)
            Temp[i_Temp++] = *(Array + Index);
        else {
            *incorrect = 1;
            return 0;
        }
        Index++;
    }
    *p = Index;
    return atof(Temp);
}

int is_Correct(char* a)
{
    int incorrect = 0;
    int i = 0;
    char circle[] = "circle";
    while (40 != *(a + i)) {
        if (circle[i] != *(a + i))
            return 1;
        i++;
    }
    if (*(a + i) != 40)
        return 1;
    int j = i + 1;
    float x, y, r;
    int* p = &j;
    x = Processing(a, p, &incorrect);
    y = Processing(a, p, &incorrect);
    r = Processing(a, p, &incorrect);
    if (!incorrect) {
        printf("circle(%.2f %.2f, %.2f)\n", x, y, r);
        return 0;
    } else
        return 1;
}

int main(int argc, char* argv[])
{
    FILE* fp;
    if (argc != 2) {
        printf("Requires 1 argument\n");
        exit(1);
    }
    char buffer[127];
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
