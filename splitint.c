/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:01:46 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/30 11:34:08 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	worldnb(char *s, int index, char c)
{
	int	world;

	world = 0;
	while (s[index] && s[index] != c)
	{
		index++;
		world++;
	}
	return (world);
}

int	ft_splited(char *s, char *error, int *pipe, int nb)
{
	int		world;
	int		i;
	int		tab;
	char	*new;

	tab = 1;
	i = 0;
	while (tab <= nb)
	{
		if (s[i] != ' ')
		{
			world = worldnb(s, i, ' ');
			new = ft_substr(s, i, world);
			if (!new)
				return (0);
			pipe[tab] = ft_atoi(new, error);
			free (new);
			tab++;
			i += world;
		}
		i++;
	}
	return (1);
}

int	counttab(char *s, char c)
{
	int	i;
	int	nb;
	int	bol;

	bol = 1;
	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && bol == 1)
		{
			nb++;
			bol = 0;
		}
		if (s[i] == c)
			bol = 1;
		i++;
	}
	return (nb);
}

int	*split(char *pipe_a, char c, char *error)
{
	int	*pipe;
	int	numtab;
	int	i;

	i = 0;
	numtab = counttab(pipe_a, c);
	pipe = malloc((numtab + 1) * sizeof(int) + 1);
	if (!pipe)
		return (NULL);
	pipe[0] = numtab;
	if (ft_splited(pipe_a, error, pipe, numtab))
		return (pipe);
	else
	{
		free (pipe);
		return (NULL);
	}
}
