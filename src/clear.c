/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:50:15 by glima-de          #+#    #+#             */
/*   Updated: 2022/02/10 17:50:25 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_stack(t_stack *s)
{
	if (s->array)
		free(s->array);
}

void	clear_matrix(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	clear(t_stacks *s)
{
	clear_stack(&s->a);
	clear_stack(&s->b);
}
