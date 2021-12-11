/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:19:42 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/11 13:35:24 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_b(t_stacks *s)
{
	ft_putstr_fd("sb\n", 1);
	swap(&s->b);
}

void push_b(t_stacks *s)
{
	ft_putstr_fd("pb\n", 1);
	push(&s->a, &s->b);
}