typedef struct
{
    char name[10];
    double x;
    double y;
    double r;
    int error_index;
} Circle;

Circle *parse(char *buffer);