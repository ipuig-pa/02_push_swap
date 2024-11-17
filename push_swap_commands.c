/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 16:47:39 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_stack **stack_destination, t_stack **stack_source)
{
	t_stack	*temp;

	temp = *stack_source;
	*stack_source = (*stack_source)->next;
	temp->next = *stack_destination;
	*stack_destination = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	ft_lstlast(*stack)->next = temp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	temp = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	*stack = current->next;
	current->next = NULL;
	(*stack)->next = temp;
}
