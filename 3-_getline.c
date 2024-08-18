#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 10;
	char *buffer = NULL;

	printf("Type a name: ");
	getline(&buffer, &n, stdin);
	printf("Hi %s Buffer size is %zu\n", buffer, n);

	free(buffer);
	return (0);
}
