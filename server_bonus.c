/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <diteixei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:11:26 by diteixei          #+#    #+#             */
/*   Updated: 2024/06/13 10:51:02 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigact(int sig, siginfo_t *info, void *context);
int		ft_printnfree(int len, int c, char *str, siginfo_t *info);

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server PID: %i\n", getpid());
	sig.sa_sigaction = sigact;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	set_up_sigaction(&sig);
	while (1)
	{
	}
}

void	sigact(int sig, siginfo_t *info, void *context)
{
	static int				c;
	static int				bit;
	static int				len;
	static char				*str;

	(void)context;
	c |= (sig == SIGUSR1);
	bit++;
	usleep(250);
	if ((bit == 32 && len == 0) || (bit == 8 && len != 0))
	{
		if (bit == 32)
			len = c;
		else if (bit == 8)
			len = ft_printnfree(len, c, str, info);
		if (bit == 32)
			str = (char *)malloc(sizeof(char) * len + 1);
		c = 0;
		bit = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR2);
}

int	ft_printnfree(int len, int c, char *str, siginfo_t *info)
{
	static int	i;

	str[i++] = c;
	if (c == '\0')
	{
		ft_printf("%s", str);
		free(str);
		i = 0;
		kill(info->si_pid, SIGUSR1);
		return (0);
	}
	return (len);
}
