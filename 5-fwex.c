#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int i;
	int status;
	char *argv[] = {"ls", "-1", "/tmp", NULL};

	for (i = 0; i < 5; ++i)
	{
		pid = fork();

        	if (pid < 0)
		{
			perror("fork fails");
			exit(0);
        	}

        	if (pid == 0)
		{
			printf("[child] pid %d from [parent] pid %d\n",getpid(),getppid());
			execve("/bin/ls", argv, NULL);
			perror("execve fails");
			exit(0);
        	}
		else
		{
			waitpid(pid, &status, 0);
        	}
		printf("done!\n");
	}
    return 0;
}
