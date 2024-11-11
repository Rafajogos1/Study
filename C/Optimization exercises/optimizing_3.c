#include <stdio.h> 
#include <stdlib.h>

/* Original function */
int max_in_array(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

/* Optimization */
int max_in_array_opt(int *arr, int size)
{
	int	max =*arr;
	int	*end = arr + size;

	while (arr++ < end)
		if (*arr > max)
			max = *arr;
	return max;
}

int	main()
{
	int	*nums;
	int	max = 0;
	
	nums = malloc(sizeof(int) * 5);
	if (!nums)
		return (0);
	for (int i = 0; i < 5; i++)
		nums[i] = i;
	max = max_in_array(nums, 5);
	printf("Max is %i\n", max);
	max = max_in_array_opt(nums, 5);
	printf("Max is %i\n", max);
	free(nums);
}