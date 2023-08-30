/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:55:01 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/30 11:33:20 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_doble(int *pipe)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	j = 1;
	while (j <= pipe[0])
	{
		i = 1;
		while (i <= pipe[0])
		{
			if (pipe[i] == pipe[j] && i != j)
				res = 1;
			i++;
		}
		j++;
	}
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
		return (NULL);
	if (len < ft_strlen(s) - start)
		str = malloc(len * sizeof(char) + 1);
	else
		str = malloc(ft_strlen(s) - start * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *s)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	test_sizeint(unsigned int c, int negativ)
{
	if (negativ < 0 && c > 2147483648)
		return (1);
	if (negativ > 0 && c > 2147483647)
		return (1);
	return (0);
}

int	is_sort(int *pipe_a)
{
	int	i;

	i = 2;
	if (pipe_a[0] == 1)
		return (1);
	while (i <= pipe_a[0])
	{
		if (pipe_a[i] < pipe_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}
