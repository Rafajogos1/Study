#include <pthread.h>
#include <stdio.h>

/* The thread function always has a prototype of "void *function_name(void *argument)". */
/* This function prints the thread id. */
/* @param arg the argument passed when creating a thread. */
void	*thread_function(void *arg)
{
	int	number = *(int *)arg; /* The argument is cast into an int pointer, which is then deferenced. */
	printf("I'm thread %i\n", number);
	return NULL;
}

int	main()
{
	int			thread_count = 5;
	int			thread_ids[thread_count]; /* Only so we can pass an argument to the thread function. It will hold the thread id. */
	pthread_t	threads[thread_count]; /* The array of threads. */

	/* This loop creates the threads and passes a pointer to the id number to the thread function. */
	for(int i = 0; i < thread_count; i++)
	{
		thread_ids[i] = i;
		if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) /* This condition ensures termination in case of an error. */
		{
			printf("Error while creating threads.\n");
			return 0;
		}
	}
	/* This loop terminates each thread once they have run their code. */
	for (int i = 0; i < thread_count; i++)
		pthread_join(threads[i], NULL);
	printf("\nTask complete!\n");
}