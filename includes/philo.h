#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

#define ARGUMENT_ERROR 100
#define WRONG_NUM_OF_PHILO 101
#define WRONG_TIME_TO_DIE 102
#define WRONG_TIEM_TO_EAT 103
#define WRONG_TIEM_TO_SLEEP 104
#define WRONG_NUM_OF_MUST_EAT 105
#define FAILED_TO_MEMORY 106
#define FAILED_TO_MUTAX 107

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct	s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				stop;
	int				start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	status;
	t_philo			*philo;
};

struct	s_philo
{
	int				n;
	int				fork_l;
	int				fork_r;
	int				start_time;
	int				meals;
	pthread_t		philo_th;
	pthread_t		monitor;
	pthread_mutex_t	protect;
	t_info			*info;
};

// utils.c
int print_error(int error_int);
// free_all.c
void free_all(t_info *info);
#endif