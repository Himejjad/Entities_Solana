/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:08:42 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/09 08:50:22 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_path_with_check(t_map *map, char *str, char type)
{
	if (!check_commas(str, map->i))
	{
		printf("Erreur: Nombre incorrect de virgules pour '%c'\n", type);
		exit(0);
	}
	map->i++;
	if (type == 'C')
		map->c = set_path(map, str);
	else if (type == 'F')
		map->f = set_path(map, str);
}

void	check_and_set(t_map *map, char *str)
{
	if (!check_texture(map, str))
	{
		if (str[map->i] == 'C' && (str[map->i + 1] == ' ' || str[map->i
					+ 1] == '\t') && !map->c)
			set_path_with_check(map, str, 'C');
		else if (str[map->i] == 'F' && (str[map->i + 1] == ' ' || str[map->i
					+ 1] == '\t') && !map->f)
			set_path_with_check(map, str, 'F');
		else
		{
			printf("Erreur : check_and_set()\n");
			exit(0);
		}
	}
}

int	check_commas(const char *str, int start)
{
	int	count;
	int	i;

	count = 0;
	i = start;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count == 2);
}
