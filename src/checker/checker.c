/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:28:35 by glima-de          #+#    #+#             */
/*   Updated: 2022/02/13 16:48:23 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	checker(int argc, char **argv, t_stacks *s)
{
	int	r;

	r = 1;
	if (!is_valid_numbers(argv, argc))
		r = 0;
	else if (duplicate_number(&s->a))
		r = 0;
	else if (!overflow_int(&s->a, argv))
		r = 0;
	if (r == 0)
		ft_putstr_fd("Error\n", 1);
	return (r);
}

int	check_order_stacks(t_stacks *s)
{
	if (in_reverse_order(&s->b) && in_order(&s->a))
		if (s->b.array[0] < s->a.array[0])
			return (1);
	return (0);
}
