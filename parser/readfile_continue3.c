/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:06:27 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/09 09:15:35 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_wc_l(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_iss_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	check_c_f(t_map *map)
{
	map->ceiling.numbers = ft_split(map->c, ',');
	map->floor.numbers = ft_split(map->f, ',');
	c_f_first(map->ceiling.numbers);
	map->ceiling.r = ft_atoi(map->ceiling.numbers[0]);
	map->ceiling.g = ft_atoi(map->ceiling.numbers[1]);
	map->ceiling.b = ft_atoi(map->ceiling.numbers[2]);
	c_f_first(map->floor.numbers);
	map->floor.r = ft_atoi(map->floor.numbers[0]);
	map->floor.g = ft_atoi(map->floor.numbers[1]);
	map->floor.b = ft_atoi(map->floor.numbers[2]);
	c_f_end(map);
}
