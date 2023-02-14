#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

float find(char *arr, int *p, int *i) {
	char temp[10];
	int j = *p;
	int t = 0;
	if ( *(arr + j) == 32 || *(arr + j) == 44 ) {
		*p = j + 1;
		return find(arr, p, i);
	}
	while ( *(arr + j) != 32 &&  *(arr + j) != 44 && *(arr + j) != 41 )
	{
		if ( isdigit(*(arr + j)) > 0 || *(arr + j) == 46 )
			temp[t++] = *(arr + j);
		else {
			*i = 1;
			return 0;
		}
		j++;
	}
	*p = j;
	return atof(temp);
}

int check(char *a) {
	int incorrect = 0;
	int i = 0;
	char circle[] = "circle";
	while ( 40 != *(a + i) ) {
		if ( circle[i] != *(a + i) )
			return 1;
		i++;
	} if ( *(a + i) != 40 )
		return 1;
	int j = i + 1;
	float x, y, r;
	int *p = &j;
	x = find(a, p, &incorrect);
	y = find(a, p, &incorrect);
	r = find(a, p, &incorrect);
	if ( !incorrect ) {
		printf("%.2f, %.2f, %.2f\n", x, y, r);
		return 0;
	}
	else
		return 1;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	if ( argc != 2 ) {
		printf("Requires 1 argument\n");
		exit(1);
	}
	char buffer[127];
	char *name = argv[1];
	if ( (fp = fopen(name, "r")) == NULL ) {
		printf("Incorrect file path or the file cannot be opened\n");
		exit(1);
	}
	while ( ! feof(fp) ) {
		fgets(buffer, 127, fp);
		if ( check(buffer) == 1) {
			printf("Incorrect str: '%s'\n", strtok(buffer, "\n"));
		}
	}
}
