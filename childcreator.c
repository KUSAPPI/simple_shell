#include "shell.h"

/**
 * child_creator - Check to refer
 * Yes
 * @command: Check to refer
 * @name: Check to refer
 * @env: Check to refer
 * @cicles: Check to refer
 * Return:Check to refer
 */
void child_creator(char **command, char *name, char **env, int cicles)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execute(command, name, env, cicles);
		free_dp(command);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(command);
		}
		free_dp(command);
	}
}


/**
  * changer_direc - Check to refer
  * Yes
  * Done
  * @path: Check to refer
  * Return: Check to refer
  */
int changer_direc(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
