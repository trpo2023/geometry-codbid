#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
		printf("%f %f %f\n", x, y, r);
		return 1;
	}
	else
		return 0;
}

int main() {
	FILE *fp;
	char buffer[127];
	char *name = "test.txt";
	fp = fopen(name, "r");
	while ( ! feof(fp) ) {
		fgets(buffer, 127, fp);
		check(buffer);
	}
}
