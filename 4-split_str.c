#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *src = "I love Mali and Mirin";
	char *str = malloc(sizeof(char) * strlen(src) + 1);
	char *delim = " ";
	char *token;
	
	strcpy(str, src);
	token = strtok(str, delim);
	
	while (token != NULL)
	{
		printf("%s \n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
