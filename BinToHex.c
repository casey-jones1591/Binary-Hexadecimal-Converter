#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

int main(int argc,char *argv[]){

	FILE * hex_file;
	FILE * bin_file;
	char binStr[MAX];
	char hexStr[MAX]="";

	/* ensure all command line arguments are given */
	if (argc != 3) {
		fprintf(stderr, "An error has occured\n");
		exit(1);
	}

	/* open both bin_file and hex_file */
	bin_file = fopen(argv[1], "r" );
	hex_file = fopen(argv[2], "w" );

	/* loop through binary numbers from bin_file */
	while (fgets(binStr, sizeof(binStr), bin_file) != NULL){
		int binLength = strlen(binStr)/4;  
		char *tempStr = (char *)malloc(5);
		int counter=0;

		/* convert the binary num to hex */
		for(int i=0; i<binLength; i++ ){
			strncpy(tempStr, binStr+counter, 4);
			counter=counter+4;
			
			if (strcmp(tempStr,"0000") == 0){
				strcat(hexStr,"0");
			} else if (strcmp(tempStr, "0001")==0){
				strcat(hexStr,"1");
			} else if (strcmp(tempStr, "0010")==0){
				strcat(hexStr,"2");
			} else if (strcmp(tempStr, "0011")==0){
				strcat(hexStr,"3");
			} else if (strcmp(tempStr, "0100")==0){
				strcat(hexStr,"4");
			} else if (strcmp(tempStr, "0101")==0){
				strcat(hexStr,"5");
			} else if (strcmp(tempStr, "0110")==0){
				strcat(hexStr,"6");
			} else if (strcmp(tempStr, "0111")==0){
				strcat(hexStr,"7");
			} else if (strcmp(tempStr, "1000")==0){
				strcat(hexStr,"8");
			} else if (strcmp(tempStr, "1001")==0){
				strcat(hexStr,"9");
			} else if (strcmp(tempStr, "1010")==0){
				strcat(hexStr,"a");
			} else if (strcmp(tempStr, "1011")==0){
				strcat(hexStr,"b");
			} else if (strcmp(tempStr, "1100")==0){
				strcat(hexStr,"c");
			} else if (strcmp(tempStr, "1101")==0){
				strcat(hexStr,"d");
			} else if (strcmp(tempStr, "1110")==0){
				strcat(hexStr,"e");
			} else if (strcmp(tempStr, "1111")==0){
				strcat(hexStr,"f");
			} else {
				fprintf(stderr, "An error has occured\n");
			}
							
		}
		/* print to hex_file and empty out hexStr */
		fprintf(hex_file, "%s\n", hexStr);
		strcpy(hexStr, "");

	}
	/* close files */
	fclose(hex_file);
	fclose(bin_file);
	return (0);
}
