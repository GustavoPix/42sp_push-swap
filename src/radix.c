/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:48:35 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/15 21:09:12 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void normalize(t_stack *s)
{
	size_t i;
	int minnor;

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

void radix_sort(t_stacks *s, int size)
{
	int i;
	int ib;

	ib = 0;
	normalize(&s->a);
	while (!inOrder(&s->a) || s->b.size)
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

int count_negative(t_stack *s)
{
	size_t i;
	int c;

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

int minor_number(t_stack *s)
{
	size_t i;
	int v;

	i = 0;
	v = 0;
	while (i < s->size)
	{
		if (s->array[i] < v)
			v = s->array[i];
		i++;
	}
	return (v);
}

int radix_sort2(t_stacks *s, int size)
{
	int i;
	int ib;
	int negative;

	ib = 0;
	// normalize(&s->a);
	negative = count_negative(&s->a);
	while (s->b.size < (size_t)negative)
	{
		if (s->a.array[0] < 0)
			push_b(s);
		else
			rotate_a(s);
	}

	while ((!inOrder(&s->a) || s->b.size - negative > 0))
	{
		i = 0;
		while (i < size - negative)
		{
			if (!((s->a.array[0] >> ib) & 1))
				push_b(s);
			else
				rotate_a(s);
			i++;
		}
		while (s->b.size - negative > 0)
		{
			if (s->b.array[0] >= 0)
				push_a(s);
			else
				rotate_b(s);
		}
		ib++;
	}
	// while (s->b.size)
	//	push_a(s);
	insert(s);

	return (0);
}
