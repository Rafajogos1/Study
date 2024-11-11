#include <stdio.h> 
#include <stdlib.h>

/* Original function */
int product_array_reverse(int *arr, int size)
{
    int product = 1;
    for (int i = size - 1; i >= 0; i--)
        product *= arr[i];
    return product;
}

/* Optimization */
int product_array_reverse_opt(int *arr, int size)
{
	int	product = 1;
	arr += size - 1;
	while (size--)
		product *= *arr--;
	return product;
}

int	main()
{
	int	*nums;
	int	pro = 0;
	
	nums = malloc(sizeof(int) * 5);
	if (!nums)
		return (0);
	for (int i = 0; i < 5; i++)
		nums[i] = i + 1;
	pro = product_array_reverse(nums, 5);
	printf("Product is %i\n", pro);
	pro = product_array_reverse_opt(nums, 5);
	printf("Product is %i\n", pro);
	free(nums);
}