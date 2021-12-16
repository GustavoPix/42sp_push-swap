/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:03:23 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 19:05:40 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define MIN -2147483648
#  define MAX 2147483647
# endif

typedef struct s_stack
{
	int *array;
	size_t size;
} t_stack;

typedef struct s_stacks
{
	t_stack a;
	t_stack b;
} t_stacks;

/*=============*/
/*  main       */
/*=============*/
int inOrder(t_stack *s);
int rev_inOrder(t_stack *s);
int outOrder(t_stack *s);
int rev_outOrder(t_stack *s);

/*=============*/
/*  debug      */
/*=============*/
void print_stacks(t_stacks *s);

/*=============*/
/*  clear      */
/*=============*/
void clear(t_stacks *s);

/*=============*/
/*  moves      */
/*=============*/
void swap(t_stack *s);
void push(t_stack *ori, t_stack *dest);
void rotate(t_stack *s);
void rev_rotate(t_stack *s);

/*=============*/
/*  moves_a    */
/*=============*/
void swap_a(t_stacks *s);
void push_a(t_stacks *s);
void rotate_a(t_stacks *s);
void rev_rotate_a(t_stacks *s);

/*=============*/
/*  moves_b    */
/*=============*/
void swap_b(t_stacks *s);
void push_b(t_stacks *s);
void rotate_b(t_stacks *s);
void rev_rotate_b(t_stacks *s);

/*=============*/
/*  moves_s    */
/*=============*/
void swap_s(t_stacks *s);
void rotate_r(t_stacks *s);
void rev_rotate_r(t_stacks *s);

/*=============*/
/*  radix      */
/*=============*/
void radix_sort(t_stacks *s, int size);
int radix_sort2(t_stacks *s, int size);

/*=============*/
/*  custom     */
/*=============*/
void custom_order(t_stacks *s);

/*=============*/
/*  insert     */
/*=============*/
void insert(t_stacks *s);

/*=============*/
/*  bubble     */
/*=============*/
void bubble(t_stacks *s);

/*=============*/
/*  valid_num  */
/*=============*/
int is_valid_numbers(char **strs, int size);
int duplicate_number(t_stack *s);
int min_valid_value(t_stack *s, char **str);

/*=============*/
/*  checker    */
/*=============*/
int checker(int argc, char **argv, t_stacks *s);

#endif
