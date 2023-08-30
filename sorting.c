/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:25:22 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/24 17:57:46 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *from, int *to, int pipe)
{
	int	i;

	i = to[0] + 1;
	while (i > 1)
	{
		to[i] = to[i - 1];
		i--;
	}
	to[1] = from[1];
	to[0]++;
	i = 1;
	while (i < from[0])
	{
		from[i] = from[i + 1];
		i++;
	}
	from[0]--;
	if (pipe == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rotate(int *rota, char c)
{
	int	buff;
	int	i;

	buff = rota[1];
	i = 1;
	while (i < rota[0])
	{
		rota[i] = rota[i + 1];
		i++;
	}
	rota[rota[0]] = buff;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	swap(int *pipe, char c)
{
	int	buff;

	buff = pipe[1];
	pipe[1] = pipe[2];
	pipe[2] = pipe[1];
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	sort_tree(int *pipe_a)
{
	if (pipe_a[1] > pipe_a[2] && pipe_a[3] > pipe_a[1])
		swap(pipe_a, 'a');
	else if (pipe_a[1] > pipe_a[3] && pipe_a[3] > pipe_a[2])
		rotate(pipe_a, 'a');
	else if (pipe_a[1] < pipe_a[2] && pipe_a[1] < pipe_a[3])
	{
		swap(pipe_a, 'a');
		rotate(pipe_a, 'a');
	}
	else if (pipe_a[1] > pipe_a[2] && pipe_a[2] > pipe_a[3])
	{
		rotate(pipe_a, 'a');
		swap(pipe_a, 'a');
	}
	else if (pipe_a[1] < pipe_a[2] && pipe_a[2] > pipe_a[3])
	{
		rotate(pipe_a, 'a');
		rotate(pipe_a, 'a');
	}
}

void	sort_five(int *pipe_a, int *pipe_b)
{
	int	small[2];
	int	i;

	i = 0;
	small[0] = pipe_a[1];
	small[1] = pipe_a[2];
	while (++i <= pipe_a[0])
		if (pipe_a[i] < small[0])
			small[0] = pipe_a[i];
	i = 0;
	while (++i <= pipe_a[0])
		if (pipe_a[i] < small[1] && pipe_a[i] != small[0])
			small[1] = pipe_a[i];
	while (pipe_a[0] != 3)
	{
		if (pipe_a[1] == small[0] || pipe_a[1] == small[1])
			push(pipe_a, pipe_b, 0);
		else
			rotate(pipe_a, 'a');
	}
	sortfive_step(pipe_a, pipe_b);
}
