/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:50:15 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 20:59:31 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_stack(t_stack *s)
{
	if (s->array)
		free(s->array);
}

void	clear(t_stacks *s)
{
	clear_stack(&s->a);
	clear_stack(&s->b);
}
