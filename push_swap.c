/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:44:17 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/30 11:35:29 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_parsing(char *pipe_a)
{
	int		*pipe;
	char	error[1];

	error[0] = 'n'; 
	if (only_int(pipe_a))
	{
		free(pipe_a);
		write(2, "Error\n", 6);
		return (0);
	}
	pipe = split(pipe_a, ' ', error);
	free(pipe_a);
	if (!pipe)
		return (0);
	if (test_doble(pipe) || error[0] == 'y')
	{
		free(pipe);
		write(2, "Error\n", 6);
		return (0);
	}
	return (pipe);
}

void	sort(int *pipe_a)
{
	int	*pipe_b;

	pipe_b = malloc((pipe_a[0] + 1) * sizeof(int));
	if (pipe_b)
	{
		pipe_b[0] = 0;
		if (!is_sort(pipe_a) && !changepipe(pipe_a))
		{
			if (pipe_a[0] == 2)
				write(1, "sa\n", 3);
			else if (pipe_a[0] == 3)
				sort_tree(pipe_a);
			else if (pipe_a[0] == 4)
				sortfoor(pipe_a, pipe_b);
			else if (pipe_a[0] == 5)
				sort_five(pipe_a, pipe_b);
			else
				sortpipe(pipe_a, pipe_b);
		}
		free(pipe_b);
	}
}

int	main(int argc, char *argv[])
{
	char	*pipe_a;
	int		i;
	int		*pipe;

	if (argc >= 2)
	{
		pipe_a = ft_strcpy(argv[1]);
		if (!pipe_a)
			return (0);
		i = 2;
		while (argv[i])
		{
			pipe_a = ft_strjoin(pipe_a, argv[i]);
			if (!pipe_a)
				return (0);
			i++;
		}
		pipe = ft_parsing(pipe_a);
		if (pipe != 0)
		{
			sort(pipe);
			free (pipe);
		}
	}
	return (0);
}
