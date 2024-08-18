#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void check_command(char *command) {
    if (access(command, F_OK) == 0) {
        printf("%s is found!\n", command);
    } else {
        printf("%s is NOT found!\n", command);
    }
}

int main() {
    size_t size = 0;
    char *buffer = NULL;
    char *token;

    while (1) {
        printf("$ ");
        getline(&buffer, &size, stdin);
        token = strtok(buffer, " \n");

        if (token && strcmp(token, "which") == 0) {
            token = strtok(NULL, " \n");
            while (token) {
                check_command(token);
                token = strtok(NULL, " \n");
            }
        } else if (token && strcmp(token, "exit") == 0) {
            break;
        } else {
            printf("Command doesn't exist\n");
        }
    }

    free(buffer);  // Free the allocated buffer
    return 0;
}
