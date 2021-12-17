/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:28:35 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 21:00:22 by glima-de         ###   ########.fr       */
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
