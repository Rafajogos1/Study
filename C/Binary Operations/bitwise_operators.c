#include<stdio.h>

void	print_bitwise(int a, int b)
{
	printf("%i and %i = %i\n", a, b, a & b); /* It compares bit by bit and if both are 1, the result is 1, else it's 0. */
	printf("%i or %i = %i\n", a, b, a | b); /* It compares bit by bit and if at least one is 1, the result is 1, else, it's 0.*/
	printf("%i xor %i = %i\n", a, b, a ^ b); /* It compares bit by bit, and if at least one is 1, but the other isn't 1 as well, the result is 1, else, it's 0. */
	printf("not %i = %i\n", a, ~a); /* It reverses the value of each bit, if 0, it becomes 1, if 1 it becomes 0. */
	printf("not %i = %i\n", b, ~b); /* It reverses the value of each bit, if 0, it becomes 1, if 1 it becomes 0. */
	printf("%i << 1 = %i\n", a, a << 1); /* It shifts the bits by the following value to the left. */
	printf("%i << 1 = %i\n", b, b << 1); /* It shifts the bits by the following value to the left. */
	printf("%i >> 1 = %i\n", a, a >> 1); /* It shifts the bits by the following value to the right. */
	printf("%i >> 1 = %i\n", b, b >> 1); /* It shifts the bits by the following value to the right. */
}

int	main()
{
	print_bitwise(4, 5);
}