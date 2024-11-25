#include <stdio.h>

/* "fprintf()" works the same way as "printf()", however, instead of printing the text into the console, it prints it into a file. */

typedef struct person
{
	char	*name;
	int		age;
	char	gender;
	char	*function;
}person;

void	data_to_file(const char *filename, const person data)
{
	FILE	*file;

	if (!filename)
		return;
	file = fopen(filename, "a");
	if (file == NULL)
		return;
	fprintf(file, "Name: %s\nAge: %i\nGender: %c\nFunction: %s\n\n", data.name, data.age, data.gender, data.function);
	fclose(file);
	return;
}

int main()
{
	person	John = {"John", 27, 'M', "Janitor"};
	person	Natalia = {"Natalia", 22, 'F', "Accountant"};
	person	Jeremy = {"Jeremy", 34, 'M', "High-school Teacher"};
	person	Lucy = {"Lucy", 19, 'F', "College Student"};
	data_to_file("person_data.txt", John);
	data_to_file("person_data.txt", Natalia);
	data_to_file("person_data.txt", Jeremy);
	data_to_file("person_data.txt", Lucy);
}