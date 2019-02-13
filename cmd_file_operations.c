#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

	FILE* cmd_File;
	char cmd_line[1024];	

	/* error check that a file is given */
	if (argc != 2){
		fprintf(stderr, "An error has occured\n");
		exit(1);
	}
	
	/* open file */
	cmd_File=fopen(argv[1], "r" );
	
	/* loop through each line */
	while(fgets(cmd_line, sizeof(cmd_line), cmd_File) != NULL){
		char *myargs[4]={ NULL }; 
		char *token;
		int count = 0;

		/* tokenize each line */
		token = strtok(cmd_line, " \t\n");
		while (token && (count < 4)){
			myargs[count++] = strdup(token);
			token = strtok(NULL, " \t\n");
		}

		/* call fork and make system call */
		/* credit: fork() call & processes are based off our text book OSTEP */
		int rc = fork();

		/* fork faiiled */
		if (rc < 0) {  			
			fprintf(stderr,"An error has occured\n");
	       		exit(1);

		/* child new process */
		} else if (rc == 0) {  		
			execvp(myargs[0], myargs); 
			
		/* parent process & wait until child process is completed */
	   	} else { 
			int wc = wait(NULL);

	    	}

		/* loop through myargs to deallocate */
		for (int idx = 0; idx < count; idx++) {
			free(myargs[idx]);
		}
			
	}
	/* close file */
	fclose(cmd_File);
	return 0;
}
