/* 	Lab 08
	Part 1
	Matt Taylor	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int process_line(char *line, size_t n)
{
	/* Q10: What do the fputs and fflush functions do?
	
			fputs: Writes a string to the specified stream up to but not including the NULL character
			fflush: Flushes the output buffer of a stream	*/
		
	 /* Q11: Why should we use them instead of printf or fprintf? 
	 
	 		printf and fprintf allow for formatted output. They interpret a format string you supply and writes to the output stream the results
	 		However, fputs doesnt have to parse the input string to figure out that all you want to do is print a string.	*/
	 	
	 		
	 
	/* Q12: What does the value of n represent? */
		
		/*	It specifies the size in bytes of the block of memory pointed to by the first parameter	*/

	fputs(line, stdout);
	fflush(stdout);

	return 0;
}

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;

	/* Q1: What values do argc and argv have when this program is run
	 * without any command-line parameters?
	 		
	 		argc has the value 1. argv contains the strings ./getline. This is assuming that ./getline is not a command-line parameter in
	 		itself. 
	 		
	 * Q2: What value do they have when run with a filename as
	 * an input argument?
	 
	 		argc has the value 2. argv contains the strings ./getline and whatever the filename is
	 */
	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");

		/* Q3: When is the condition !fp true, and when is it false
		
			!fp is true when the input file is corrupt or not the correct file type. !fp is false when it is the correct file type and
			able to be opened. 
		
		 * Q4: strerror() is called with the global variable
		 * errno that the C library maintains internally.
		 * What does strerror do?
		 
		 	Returns to the string a pointer that describes the error code passed in the argument errno.
		 	
		 */

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
			/* Q5: What does the exit() library function do? 
			
			exit() causes normal process termination. The argument of 1 shows that the program exits with a status of exit_success
			
			*/
			exit(1);
		}
	}


	size_t n = 0;
	char *lineptr = 0;

	/* Q6: What does a for(;;) loop do?
	
		for(;;) is the same as while(true). The loop keeps running until it breaks out of the loop, or exits the program. 
	
	*/
	for (;;) {
		/* Q7: What is the difference between the types size_t
		 * and ssize_t ?
		 
		 	size_t is an unsigned int used in the standard library for representing sizes. ssize_t is the same as size_t, however it is a
		 	signed int. This allows it to return -1 as an error message. size_t higher sized values than ssize_t since it is unsigned.
		 
		 */
		ssize_t rc = getline(&lineptr, &n, fp);

		/* Q8: What does the getline function do? 
		
			getline reads a line from stream and stores the address of the buffer containing the text into *lineptr
		
		 * Q9: What does it return in the normal case,
		 * upon EOF, and upon error?
		 
		 	getline returns the updated *lineptr and *n which repretent the buffer address and allocated size respectively
		 
		 */

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
