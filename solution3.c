#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

/*int convertBinToHex(int binNum){
	int n=0;
	int size = strlen(line)-1;
	int count = 0
	while (*line != '\0'){
		if (*line == '1')
			n=n +pow(2, size -count);
		count++
		line++
	}
	

}
*/
int main(int argc,char *argv[])
{
	FILE * hex_file;
	FILE * bin_file;
	char line[MAX];
	char *eptr;
	long result;

	/* ensure all command line arguments are given */
	if (argc != 3) {
		printf("An error has occured\n");
		exit(1);
	}

	/* open both bin_file and hex_file */
	bin_file = fopen(argv[1], "r" );
	hex_file = fopen(argv[2], "w" );


	/* Loop through binary number from bin_file */
	while (fgets(line, sizeof(line), bin_file) != NULL){
		
		/* call function to convert to hexidecimal(binary(line)) */
		int result = (int)strtol(line, NULL, 2);
		printf("%i \n",result );
		


		/*print to  hex_file fprintf(bin_file, "%s\n", bin); */
	}

	//close files
	fclose(hex_file);
	fclose(bin_file);
	return (0);
}
