#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * readFile(char* fileName);

void main(int arc, char* args)
{
	char* input = readFile("RealInput.txt");


	int index = 0;
	int number = 0;
	int max = 0;
	int min = 0;
	int sum = 0;

	while(*(input + index) != 0)
	{
		char c = *(input + index);

		if (c >= 48 && c <= 57)
		{
			number *= 10;
			number += c - 48;
		}
		else
		{
			min = (min > number) || (min == 0) ? number : min;
			max = (max < number) ? number : max;
			number = 0;
		}
		
		if (c == 10)
		{
			printf("%d\n", (max - min));
			sum += (max - min);
			max = 0;
			min = 0;
			number = 0;
		}

		index++;
	}

	printf("Sum %d", sum);

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

	char c;
	int index = 0;

	while ((c = fgetc(fp)) != EOF)
	{
		memcpy(buffer + index, &c, sizeof(char));
		index++;
	}

	*(buffer + index) = 0;

	fclose(fp);

	return buffer;
}