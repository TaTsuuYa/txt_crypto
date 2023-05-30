#include "main.h"

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments list
 *
 * Return: 0 success, int otheriwse
 */

int main(int argc, char **argv)
{
	char *str;

	if (argc != 3)
	{
		printf("usage: %s [flag] [text]\n", argv[0]);
		return (0);
	}

	switch (argv[1][1])
	{
		case 'e':
			str = enc(argv[2]);
			break;
		case 'd':
			str = dec(argv[1]);
			break;
		default:
			printf("usage: %s [flag] [txt]\n", argv[0]);
			exit(0);
	}
	printf("%s\n", str);

	if (str != NULL)
		free(str);

	return (0);
}

