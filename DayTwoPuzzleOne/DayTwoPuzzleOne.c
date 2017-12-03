#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * readFile(char* fileName);

void main(int arc, char* args)
{
	char* input = readFile("TestInput.txt");

	int* numbers = NULL;
	int numberOfNumbers = 0;

	int currentNumber = 0;

	int sum = 0;

	for (size_t i = 0; i < strlen(input); i++)
	{
		char currentChar = *(input + i);

		if (currentChar >= 48 && currentChar <= 57)
		{
			currentNumber *= 10;
			currentNumber += currentChar - 48;
		}
		else
		{
			numberOfNumbers++;

			numbers = realloc(numbers, numberOfNumbers * sizeof(int));
			*(numbers + (numberOfNumbers - 1)) = currentNumber;

			currentNumber = 0;
		}



		if (currentChar == 10)
		{

			for (int i = 0; i < numberOfNumbers; i++)
				printf("%d ", *(numbers + i));

			printf("\n");

			int* min = NULL;
			int* max = NULL;

			for (int i = 0; i < numberOfNumbers; i++)
			{
				int number = *(numbers + i);

				if (min == NULL)
				{
					min = malloc(sizeof(int));
					*(min) = number;
				}
				else if (*(min) > number)
				{
					*(min) = number;
				}

				if (max == NULL)
				{
					max = malloc(sizeof(int));
					*(max) = number;
				}
				else if (*(max) < number)
				{
					*(max) = number;
				}
			}

			printf("Min: %d\n", *(min));
			printf("Max: %d\n", *(max));
			printf("\n");

			sum += *(max)-*(min);

			numbers = NULL;
			min = NULL;
			max = NULL;
			numberOfNumbers = 0;
		}
	}

	printf("Answer: %d\n", sum);
	getchar();
}

int numOfChar(char* buffer, char token)
{
	int count = 0;

	for (size_t i = 0; i < (int)strlen(buffer); i++)
	{
		if (*(buffer + i) == token)
			count++;
	}

	return count;
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

	*(buffer + index) = '\0';

	fclose(fp);

	return buffer;
}