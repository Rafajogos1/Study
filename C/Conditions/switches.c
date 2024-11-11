#include <stdio.h>

int main()
{
	char letter;

	printf("Please input a letter: \n");
	scanf("%c", &letter);
	if (!(64 < letter && letter < 91) && !(96 < letter && letter < 123))
		printf("The character you inputed is not a letter.\n");
	else
	{	
		switch(letter)
		{
			case 'A': /*When used like this, it will enter the "case" and execute the code in front of it, however, it doesn't mean it won't execute the following code.*/
			case 'a': printf("Vowel.\n"); break; /*By using "break", we make it so that the following code lines aren't executed after the comparasion enters "case".*/
			case 'E':
			case 'e': printf("Vowel.\n"); break;
			case 'I':
			case 'i': printf("Vowel.\n"); break;
			case 'O':
			case 'o': printf("Vowel.\n"); break;
			case 'U':
			case 'u': printf("Vowel.\n"); break;
			case 'Y':
			case 'y': printf("Vowel.\n"); break;
			default : printf("Consonant.\n"); /*The "default" is the intended result in case any of the previous comparasions fail. It is not required.*/
		}
	}
}