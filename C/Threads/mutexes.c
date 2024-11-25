#include <pthread.h>
#include <stdio.h>

/* A mutex (mutual exclusion) acts as a lock to prevent threads to access the same data at the same time. */
/* If two threads tried to access the same variable at the same time, it's possible that only the operation of one of the threads is kept. */
/* A race condition is when two operations happen at the same time, unintended. To prevent them, we ask a thread to lock a mutex and then perform the intended action. */
/* A mutex can't be locked by two threads at once, so a repeated action of locking it will halt the thread that attempted it. */
/* Once the mutex is unlocked, it can be locked again by a different thread. Any halted thread will try to lock it again and resume if successful. */

/* This struct contains a mutex and a counter. By doing this, we can pass multiple variables to the same thread function. */
typedef struct mutex_data
{
	pthread_mutex_t	mutex;
	int				shared_counter;
}mutex_data;

/* This function locks the mutex, increases the global counter, the unlocks the mutex for other threads to use. */
void	*thread_function(void *arg)
{
	mutex_data *data = (mutex_data*)arg;
	pthread_mutex_lock(&(data->mutex));
	printf("Increased counter from %i to %i.\n", data->shared_counter, data->shared_counter + 1);
	data->shared_counter++;
	pthread_mutex_unlock(&(data->mutex));
	return NULL;
}

int	main()
{
	int			thread_count = 5;
	pthread_t	threads[thread_count]; /* The array of threads. */
	mutex_data	counter; /* A "mutex_data" struct variable that contains the mutex and the shared counter. */

	counter.shared_counter = 0;
	pthread_mutex_init(&(counter.mutex), NULL); /* This function recieves a pointer of a mutex and initializes it. */
	for(int i = 0; i < thread_count; i++)
	{
		if (pthread_create(&threads[i], NULL, thread_function, &counter) != 0) /* Here we sent a pointer of a "mutex_data" struct variable. */
		{
			printf("Error while creating threads.\n");
			return 0;
		}
	}
	/* This loop terminates each thread once they have run their code. */
	for (int i = 0; i < thread_count; i++)
		pthread_join(threads[i], NULL);
	pthread_mutex_destroy(&(counter.mutex));
	printf("\nTask complete! Final counter: %i\n", counter.shared_counter);
}