#include "main.h"

/**
 * enc - encrypts @str
 * @str: pointer to string
 *
 * Return: pointer to encrypted string
 */

char *enc(char *str)
{
	char *encstr;
	char min = ' ', max = '~';
	int i, seed = (time(0) % (max - min)) + min;

	srand(seed);

	encstr = malloc(sizeof(char *) * (strlen(str) + 2));
	if (encstr == NULL)
		return (NULL);

	encstr[0] = seed;
	for (i = 0; str[i] != 0; i++)
		encstr[i + 1] = ((str[i] + rand()) % (max - min)) + min;

	return (encstr);
}

/**
 * dec - decrypts @str
 * @str: pointer to string
 *
 * Return: pointer to decrypted string
 */

char *dec(char *str)
{
	char *decstr;
	char min = ' ', max = '~';
	int i, seed = str[0];

	srand(seed);

	decstr = malloc(sizeof(char *) * strlen(str));
	if (decstr == NULL)
		return (NULL);

	for (i = 0; str[i + 1] != 0; i++)
		decstr[i] = ((str[i + 1] - rand()) % (max - min)) - min + (max - min);

	return (decstr);
}

