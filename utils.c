/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <diteixei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:11:31 by diteixei          #+#    #+#             */
/*   Updated: 2024/06/13 10:32:45 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_up_sigaction(struct sigaction *sig)
{
	if (sigaction(SIGUSR1, sig, NULL) < 0)
		ft_printf("Error setting up SIGUSR1");
	if (sigaction(SIGUSR2, sig, NULL) < 0)
		ft_printf("Error setting up SIGUSR2");
}
