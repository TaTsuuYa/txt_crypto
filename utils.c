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

	if (str == NULL)
		return (NULL);

	srand(seed);

	encstr = malloc(sizeof(char *) * (strlen(str) + 2));
	if (encstr == NULL)
		return (NULL);

	encstr[0] = seed;
	for (i = 0; str[i] != 0; i++)
		encstr[i + 1] = (((str[i] - min) + rand()) % (max - min)) + min;

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

	if (str == NULL)
		return (NULL);

	srand(seed);

	decstr = malloc(sizeof(char *) * strlen(str));
	if (decstr == NULL)
		return (NULL);

	for (i = 0; str[i + 1] != 0; i++)
		decstr[i] = modulo(((str[i + 1] - min) - rand()), (max - min)) + min;

	return (decstr);
}

/**
 * modulo - handles the modulo
 * @dividend: devided number
 * @divisor: deviding number
 *
 * Return: reminder of division
 */

int modulo(int dividend, int divisor)
{
	int r = dividend % divisor;

	if (r < 0)
		r = (r + divisor) % divisor;

	return (r);
}

