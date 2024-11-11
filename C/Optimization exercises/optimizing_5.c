#include <stdio.h> 
#include <stdlib.h>

/* Original function */
int count_evens(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0)
            count++;
    return count;
}

/* Optimization */
int count_evens_opt(int *arr, int size)
{
	int	count = 0;
	int	*end = arr + size;
	while (arr++ < end)
		if (*arr % 2 == 0)
			count++;
	return count;
}

int	main()
{
	int	*nums;
	int	even = 0;
	
	nums = malloc(sizeof(int) * 5);
	if (!nums)
		return (0);
	for (int i = 0; i < 5; i++)
		nums[i] = i;
	even = count_evens(nums, 5);
	printf("There are %i even numbers.\n", even);
	even = count_evens(nums, 5);
	printf("There are %i even numbers.\n", even);
	free(nums);
}