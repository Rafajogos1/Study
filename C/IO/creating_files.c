#include <stdio.h>

void	create_file(const char *filename, const char *string)
{
	FILE	*file;

	if (!filename || !string)
		return;
	file = fopen(filename, "w+");
	if (file == NULL)
		return;
	fputs(string, file);
	fclose(file);
	return;
}

int	main()
{
	create_file("not_from_a_jedi.txt", "Did you ever hear the tragedy of Darth Plagueis the wise?");
}