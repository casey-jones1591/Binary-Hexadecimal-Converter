#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <sys/types.h>


int main(int argc, char* argv[]){

	FILE* fp;
	char line[1024];
	int i=0;	

	/* error check that a file is given */
	if (argc != 2){
		printf("An error has occured\n");
		exit(1);
	}
	
	/* open file */
	fp=fopen(argv[1], "r" );
	
	/* loop through each line */
	while(fgets(line, sizeof(line), fp) != NULL){
		char *myargs[4]={ NULL }; 
		char *token;
		int idx;
		int count = 0;

		/* tokenize each line */
		token = strtok(line, " \t\n");
		while (token && (count < 4)){
			myargs[count++] = strdup(token);
			token = strtok(NULL, " \t\n");
		}

		/* call fork and make system call */
		int rc = fork();
		/* fork faiiled */
		if (rc < 0) {  			
			printf("An error has occured\n");
	       		exit(1);

		/* child new process */
		} else if (rc == 0) {  		
	   		printf("hello, I am child (pid:%d)\n", (int) getpid());
			execvp(myargs[0], myargs); 
			printf("this shouldn't print out\n");

		/* parent new process */
	   	} else { 
			int wc = wait(NULL);
	       		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
		       		rc, wc, (int) getpid());
	    	}

		/* loop through myargs to deallocate */
		for (idx = 0; idx < count; idx++) {
			free(myargs[idx]);
		}
			
	}
	/* close file */
	fclose(fp);
	return 0;
}
