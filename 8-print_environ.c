#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("%p\n", *environ);
	printf("%p\n", *env);
	return (0);
}
