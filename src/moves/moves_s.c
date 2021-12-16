/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:25:21 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/15 21:46:28 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void swap_s(t_stacks *s)
{
	ft_putstr_fd("ss\n", 1);
	swap(&s->a);
	swap(&s->b);
}

void rotate_r(t_stacks *s)
{
	ft_putstr_fd("rr\n", 1);
	rotate(&s->a);
	rotate(&s->b);
}

void rev_rotate_r(t_stacks *s)
{
	ft_putstr_fd("rrr\n", 1);
	rev_rotate(&s->a);
	rev_rotate(&s->b);
}
