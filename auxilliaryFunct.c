#include "shell.h"

/**
 * strcmpi - Check to refer
 * Yes
 * @s1: Check to refer
 * @s2: Check to refer
 * Return: Check to refer
 */
int strcmpi(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * strlengi - Check to refer
 * Yes
 * @s: Check to refer
 * Return: Check to refer
 */
unsigned int strlengi(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}


/**
 * strcpyi - Check to refer
 * Yes
 * @dest: Check to refer
 * @src: Check to refer
 * Return: Check to refer
 */
char *strcpyi(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}


/**
 * strcati - Check to refer
 * Yes
 * @dest: Check to refer
 * @src: Check to refer
 * Return: Check to refer
 */
char *strcati(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}


/**
 * iatoii - Check to refer
 * Yes
 * @s: Check to refer
 * Return: Check to refer
 */
int iatoii(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (null_flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
