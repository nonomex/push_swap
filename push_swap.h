/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:12:51 by aammirat          #+#    #+#             */
/*   Updated: 2023/08/24 20:43:52 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(char *str, char *error);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		only_int(char *str);
int		*split(char *pipe_a, char c, char *error);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strcpy(char *s);
int		test_doble(int *pipe);
int		test_sizeint(unsigned int c, int negativ);
int		is_sort(int *pipe_a);
void	sortpipe(int *pipe_a, int *pipe_b);
void	sort_tree(int *pipe_a);
void	sort_five(int *pipe_a, int *pipe_b);
void	sortfive_step(int *pipe_a, int *pipe_b);
void	swap(int *pipe, char c);
void	rotate(int *rota, char c);
void	push(int *from, int *to, int pipe);
void	sortfoor(int *pipe_a, int *pipe_b);
int		puiss(int a, int b);
int		changepipe(int *pipe_a);

#endif
