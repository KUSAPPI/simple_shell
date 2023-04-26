#include "shell.h"

/**
 * main - This function runs the shell
 * Yes
 * Done
 * @ac: No. of arguments inputted
 * @av: Check to refer
 * @env: Check to refer
 * Return: Check to refer Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cicles = 0;
	(void)ac;

	while (1)
	{
		cicles++;
		iprompti();
		signal(SIGINT, handle);
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			i_iEOFi(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokening(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				exiti_shelli(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				create_child(command, av[0], env, cicles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * iprompti - Check to refer
 * Return: Check to refer
 */
void iprompti(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Shelly_Me>> ", 13);
}


/**
 * handle - Check to refer.
 * @signals: Check to refer
 * Return: Check to refer Nothing.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nShelly_Me>> ", 14);
}


/**
 * i_iEOFi - Check to refer
 * @buffer: Check to refer
 * Return: Check to refer
 */
void i_iEOFi(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}


/**
 * exiti_shelli - Check to refer
 * @command: Check to refer
 * Return: Check to refer
 */
void exiti_shelli(char **command)
{
	int sta_tus = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	sta_tus = _atoi(command[1]);
	free_dp(command);
	exit(sta_tus);
}
