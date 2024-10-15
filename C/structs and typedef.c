#include <stdio.h>

struct person
{
	char	*name;
	int		age;
	char	gender;
};

typedef struct animal /* "typedef" allows to associate an intended type or value to a word, in this case, it associates the "struct animal" with the word "animal". */
{
	char	*name;
	int		age;
	char	gender;
	char	*type;
}animal;

typedef	int	integer; /* In this case we're making it so we can write "integer" and it working as another word for "int". */

void	print_data(struct person person) /* Just like normal variables, a struct can also be passed to a function.*/
{
	printf("%s, %i, %c.\n", person.name, person.age, person.gender);
}

void	print_data_animal(animal animal) /* Similarly, as an argument it also faces the same rules of defenition. If "typedef" is used, it also affects how it should be written as an argument.*/
{
	printf("%s, %i, %c, %s.\n", animal.name, animal.age, animal.gender, animal.type);
}

int	main()
{
	struct person James; /* If done like this, the structure is initialized empty.*/
	struct person Furina = {"Furina", 500, 'F'}; /* Just like variables, structs can also be initialized with values, using brackets and seperating each wiht a comma. */
	animal Tubs = {"Tubs", 6, 'M', "Dog"};
	integer number = 20;

	James.name = "James";
	James.age = 25;
	James.gender = 'M';
	print_data(James);
	print_data(Furina);
	print_data_animal(Tubs);
	printf("%i\n", number);
}