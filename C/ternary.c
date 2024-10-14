#include <stdio.h>

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
	salary = (salary > 1000 ? salary * 1.05 : salary * 1.07); /*"condition ? result1 : result 2" parenthesis are optional*/
	printf("New salary: %.2f\n", salary);
}