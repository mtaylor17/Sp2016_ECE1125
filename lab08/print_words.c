/*  Lab 08
    Part 4
    Matt Taylor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

int process_line(char *line, size_t n)
{
    int i = 0, temp = 0, g = 0;
    while(*(line + i) != '\0'){
        if(isspace(*(line + i)) != 0){
            char *p = malloc((i - temp + 1) * sizeof(char));
            g = temp;
            for(; temp < i; temp ++){
                *(p + (temp - g)) = *(line + temp);
            }
            fputs(p, stdout);
            printf("\n");
            fflush(stdout);
            while(isspace(*(line + temp)) != 0){ // skips white spaces
                temp ++;
            }
            free(p);
            i = temp;
        }
        else{
            i ++;
        }
    }
	return 0;
}

int main(int argc, char *argv[])
{
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
			if (process_line(lineptr, rc) < 0) {
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

	fclose(fp);
	exit(exit_status);
}
