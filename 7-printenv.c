#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i = 0;

	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
