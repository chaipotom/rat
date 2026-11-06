/*
 * rat - clone of a cat utility by Alex Larin
*/
#include <stdio.h>

void printStream(FILE* fp);

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printStream(stdin);
		return 0;
	} 

	for (int i = 1; i < argc; i++)
	{
		FILE* fp = fopen(argv[i], "r");

		if (fp == NULL) {
			fprintf(stderr, "%s: No such file or directory\n", argv[i]);
			return 1;
		}

		printStream(fp);
	
		fclose(fp);
	}
}

void printStream(FILE* fp) {
	int c;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}
}

