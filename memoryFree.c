#include "shell.h"

/**
 * freelyDp - Check to refer
 * Yes
 * @command: Check to refer
 * Return:Check to refer 
 */

void freelyDp(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
}


/**
 * freelyExit - Check to refer
 * Yes
 * @command: Check to refer
 * Return: Check to refer
 */
void freelyExit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}
