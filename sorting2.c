/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:43:15 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/24 20:39:01 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortfive_step(int *pipe_a, int *pipe_b)
{
	sort_tree(pipe_a);
	if (pipe_b[1] < pipe_b[2])
		swap(pipe_b, 'b');
	push(pipe_b, pipe_a, 1);
	push(pipe_b, pipe_a, 1);
}

void	sortpipe(int *pipe_a, int *pipe_b)
{
	int	maxbin;
	int	i;
	int	j;
	int	size;

	i = 0;
	maxbin = 0;
	size = pipe_a[0];
	while (size >> maxbin != 0)
		maxbin++;
	while (i < maxbin)
	{
		j = 0;
		while (j < size)
		{
			if (((pipe_a[1] >> i) & 1) == 1)
				rotate(pipe_a, 'a');
			else
				push(pipe_a, pipe_b, 0);
			j++;
		}
		while (pipe_b[0] != 0)
			push(pipe_b, pipe_a, 1);
		i++;
	}
}

void	sortfoor(int *pipe_a, int *pipe_b)
{
	int	small;
	int	i;

	i = 0;
	small = pipe_a[1];
	while (++i <= pipe_a[0])
		if (pipe_a[i] < small)
			small = pipe_a[i];
	while (pipe_a[0] != 3)
	{
		if (pipe_a[1] == small)
			push(pipe_a, pipe_b, 0);
		else
			rotate(pipe_a, 'a');
	}
	sort_tree(pipe_a);
	push(pipe_b, pipe_a, 1);
}
