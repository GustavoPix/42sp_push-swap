/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:50:15 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/08 20:12:24 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void clear_stack(t_stack *s)
{
	if(s->array)
		free(s->array);
}

void clear(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
}
