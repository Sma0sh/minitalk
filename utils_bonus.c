/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <diteixei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:11:35 by diteixei          #+#    #+#             */
/*   Updated: 2024/06/13 10:51:07 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	set_up_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
		ft_printf("Error setting up SIGUSR1");
	if (sigaction(SIGUSR2, sa, NULL) < 0)
		ft_printf("Error setting up SIGUSR2");
}
