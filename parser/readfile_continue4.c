/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_continue4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:07:04 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/08 21:36:08 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_element_count(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	if (i != 3 || numbers[3] != NULL)
	{
		printf("Error : Incorrect number of elements in c_f_first()\n");
		exit(0);
	}
}

void	c_f_first(char **numbers)
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		check_number_string(numbers[i]);
		i++;
	}
	check_element_count(numbers);
}

void	handle_error(char c)
{
	printf("Error : c_f_first(non-digit character '%c')\n", c);
	exit(0);
}

void	validate_character(char *number, int *j, int *last_digit)
{
	if (ft_iss_digit(number[*j]))
	{
		*last_digit = 1;
		(*j)++;
	}
	else if (number[*j] == ' ')
	{
		if (*last_digit && number[*j + 1] != '\0' && ft_iss_digit(number[*j
					+ 1]))
		{
			printf("Error Space inside a number in '%s'\n", number);
			exit(0);
		}
		(*j)++;
	}
	else
		handle_error(number[*j]);
}

void	check_number_string(char *number)
{
	int		j;
	int		last_digit;

	j = 0;
	last_digit = 0;
	while (number[j])
		validate_character(number, &j, &last_digit);
}
