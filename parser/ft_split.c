/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:44:48 by bel-kase          #+#    #+#             */
/*   Updated: 2023/12/08 13:46:45 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static int	ft_is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static void	ft_alocate(char **tab, char *s, char c, int w)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	j = 0;
	a = 0;
	while (j < w)
	{
		i = 0;
		while (ft_is_sep(s[a], c))
			a++;
		while (ft_is_sep(s[a + i], c) == 0)
		{
			if (ft_is_sep(s[a + i + 1], c) || s[a + 1 + i] == '\0')
			{
				i++;
				tab[j] = (char *)malloc(i + 1);
				a = a + i;
				break ;
			}
			i++;
		}
		j++;
	}
}

static void	ft_fill_split(char **tab, char *s, char c)
{
	int	i;
	int	j;
	int	a;
	int	skip;

	j = 0;
	i = 0;
	skip = 0;
	while (tab[j])
	{
		a = 0;
		while (ft_is_sep(s[i + skip], c) && s[i])
			skip++;
		if (!ft_is_sep(s[i + skip], c) && s[i])
		{
			while (!ft_is_sep(s[i + skip], c) && s[i + skip])
			{
				tab[j][a] = s[i + skip];
				i++;
				a++;
			}
			tab[j][a] = '\0';
		}
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		total_words;

	if (s == NULL)
		return (NULL);
	total_words = ft_count_words((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!tab)
		return (NULL);
	tab[total_words] = NULL;
	ft_alocate(tab, (char *)s, c, total_words);
	ft_fill_split(tab, (char *)s, c);
	return (tab);
}
