/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:40:55 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 21:27:38 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	prepare(t_stacks *s)
{
	while (s->a.size > 1)
		push_b(s);
}

static size_t	first_part(t_stacks *s, size_t ia)
{
	if (ia > 0)
	{
		if (s->b.array[0] < s->a.array[s->a.size - 1])
		{
			rev_rotate_a(s);
			ia--;
		}
		else
			push_a(s);
	}
	else
		push_a(s);
	return (ia);
}

static size_t	second_part(t_stacks *s, size_t ia)
{
	if (ia < s->a.size - 1)
	{
		if (s->b.array[0] > s->a.array[1])
		{
			rotate_a(s);
			ia++;
		}
		else
		{
			push_a(s);
			swap_a(s);
		}
	}
	else
	{
		push_a(s);
		swap_a(s);
	}
	return (ia);
}

static size_t	sort(t_stacks *s)
{
	size_t	ia;

	ia = 0;
	while (s->b.size)
	{
		if (s->b.array[0] < s->a.array[0])
			ia = first_part(s, ia);
		else
			ia = second_part(s, ia);
	}
	return (ia);
}

void	insert(t_stacks *s)
{
	size_t	ia;

	prepare(s);
	ia = sort(s);
	if (ia > s->a.size / 2)
	{
		while (!in_order(&s->a))
			rotate_a(s);
	}
	else
	{
		while (!in_order(&s->a))
			rev_rotate_a(s);
	}
}
