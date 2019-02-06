#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main(int argc,char *argv[])
{
	FILE * hex_file;
	FILE * bin_file;
	char line[MAX];
	char bin[MAX]= "";
	int i=0;

	/* ensure all command line arguments are given */
	if (argc != 3) {
		printf("An error has occured\n");
		exit(1);
	}

	/* open both bin_file and hex_file */
	hex_file = fopen(argv[1], "r" );
	bin_file = fopen(argv[2], "w" );


	/* Loop through hexadecimal number from hex_file */
	while (fgets(line, sizeof(line), hex_file) != NULL){
		
		/* convert each hexidecimal digit to binary and append to bin*/
		for(i=0; line[i] !='\0'; i++ ){
			switch (line[i]){
				case '0':
			       		strcat(bin,"0000"); break;
				case '1':
					strcat(bin,"0001"); break;
				case '2':
					strcat(bin,"0010"); break;
				case '3':
					strcat(bin,"0011"); break;
				case '4':
					strcat(bin,"0100"); break;
				case '5':
					strcat(bin,"0101"); break;
				case '6':
					strcat(bin,"0110"); break;
				case '7':
					strcat(bin,"0111"); break;
				case '8':
					strcat(bin,"1000"); break;
				case '9':
					strcat(bin,"1001"); break;
				case 'a':
					strcat(bin,"1010"); break;
				case 'b':
		           		strcat(bin,"1011"); break;
				case 'c':
            				strcat(bin,"1100"); break;
        			case 'd':
            				strcat(bin,"1101"); break;
        			case 'e':
            				strcat(bin,"1110"); break;
				case 'f':
            				strcat(bin,"1111"); break;
				default:
					break;  //?? should there be some kind of 
			}
		}
		
		/* print to bin_file and clear bin */
		fprintf(bin_file, "%s\n", bin);
		//memset(bin,0,sizeof(bin));
	}

	/* close files */
	fclose(hex_file);
	fclose(bin_file);
	return (0);
}
