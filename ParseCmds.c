#include <stdio.h>
#include <string.h>

#define MAX 1024

int main(int argc, char* argv[]){

	char commandString[MAX];

	/* continously loop for commandString */
	while(1){
		
		/* get commandString from STDIN */
		fgets(commandString, sizeof(commandString), stdin);

		/* If commandString is equal to exit, then exit the loop */
		if (strcmp(commandString, "exit\n")==0){
			break;
		} else {
			/* Tokenize the command */
			char* token = strtok(commandString, " \t \n");
			while (token != NULL){
				printf("%s\n", token);
				token = strtok(NULL, " \t \n");
			}
		}
	}
	return 0;
}
