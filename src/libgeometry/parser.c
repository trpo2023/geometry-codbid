#include <stdio.h>
#include "parser.h"

Circle *parse(char *buffer)
{
    Circle* circle = malloc(sizeof(Circle));
    circle->error_index = 0;
    char *temp = malloc(10 * sizeof(char));
    int temp_i = 0;
    int i = 0;
    while (buffer[i] != '(')
    {
        circle->name[i] = buffer[i];
        i++;
    } i++;

    while (buffer[i] != ' ' && ( isdigit(buffer[i]) != 0 || buffer[i] == '.' ) )
    {
        temp[temp_i] = buffer[i];
        temp_i++;
        i++;
    }
    circle->x = atof(temp);

    if ( buffer[i] != ' ' )
    {   
        printf("Error at %d", i);
        circle->error_index = i;
        free(temp);
        return circle;
    }

    while ( isdigit(buffer[i]) == 0 )
        i++;
    temp = malloc(10 * sizeof(char));
    temp_i = 0;

    while (buffer[i] != ',' && ( isdigit(buffer[i]) != 0 || buffer[i] == '.' ) )
    {
        temp[temp_i] = buffer[i];
        temp_i++;
        i++;
    }
    circle->y = atof(temp);

    if ( buffer[i] != ',' )
    {   
        printf("Error at %d", i);
        circle->error_index = i;
        free(temp);
        return circle;
    }

    while ( isdigit(buffer[i]) == 0 )
        i++;

    temp = malloc(10 * sizeof(char));
    temp_i = 0;

    while (buffer[i] != ')' && ( isdigit(buffer[i]) != 0 || buffer[i] == '.' ) )
    {
        temp[temp_i] = buffer[i];
        temp_i++;
        i++;
    } i++;
    circle->r = atof(temp);

    free(temp);
    return circle;
}