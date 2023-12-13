/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:08:17 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/08 21:28:06 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*set_path(t_map *map, char *str)
{
	char	*dst;
	int		j;

	dst = NULL;
	if (str[map->i] == ' ' || str[map->i] == '\t')
	{
		while (str[map->i] && (str[map->i] == ' ' || str[map->i] == '\t'))
			map->i++;
		j = 0;
		while (str[map->i + j] && str[map->i + j] != '\n')
			j++;
		dst = (char *)malloc(j + 1);
		map->j = 0;
		while (str[map->i] && str[map->i] != '\n')
			dst[map->j++] = str[map->i++];
		dst[map->j] = '\0';
		return (dst);
	}
	else
	{
		printf("Error : set_path()\n");
		exit(0);
	}
}

int	set_texture_path(t_map *map, char *str, char *texture_id,
		char **texture_path)
{
	char	*path;

	if (str[map->i] == texture_id[0] && str[map->i + 1] == texture_id[1]
		&& !(*texture_path))
	{
		map->i += 2;
		path = set_path(map, str);
		if (!check_path(path, ".xpm"))
		{
			printf("Error : PATH texture '%s' ne se termine pas par '.xpm'\n",
				texture_id);
			free(path);
			return (0);
		}
		*texture_path = path;
		return (1);
	}
	return (0);
}

int	check_texture(t_map *map, char *str)
{
	if (set_texture_path(map, str, "NO", &map->no))
		return (1);
	if (set_texture_path(map, str, "SO", &map->so))
		return (1);
	if (set_texture_path(map, str, "WE", &map->we))
		return (1);
	if (set_texture_path(map, str, "EA", &map->ea))
		return (1);
	return (0);
}
