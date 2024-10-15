#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
	char	*name;
	int		age;
	char	gender;
}person;

/* "void" is a versatile varaible type. It is nothing, but at the same time it can be anything.*/

void	print_data(person person) /* A "void" function returns nothing, therefore, it can do any operation without the limitation of having to return a value. */
{
	printf("%s, %i, %c.\n", person.name, person.age, person.gender);
}

void	*return_something(char type) /* A "void *" function, on the other hand, can return a pointer to anything, as long as it's properly cast.*/
{
	static int	nums[3];
	char		*name = "John";

	nums[0] = 0;
	nums[1] = 5;
	nums[2] = 10;
	if (type == 'i')
		return ((void *)nums);
	if (type == 'c')
		return ((void *)name);
	return (NULL);
}

int main()
{
	person 	Furina = {"Furina", 500, 'F'};
	void *pointer;

	print_data(Furina);
	pointer = return_something('i');
	if (pointer)
		printf("%i, %i, %i.\n", ((int *)pointer)[0], ((int *)pointer)[1], ((int *)pointer)[2]);
	pointer = return_something('c');
	if (pointer)
	printf("%s.\n", (char *)pointer);
}