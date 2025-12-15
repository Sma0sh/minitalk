/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <diteixei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:10:54 by diteixei          #+#    #+#             */
/*   Updated: 2024/06/13 10:40:06 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendstring(int pid, char *str);
void	ft_sendleng(int pid, size_t len);
void	ft_checkerror(int argc, char **argv);
void	ft_sigchandler(int signum);

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_handler = ft_sigchandler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	set_up_sigaction(&sig);
	ft_checkerror(argc, argv);
	pid = ft_atoi(argv[1]);
	ft_sendleng(pid, ft_strlen(argv[2]));
	ft_sendstring(pid, argv[2]);
	return (0);
}

void	ft_sigchandler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf(".");
}

void	ft_sendleng(int pid, size_t len)
{
	int	bit;

	bit = 31;
	while (bit >= 0)
	{
		if (len & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		pause();
	}
}

void	ft_sendstring(int pid, char *str)
{
	size_t	i;
	int		bit;

	i = 0;
	while (i != (ft_strlen(str) + 1))
	{
		bit = 0;
		while (bit != 8)
		{
			if (((str[i] << bit) & 0x80) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			pause();
		}
		i++;
	}
}

void	ft_checkerror(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("!Error!\n@/Try 2 arguments./@\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) != 1)
		{
			ft_printf("!Error!\n@/PID is invalid./@\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (argv[2][0] == '\0')
	{
		ft_printf("!Error!\n@/Message is empty./@\n");
		exit(EXIT_FAILURE);
	}
}
