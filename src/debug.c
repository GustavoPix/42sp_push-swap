/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:40:00 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 21:00:00 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_value(int a)
{
	if (a)
		ft_putnbr_fd(a, 1);
	else
		ft_putchar_fd('-', 1);
}

void	print_stacks(t_stacks *s)
{
	size_t	i;

	i = 0;
	ft_putstr_fd("a    b\n", 1);
	ft_putstr_fd("=    =\n", 1);
	while (i < s->a.size || i < s->b.size)
	{
		print_value(s->a.array[i]);
		ft_putstr_fd("    ", 1);
		print_value(s->b.array[i]);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("======\n", 1);
}
