/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:03:23 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/08 20:33:10 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int *array;
	size_t size;
}	t_stack;

/*=============*/
/*  debug      */
/*=============*/
void print_stacks(t_stack *a, t_stack *b);

/*=============*/
/*  clear      */
/*=============*/
void clear(t_stack *a, t_stack *b);

#endif
