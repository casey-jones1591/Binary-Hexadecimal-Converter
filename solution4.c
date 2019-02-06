#include <stdio.h>
#include <string.h>



int main(int argc, char* argv[]){

	char commandString[1024];


	/* continously loop for commandString */
	while(1){
		
		/* get commandString from STDIN */
		printf("String Command:  ");
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

			/* Print the command */ 
			//printf("The command string is: %s\n", commandString);
		}

	}

	return 0;
}
