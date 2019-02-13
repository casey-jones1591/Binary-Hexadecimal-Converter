#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main(int argc,char *argv[]){
	
	FILE * hex_file;
	FILE * bin_file;
	char hexStr[MAX];
	char binStr[MAX]= "";
	
	/* ensure all command line arguments are given */
	if (argc != 3) {
		fprintf(stderr, "An error has occured\n");
		exit(1);
	}

	/* open both bin_file and hex_file */
	hex_file = fopen(argv[1], "r" );
	bin_file = fopen(argv[2], "w" );

	/* loop through hexadecimal number from hex_file */
	while (fgets(hexStr, sizeof(hexStr), hex_file) != NULL){	

		/* convert each hexidecimal digit to binary and append to binStr */
		for(int i=0; hexStr[i]!= '\n'; i++){
			
			switch (hexStr[i]){
				case '0':
			       		strcat(binStr, "0000"); 
					break;
				case '1':
					strcat(binStr, "0001"); 
					break;
				case '2':
					strcat(binStr, "0010");
					break;
				case '3':
					strcat(binStr, "0011"); 
					break;
				case '4':
					strcat(binStr, "0100"); 
					break;
				case '5':
					strcat(binStr, "0101"); 
					break;
				case '6':
					strcat(binStr, "0110"); 
					break;
				case '7':
					strcat(binStr, "0111"); 
					break;
				case '8':
					strcat(binStr, "1000"); 
					break;
				case '9':
					strcat(binStr, "1001"); 
					break;
				case 'a':
					strcat(binStr, "1010"); 
					break;
				case 'b':
		           		strcat(binStr, "1011"); 
					break;
				case 'c':
            				strcat(binStr, "1100"); 
					break;
        			case 'd':
            				strcat(binStr, "1101"); 
					break;
        			case 'e':
            				strcat(binStr, "1110"); 
					break;
				case 'f':
            				strcat(binStr, "1111"); 
					break;
				default:
					fprintf(stderr, "An error has occured\n");
					exit(1); 
			}
			
		}
		/* print to bin_file and clear binStr */
		fprintf(bin_file, "%s\n", binStr);
		strcpy(binStr, "");
	}
	/* close files */
	fclose(hex_file);
	fclose(bin_file);
	return (0);
}
