/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 16:37:22 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	push(int *stack_destination, int *stack_source, int d_size, int s_size)
{
	if (d_size != 0)
		push_index(stack_destination, '+', d_size + 1);
	stack_destination[0] = stack_source[0];
	if (s_size - 1 != 0)
		push_index(stack_source, '-', s_size);
}

void	rotate(int *stack, int size)
{
	int	temp;

	temp = stack[0];
	push_index(stack, '-', size);
	stack[size - 1] = temp;
}

void	reverse_rotate(int *stack, int size)
{
	int	temp;

	temp = stack[size - 1];
	push_index(stack, '+', size);
	stack[0] = temp;
}

void	push_index(int *stack, char c, int size)
{
	int	previous;
	int	following;
	int	i;

	i = 0;
	if (c == '+')
	{
		previous = stack[i];
		while (i < size - 1)
		{
			following = stack[i + 1];
			stack[i + 1] = previous;
			previous = following;
			i++;
		}
	}
	else
	{
		while (i < size - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
	}
}
