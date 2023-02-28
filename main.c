#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SPACE_SYMBOL 32 // " "
#define COMMA_SYMBOL 44 // ","
#define BRACKET_SYMBOL 40 // "("
#define BACKBRACKET_SYMBOL 41 // ")"
#define DOT_SYMBOL 46 // "."
#define MAX_BUFFER_SIZE 127

float Processing(char* Array, int* p, int* incorrect, int target)
{
    char Temp[10];
    int Index = *p;
    int i_Temp = 0;
    
    if ( target == 1 ) {
    	if ( (*(Array + Index + 1) != SPACE_SYMBOL) || (isdigit(*(Array + Index + 2) == 0)) ) {
    		*incorrect = 1;
    		printf("Received '");
    		while ( isdigit(*(Array + Index)) == 0 ) {
    			printf("%c", *(Array + Index));
    			Index++;
    		}
    		printf("', but required SPACE\n");
    		return 2;
    	}
    }
    if (*(Array + Index) == SPACE_SYMBOL || *(Array + Index) == COMMA_SYMBOL) {
        *p = Index + 1;
        return Processing(Array, p, incorrect, target);
    }
    while (*(Array + Index) != SPACE_SYMBOL && *(Array + Index) != COMMA_SYMBOL && *(Array + Index) != BACKBRACKET_SYMBOL) {
        if (isdigit(*(Array + Index)) > 0 || *(Array + Index) == DOT_SYMBOL)
            Temp[i_Temp++] = *(Array + Index);
        else {
            *incorrect = 1;
            return 0;
        }
        Index++;
    }
    *p = Index;
    if ( target == 2 ) {
    	if ( (*(Array + Index) != COMMA_SYMBOL) || (*(Array + Index + 1) != SPACE_SYMBOL) || (isdigit(*(Array + Index + 2) == 0)) ) {
    		*incorrect = 1;
    		return 2;
    	}
    }
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
    x = Processing(a, p, &incorrect, 1);
    y = Processing(a, p, &incorrect, 2);
    r = Processing(a, p, &incorrect, 3);
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
