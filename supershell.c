#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *prompt = "cisfun$ ";
	char *input = NULL;
	size_t n = 1024;
	char *token;
	int i = 0, status;
	char **array;
	pid_t child_pid;

	while (1)
	{
		printf("%s", prompt);
		getline(&input, &n, stdin);
		token = strtok(input, "\n");
		array = malloc(sizeof(char *) * n);
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}
		array[i] = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Error with the exec");
			}
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(array);
	}
}
