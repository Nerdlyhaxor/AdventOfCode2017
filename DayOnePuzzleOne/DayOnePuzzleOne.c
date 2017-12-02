#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * readFile(char *);

void main(int argc, char* args)
{
	char *input = readFile("input.txt");
	int sum = 0;

	for (int index = 0; index < strlen(input); index++)
	{
		if (index == strlen(input) - 1 && *(input) == *(input + index))
		{
			sum += *(input + index) - 48;
		}
		else if (*(input + index) == *(input + index + 1))
		{
			sum += *(input + index) - 48;
		}
	}

	printf("Answer: %d", sum);

	getchar();
}

char * readFile(char* fileName)
{
	char *buffer;

	FILE *fp = fopen(fileName, "r");

	fseek(fp, 0L, SEEK_END);

	int fileLength = ftell(fp);

	buffer = malloc(sizeof(char) * fileLength);

	rewind(fp);

	fgets(buffer, fileLength, fp);

	fclose(fp);

	return buffer;
}