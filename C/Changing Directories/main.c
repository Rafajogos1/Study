#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

int	main(void)
{
	const char	*dir_path = "./b";
	DIR			*dir;
	FILE 		*file;

	if (chdir(dir_path) != -1)
		file = fopen("test_file.txt", "w");
	else
	{
		printf("no such file or directory: \"%s\"\n", dir_path);
		exit(EXIT_FAILURE);
	}
	fclose(file);
	closedir(dir);
}
