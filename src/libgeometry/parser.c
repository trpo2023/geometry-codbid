#include <ctype.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>

Circle* parse(char* buffer)
{
    Circle* circle = malloc(sizeof(Circle));
    circle->error_index = -1;
    char* temp = malloc(10 * sizeof(char));
    int temp_i = 0;
    char example[] = "circle";
    int i = 0;

    while (buffer[i] != '(') {
        if (buffer[i] == example[i]) {
            circle->name[i] = buffer[i];
            i++;
        } else
            break;
    }
    i++;

    if (i != 7) {
        circle->error_index = i - 2;
        free(temp);
        return circle;
    }

    int start = i;
    if (isdigit(buffer[i]) || buffer[i] == '-') {
        while (buffer[i] != ' '
               && (isdigit(buffer[i]) != 0 || buffer[i] == '.'
                   || (buffer[i] == '-' && i == start))) {
            temp[temp_i] = buffer[i];
            temp_i++;
            i++;
        }
        circle->x = atof(temp);
    }

    if (buffer[i] != ' ') {
        circle->error_index = i;
        free(temp);
        return circle;
    }

    while (isdigit(buffer[i]) == 0)
        i++;
    temp = malloc(10 * sizeof(char));
    temp_i = 0;

    start = i;
    while (buffer[i] != ','
           && (isdigit(buffer[i]) != 0 || buffer[i] == '.'
               || (buffer[i] == '-' && i == start))) {
        temp[temp_i] = buffer[i];
        temp_i++;
        i++;
    }
    circle->y = atof(temp);

    if (buffer[i] != ',') {
        circle->error_index = i;
        free(temp);
        return circle;
    }

    while (isdigit(buffer[i]) == 0)
        i++;

    temp = malloc(10 * sizeof(char));
    temp_i = 0;

    while (buffer[i] != ')' && (isdigit(buffer[i]) != 0 || buffer[i] == '.')) {
        temp[temp_i] = buffer[i];
        temp_i++;
        i++;
    }
    i++;
    circle->r = atof(temp);

    free(temp);
    return circle;
}