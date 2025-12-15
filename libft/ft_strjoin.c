/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diteixei <diteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:52:19 by diteixei          #+#    #+#             */
/*   Updated: 2024/04/29 11:56:04 by diteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	re = ft_calloc(sizeof(char), (s1len + s2len + 1));
	if (!re)
		return (0);
	ft_strlcpy(re, s1, s1len + s2len + 1);
	ft_strlcat(re, s2, s1len + s2len + 1);
	return (re);
}
