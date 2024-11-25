#include <stdio.h>

/* Switches can be benefical to use when compared to using multiple "else if" blocks. */
/* Their efficiency depends on the case. */

int main()
{
	char letter;

	printf("Please input a letter: \n");
	scanf("%c", &letter);
	if (!(64 < letter && letter < 91) && !(96 < letter && letter < 123))
		printf("The character you inputed is not a letter.\n");
	else
	{	
		/* A switch will take a varaible and compare it against very single case and can have different results. */
		/* In the example below, the switch compares the letter to each vowel and only prints that it is a vowel after checking each vowel case. */
		/* As explained below, we can have multile cases with the same result. */
		switch(letter)
		{
			case 'A': /*When used like this, it will enter the "case" and execute the code in front of it, however, it doesn't mean it won't execute the following code.*/
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
			case 'Y':
			case 'y': printf("Vowel.\n"); break; /*By using "break", we make it so that the following code lines aren't executed after the comparasion enters "case".*/
			default : printf("Consonant.\n"); /*The "default" is the intended result in case any of the previous comparasions fail. It is not required.*/

			/* In this example, we compare the letter with every vowel, and since "break" only appears in the last case, the code for every previous case will be the same. */
			/* While the line only appears in the 'y' case, since the code doesn't stop for the previous ones, it is still considered to be their intended result. */
			/* After the 'y' case however, "break" makes the code stop there if the case is either 'y' or anything that appeared before it (in this case the other vowels). */
			/* While we could techincally do a case for non-vowels, in cases where there are only two possible outcomes, we can simply make the other outcome the "default" behaviour. */
			/* Essentially, in this case, this switch acts as "if a - 1, else - 0". */
		}
	}
}