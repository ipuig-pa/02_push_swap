/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/16 13:04:16 by ipuig-pa         ###   ########.fr       */
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

// void	print_command(char *command, char stack_id)
// {
// 	char	previous_command[4];
// 	int		joined_commands;
// 	int		prevcomm_len;

// 	prevcomm_len = read(1, previous_command, 4);
// 	previous_command[prevcomm_len] = '\0';
// 	joined_commands = 0;
// 	if (previous_command[0] == command[0])
// 	{
// 		if (stack_id != previous_command[prevcomm_len - 1])
// 		{
// 			joined_commands = 1;
// 			if (previous_command[0] == 's')
// 				stack_id = 's';
// 			else if (previous_command[0] == 'r')
// 				stack_id = 'r';
// 		}
// 	}
// 	if (joined_commands == 0)
// 		write (1, "\n", 1);
// 	write (1, command, ft_strlen(command));
// 	write (1, &stack_id, 1);
// 	if (joined_commands == 1)
// 		write (1, "\n", 1);
// }
