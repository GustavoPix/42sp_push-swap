/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:25:21 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/11 12:29:31 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_s(t_stacks *s)
{
	ft_putstr_fd("ss\n", 1);
	swap(&s->a);
	swap(&s->b);
}