/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:48:15 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/13 16:49:33 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	int	i = 0;

	while (i < 1000000)
	{	
		pthread_mutex_lock(&philo->mutex);
		philo->score++;
		i++;
		pthread_mutex_unlock(&philo->mutex);
	}
	return (NULL);
}

void	ft_init_philo(t_philo *philo)
{
	pthread_mutex_init(&philo->mutex, NULL);
	philo->score = 0;
}

int	main()
{
	t_philo		philo;
	pthread_t	threads[THREADS];
	int			i = 0;

	ft_init_philo(&philo);
	// Create threads
	while (i < THREADS)
	{	
		if (pthread_create(&threads[i], NULL, &ft_routine, &philo) != 0)
			return (EXIT_FAILURE);
		printf("Thread Started Execution\n");
		i++;
	}
	// Join thrades
	i = 0;
	while (i < THREADS)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (EXIT_FAILURE);
		printf("Thread Finished Execution\n");
		i++;
	}
	printf("Score: %d\n", philo.score);
	pthread_mutex_destroy(&philo.mutex);
	return (0);
}
