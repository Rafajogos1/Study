#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/* "Condition variables" are synchronization objects of the type "pthread_cond_t" that can make threads continue only when needed. */
/* Their behaviour might appear simillar to mutexes, however, they don't necessarily block other threads when a thread acts upon it. */
/* While a mutex is blocked and it prevents other threads that need it to wait, a condition variable can ensure that other threads won't wait. */
/* While they appear to be simillar to "bool" variables, they dont't take a "true" or "false" values, bur rather, they are broadcast. */
/* By using a function such as "pthread_cond_wait()", we can make a thread wait for the speciefied condition variable to be broadcast. */
/* By using either "pthread_cond_broadcast()" or "pthread_cond_signal()", essentially, we're sending a signal or broadcast that the variable is "active". */
/* Any thread waiting for the condition variable to be broadcast, will continue. */
/* Waiting on a conidition variable also means that a mutex will be locked by the awaiting thread, to prevent race conditions. */
/* If a thread is waiting on a condition variable, it will unlock the specified mutex if it owns it. */
/* To summarize, we can control the behaviour of threads and ensure that they only act when needed, preventing other threads to wait because of a locked mutex. */

typedef struct t_data
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	int				value;
	int				turns;
}t_data;


void	*produce(void *arg)
{
	int		i = 0;

	t_data	*data = (t_data *)arg;
	data->value = i;
	while (data->turns)
	{
		data->value = i + 1;
		i++;
		printf("The producer created the value \"%i\".\n", data->value);
		pthread_cond_broadcast(&(data->cond)); /* This function broadcasts the condition variable. Any waiting thread will continue upon it. */
		usleep(50); /* Since this thread waits for the condition variable to be broafcast again, we make it wait so it doesn't act upon its own broadcast. */
		pthread_cond_wait(&(data->cond), &(data->mutex));	
		while (data->value != 0) /* This ensures that the value has been consumed before continuing. */
			usleep(1);
		data->turns--;
	}
	return NULL;
}

void	*consume(void *arg)
{
	t_data	*data = (t_data *)arg;
	usleep(50); /* This ensures that the producer has enough time to produce the first value before the consumer consumes it.*/
	while (data->turns)
	{
		pthread_cond_wait(&(data->cond), &(data->mutex));
		if (data->value != 0)
		{
			printf("The consumer consumed the value \"%i\".\n", data->value);
			data->value = 0;
			pthread_cond_broadcast(&(data->cond));
			usleep(50);
		}
	}
	return NULL;
}

int	main()
{
	pthread_t	producer;
	pthread_t	consumer;
	t_data		data;

	data.turns = 5;
	pthread_cond_init(&(data.cond), NULL);
	pthread_mutex_init(&(data.mutex), NULL);
	if (pthread_create(&producer, NULL, produce, &data) \
		|| pthread_create(&consumer, NULL, consume, &data) != 0)
	{
		printf("Error while creating threads.\n");
		return 0;
	}
	pthread_cond_destroy(&(data.cond));
	pthread_mutex_destroy(&(data.mutex));
	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);
	printf("\nTask complete!\n");
}