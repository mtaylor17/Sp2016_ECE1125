/*  Lab 08
    Part 4
    Matt Taylor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

struct count{
	int lines;
	int words;
	int characters;
};

int process_line(char *line, size_t n, struct count * count1)
{
	int i = 0, temp = 0;
    while(*(line + i) != '\0'){
    	if(*(line) == '\n'){
    		break;
    	}
        if(isspace(*(line + i)) != 0){
        	while(temp < i){
        		temp ++;
        	}
            while(isspace(*(line + temp)) != 0){ // skips white spaces
           	temp ++;
        	}
        	if(i != 0){
        		count1->words ++;
        	}
        	i = temp;
        }
        else{
        	count1->characters ++;
        	if(*(line + i + 1) == '\0'){
        		count1->words ++;
        	}
        	i++;
        }
    }
	count1->lines ++;
	return 0;
}

int main(int argc, char *argv[])
{
	
	struct count count1;
	count1.lines = 0;
	count1.words = 0;
	count1.characters = 0;
	
	int exit_status = 0;
	FILE *fp;


	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));

			exit(1);
		}
	}


	size_t n = 0;
	char *lineptr = 0;

	for (;;) {
		ssize_t rc = getline(&lineptr, &n, fp);

		if (rc < 0) {
			break;
		}

		if (rc > 0) {
			if (process_line(lineptr, rc, &count1) < 0) {
				exit_status = 1;
				free(lineptr);
				break;
			}
		}

		free(lineptr);
		lineptr = 0;
		n = 0;
	}

	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		exit_status = 1;
	}
	printf("Lines: %d	Words: %d	Characters: %d\n", count1.lines, count1.words, count1.characters);
	
	fclose(fp);
	exit(exit_status);
}
