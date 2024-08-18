#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_t {
	char *directory;
	struct node_t *next;
} node_t;

node_t *create_node(const char *dir);
node_t *build_path_list(void);
void print_list(node_t *head);
void free_list(node_t *head);

node_t *create_node(const char *dir)
{
	node_t *new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	new_node->directory = strdup(dir);
	if (new_node->directory == NULL)
	{
		fprintf(stderr, "String duplication failed\n");
		exit(1);
	}
	new_node->next = NULL;
	return (new_node);
}

node_t *build_path_list(void)
{
	char *path = getenv("PATH");
	char *buffer, *token;
	node_t *head, *tail, *new_node;

	if (path == NULL)
	{
		fprintf(stderr, "Failed to get PATH\n");
		return NULL;
	}

	buffer = strdup(path);

	if (buffer == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}

	head = NULL;
	tail = NULL;
	token = strtok(buffer, ":");

	while (token != NULL)
	{
        	new_node = create_node(token);
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		token = strtok(NULL, ":");
	}

	free(buffer);
	return (head);
}

void print_list(node_t *head)
{
	node_t *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}
}

void free_list(node_t *head)
{
	node_t *current = head;
	node_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current->directory);
		free(current);
		current = next_node;
	}
}

int main(void)
{
	node_t *path_list = build_path_list();

	if (path_list != NULL)
	{
		print_list(path_list);
	}
	free_list(path_list);
	return 0;
}
