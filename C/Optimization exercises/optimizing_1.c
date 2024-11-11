#include <stdio.h> 
#include <stdlib.h>

/* Original function */
int sum_array(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

/* Optimization */
int	sum_array_opt(int *arr, int size)
{
	int	sum = 0;
	int	*end = arr + size;
	while (arr < end)
		sum += *arr++;
	return sum;
}

int	main()
{
	int	*nums;
	int	sum = 0;
	
	nums = malloc(sizeof(int) * 5);
	if (!nums)
		return (0);
	for (int i = 0; i < 5; i++)
		nums[i] = i;
	sum = sum_array(nums, 5);
	printf("Sum is %i\n", sum);
	sum = sum_array_opt(nums, 5);
	printf("Sum is %i\n", sum);
	free(nums);
}