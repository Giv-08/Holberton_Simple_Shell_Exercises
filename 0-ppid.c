#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
	pid_t id;

	id = fork();
	printf("parent ID: %d\n", getppid());
	return 0;
}
