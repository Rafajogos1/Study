#include <stdio.h>
#include <stdlib.h>

char	*read_file(const char *filename)
{
	FILE 	*file;
	int		count = 0;
	int		ch = 0;
	char	*string;

	if (!filename)
		return(NULL);
	file = fopen(filename, "r");
	if (file == NULL)
		return (NULL);
	while ((ch = fgetc(file))!= EOF)
			count++;
	if (count == 0)
	{
		fclose(file);
		return (NULL);
	}
	count++;
	rewind(file);
	string = malloc(sizeof(char) * count);
	if (!string)
		return (NULL);
	fgets(string, count, file);
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