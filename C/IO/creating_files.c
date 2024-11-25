#include <stdio.h>

/* This function creates a file named "filename" and adds the text contained in "string" to it. */
/* @param *filename The name of the file to be created. */
/* @param *string The text that will be written into the file. */
void	create_file(const char *filename, const char *string)
{
	FILE	*file;

	if (!filename || !string) /* Check if neither are NULL as they're both necessary. */
		return;
	file = fopen(filename, "w+"); /* "w+"" creates a file if it doesn't exit and opens it in "read and write". "r+" doesn't create a file if it doesn't exit. */
	if (file == NULL)
		return;
	fputs(string, file);
	fclose(file); /* To prevent memory leaks, just like the "free()" function. */
	return;
}

int	main()
{
	create_file("not_from_a_jedi.txt", "Did you ever hear the tragedy of Darth Plagueis the wise?");
}