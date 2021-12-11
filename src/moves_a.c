/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:06:58 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/11 14:29:06 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_a(t_stacks *s)
{
	ft_putstr_fd("sa\n", 1);
	swap(&s->a);
}

void push_a(t_stacks *s)
{
	ft_putstr_fd("pa\n", 1);
	push(&s->b, &s->a);
}

void rotate_a(t_stacks *s)
{
	ft_putstr_fd("ra\n", 1);
	rotate(&s->a);
}

void rev_rotate_a(t_stacks *s)
{
	ft_putstr_fd("rra\n", 1);
	rev_rotate(&s->a);
}
