/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:01:19 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 22:10:32 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	count_negative(t_stack *s)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (i < s->size)
	{
		if (s->array[i] < 0)
			c++;
		i++;
	}
	return (c);
}

static int	put_b_negative(t_stacks *s)
{
	int	negative;

	negative = count_negative(&s->a);
	while (s->b.size < (size_t)negative)
	{
		if (s->a.array[0] < 0)
			push_b(s);
		else
			rotate_a(s);
	}
	return (negative);
}

static void	filter_sort(t_stacks *s, int size, int negative, int ib)
{
	int	i;

	i = 0;
	while (i < size - negative)
	{
		if (!((s->a.array[0] >> ib) & 1))
			push_b(s);
		else
			rotate_a(s);
		i++;
	}
}

static void	back_sort(t_stacks *s, int negative)
{
	while (s->b.size - negative > 0)
	{
		if (s->b.array[0] >= 0)
			push_a(s);
		else
			rotate_b(s);
	}
}

void	radix_sort2(t_stacks *s, int size)
{
	int	ib;
	int	negative;

	ib = 0;
	negative = put_b_negative(s);
	while ((!in_order(&s->a) || s->b.size - negative > 0))
	{
		filter_sort(s, size, negative, ib);
		back_sort(s, negative);
		ib++;
	}
	insert(s);
}
