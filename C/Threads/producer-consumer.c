#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct
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
		data->value = i;
		i++;
		printf("The producer created the value \"%i\".\n", data->value);
		pthread_cond_broadcast(&(data->cond));
		usleep(50);
		pthread_cond_wait(&(data->cond), &(data->mutex));
		data->turns--;
	}
	return NULL;
}

void	*consume(void *arg)
{
	t_data	*data = (t_data *)arg;
	usleep(50);
	while (data->turns)
	{
		pthread_cond_wait(&(data->cond), &(data->mutex));
		if (data->value != 0)
		{
			printf("The consumer consumed the value \"%i\".\n", data->value);
			data->value = 0;
		}
		pthread_cond_broadcast(&(data->cond));
		usleep(50);
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