/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:56:32 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/30 11:33:43 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, char *error)
{
	int	i;
	int	res;
	int	negativ;

	i = 0;
	res = 0;
	negativ = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-')
	{
		negativ = negativ * -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		if (test_sizeint((unsigned)res * 10 + (str[i] - 48), negativ))
			error[0] = 'y';
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (res * negativ);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (!s1)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = -1;
	j = -1;
	new = malloc(len * sizeof(char) + 1);
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		new[i] = s1[i];
	new[i] = ' ';
	while (s2[++j])
		new[i + 1 + j] = s2[j];
	free(s1);
	new[i + j + 1] = '\0';
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	only_int(char *str)
{
	int	tester;
	int	i;

	i = 1;
	tester = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && (str[i] < 9 || str[i] > 13) && \
			str[i] != '-' && (str[i] < 48 || str[i] > 57)) || \
			(str[i] == '-' && (str[i - 1] >= 48 && str[i - 1] <= 57)))
			tester = 1;
		i++;
	}
	return (tester);
}
