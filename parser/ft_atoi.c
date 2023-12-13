/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:45:22 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/08 21:10:22 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	ft_sing(char c, int *sing, unsigned long *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sing = *sing * (-1);
		*i = *i + 1;
	}
}

int	ft_atoi(char *str)
{
	unsigned long	i;
	int				sing;
	unsigned long	val;

	sing = 1;
	i = 0;
	val = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || '\v' == str[i]
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	ft_sing(str[i], &sing, &i);
	while (str[i] <= '9' && str[i] >= '0' && str[i])
	{
		val = val * 10 + (str[i] - 48);
		if (val > 9223372036854775807 && sing == 1)
			return (-1);
		else if (val > 9223372036854775807 && sing == -1)
			return (0);
		i++;
	}
	return (val * sing);
}
