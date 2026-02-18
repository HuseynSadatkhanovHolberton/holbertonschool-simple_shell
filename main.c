#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, or appropriate error code
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}

		/* Sətir sonundakı yeni sətir simvolunu silirik */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Burada komandanı icra edəcək funksiya çağırılmalıdır */
		/* execute_command(line); */
	}

	return (0);
}
