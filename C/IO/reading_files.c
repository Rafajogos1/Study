#include <stdio.h>
#include <stdlib.h>

/* Regardless of what operation is being done with files, we should ALWAYS close files that we open to avoid memory leaks. */
/* Just like we use "free()" to free memory that was allocated by "malloc()", we use "close()" to close every file opened with "open()". */

char	*read_file(const char *filename)
{
	FILE 	*file;
	int		count = 0;
	int		ch = 0;
	char	*string;

	if (!filename)
		return(NULL);
	file = fopen(filename, "r"); /* "r" is "read only". */
	if (file == NULL)
		return (NULL);
	while ((ch = fgetc(file))!= EOF) /* We need to know how many characters are in the file so we can properly allocate memory to the variable that will hold it. */
			count++;
	if (count == 0)
	{
		fclose(file);
		return (NULL);
	}
	count++;
	rewind(file); /* This returns the reading of the file to the beggining without needing to close and open it again. */
	string = malloc(sizeof(char) * count);
	if (!string)
		return (NULL);
	fgets(string, count, file); /* Works just like "fputs()", but it reads instead and stores it to a variable. */
	fclose(file);
	return (string);
}

int	main()
{
	char	*string;

	string = read_file("not_from_a_jedi.txt");
	if (string)
	{
		printf("%s\n", string);
		free(string);
	}
}