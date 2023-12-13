/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:21:27 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/10 20:37:00 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_free_tmp_g(char **tmp)
{
	int	i;

	if (tmp == NULL)
		return ;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	check_wall_line(char *line, int width, char *error_message)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			printf("%s\n", error_message);
			exit(1);
		}
		i++;
	}
}

void	check_side_walls(char **lines, int height, char *error_message)
{
	int	i;
	int	width;

	i = 0;
	while (i < height)
	{
		width = ft_len(lines[i]);
		if ((lines[i][0] != '1' && lines[i][0] != ' ')
			|| (lines[i][width - 1] != '1'
				&& lines[i][width - 1] != ' '))
		{
			printf("%s\n", error_message);
			exit(1);
		}
		if ((i - 1 >= 0 && ft_len(lines[i - 1]) > width
				&& !check_zero(lines[i - 1], width))
			|| (i + 1 < height && ft_len(lines[i + 1]) > width
				&& !check_zero(lines[i + 1], width)))
		{
			printf("%s\n", error_message);
			exit(1);
		}
		i++;
	}
}

void	check_walls(t_map *map)
{
	int		height;

	height = ft_wc_l(map->maps);
	check_wall_line(map->maps[0], ft_len(map->maps[0]),
		"Error: Maps n'est pas entoure de (1)");
	check_wall_line(map->maps[height - 1], ft_len(map->maps[height - 1]),
		"Error: Maps n'est pas entoure de (1)");
	check_side_walls(map->maps, height, "Error: Maps n'est pas entoure de (1)");
}

int	item_chr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		i++;
	if (c == s[i])
		return (i);
	return (-1);
}
