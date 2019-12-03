/*  Lab 08
    Part 2
    Matt Taylor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int process_line(char *line, size_t n)
{
    int i;
    for(i = 0; *(line + i) != '\0'; i ++){
        if(*(line + i) < 91 && *(line + i) > 64){
            *(line + i) += 32;
        }
    }
	fputs(line, stdout);
	fflush(stdout);

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
