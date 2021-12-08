/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:21:48 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/08 20:47:10 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_value(int a)
{
	if (a)
		ft_putnbr_fd(a, 1);
	else
		ft_putchar_fd('-', 1);
}

void print_stacks(t_stack *a, t_stack *b)
{
	size_t i;

	i = 0;
	ft_putstr_fd("a    b\n", 1);
	ft_putstr_fd("=    =\n", 1);
	while (i < a->size)
	{

		print_value(a->array[i]);
		ft_putstr_fd("    ", 1);
		print_value(b->array[i]);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("======\n", 1);
}
