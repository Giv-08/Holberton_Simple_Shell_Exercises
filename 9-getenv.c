#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i])
	{
		if(strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

int main(int ac, char **av, char **env)
{
	char *value = _getenv("PATH");

	if (value)
	{
		printf("PATH: %s\n", value);
	}
	else
	{
		printf("Environment variable not found.\n");
	}
	return 0;
}
