/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:52:24 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/15 13:29:15 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void bubble(t_stacks *s)
{
	while (!inOrder(&s->a) || s->a.size)
	{
		if (s->b.size > 1)
		{
			while (s->b.array[0] > s->a.array[0])
			{
				push_a(s);
				rotate_a(s);
			}
		}
		push_b(s);
	}
	while (s->b.size)
		push_a(s);
}
