/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:28:36 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/30 11:21:32 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	puiss(int a, int b)
{
	int	i;

	i = 1;
	while (i < b)
	{
		a = a * 2;
		i++;
	}
	return (a);
}

void	quicksort(int *tab, int size)
{
	int	i;
	int	j;
	int	buff;

	i = size - 1;
	while (i >= 1)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j + 1] < tab[j])
			{
				buff = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = buff;
			}
			j++;
		}
		i--;
	}
}

int	changepipe(int *pipe_a)
{
	int	*tab;
	int	i;
	int	j;

	i = -1;
	tab = malloc (pipe_a[0] * sizeof(int));
	if (!tab)
		return (1);
	while (++i < pipe_a[0])
		tab[i] = pipe_a[i + 1];
	quicksort(tab, pipe_a[0]);
	i = 1;
	while (i <= pipe_a[0])
	{
		j = 1;
		while (pipe_a[j] != tab[i - 1])
			j++;
		pipe_a[j] = i;
		i++;
	}
	free(tab);
	return (0);
}
