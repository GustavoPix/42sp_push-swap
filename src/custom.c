/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:49:47 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/15 21:37:53 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void custom_order(t_stacks *s)
{
	int m;

	m = 0;
	while ((!inOrder(&s->a) || s->b.size))
	{
		if (s->a.array[1] < s->a.array[0])
			swap_a(s);
		else if (s->a.size > 1 && s->a.array[s->a.size - 1] < s->a.array[0])
			rev_rotate_a(s);
		else if (s->a.array[0] > s->a.array[s->a.size - 1])
			rotate_a(s);
		else if (!inOrder(&s->a))
			push_b(s);
		if (s->b.size > 1)
		{
			if (s->b.array[0] < s->b.array[s->b.size - 1])
				rotate_b(s);
			else if (s->b.array[0] < s->b.array[1])
				swap_b(s);
		}
		if (inOrder(&s->a) && s->b.size)
			push_a(s);
		m++;
	}
}
