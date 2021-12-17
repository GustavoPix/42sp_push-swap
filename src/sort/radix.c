/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:48:35 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 22:01:38 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	normalize(t_stack *s)
{
	size_t	i;
	int		minnor;

	i = 0;
	minnor = 0;
	while (i < s->size)
	{
		if (s->array[i] < minnor)
			minnor = s->array[i];
		i++;
	}
	i = 0;
	minnor *= -1;
	while (i < s->size)
	{
		s->array[i] += minnor;
		i++;
	}
}

void	radix_sort(t_stacks *s, int size)
{
	int	i;
	int	ib;

	ib = 0;
	normalize(&s->a);
	while (!in_order(&s->a) || s->b.size)
	{
		i = 0;
		while (i < size)
		{
			if (((s->a.array[0] >> ib) & 1))
				rotate_a(s);
			else
				push_b(s);
			i++;
		}
		while (s->b.size)
			push_a(s);
		ib++;
	}
}
