#include <stdio.h>

/* The use of ternary is beneficial to keep a "if-else" block into a single line of code. */

int	main()
{
	float salary;

	printf("Please input the salary value: ");
	scanf("%f", &salary);
	/*if (salary > 1000)
	{
		salary *= 1.05;
	}
	else {
		salary *= 1.07;
	}*/

	/* The following line does the exact same as the block of code that is in comment above.*/
	salary = (salary > 1000 ? salary * 1.05 : salary * 1.07); /*"condition ? result1 : result 2" parenthesis are optional*/
	printf("New salary: %.2f\n", salary);
}