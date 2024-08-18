#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void check_command_in_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path = strdup(path_env);
	char *dir = strtok(path, ":");
	char array[1024];

	if (!path_env)
	{
        	printf("Unable to retrieve PATH.\n");
        	return;
	}
	if (!path)
	{
		perror("Error strdup");
		return;
	}

	while (dir != NULL)
	{
		array[0] = '\0';
		strcat(array, dir);
		strcat(array, "/");
		strcat(array, command);
	
        	if (access(array, F_OK) == 0)
		{
			printf("%s is found at %s\n", command, array);
			return;
        	}
        	dir = strtok(NULL, ":");
	}
	printf("%s is NOT found in the PATH\n", command);
	free(path);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		check_command_in_path(argv[i]);
	}
	return 0;
}
