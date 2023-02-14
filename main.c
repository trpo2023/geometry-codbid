#include <stdio.h>

int main() {
	FILE *fp;
	char buffer[127];
	char *name = "test.txt";
	fp = fopen(name, "r");
	while ( ! feof(fp) ) {
		fgets(buffer, 127, fp);
	}
	printf("%s", buffer);
}
