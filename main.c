/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:53:22 by arahmoun          #+#    #+#             */
/*   Updated: 2023/12/10 16:22:51 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_path(char *str, char *extension)
{
	int		i;
	int		j;
	char	*cub;

	j = 0;
	cub = ft_strdup(extension);
	i = ft_len(str) - 4;
	while (cub[j] && str[i])
	{
		if (str[i] != cub[j])
		{
			free(cub);
			return (0);
		}
		i++;
		j++;
	}
	if (!str[i] && !cub[j])
	{
		free(cub);
		return (1);
	}
	free(cub);
	return (0);
}

void	init_t_map(t_map *ptr)
{
	ptr->no = NULL;
	ptr->so = NULL;
	ptr->we = NULL;
	ptr->ea = NULL;
	ptr->map = NULL;
	ptr->maps = NULL;
	ptr->dst = NULL;
	ptr->c = NULL;
	ptr->f = NULL;
	ptr->ceiling.numbers = NULL;
	ptr->floor.numbers = NULL;
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	*ptr;
	t_game	*game;

	ptr = (t_map *)malloc(sizeof(t_map));
	game = (t_game *)malloc(sizeof(t_game));
	game->t_map = ptr;
	fd = open(av[1], O_RDWR);
	if (ac != 2 || fd == -1 || !check_path(av[1], ".cub"))
	{
		free(ptr);
		free(game);
		printf("Error\n%sinvalid path\n%s ", RED, DEFFAULT);
		return (0);
	}
	else
	{
		init_t_map(ptr);
		read_file(ptr, fd);
		start_mlx(game);
	}
}
