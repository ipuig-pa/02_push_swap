/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_creation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:40:30 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 15:37:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input_to_arr(int count, char **argv, int *arr, int flag)
{
	int	i;
	int	j;

	i = 0;
	if (count == 1)
		return (0);
	while (i + 1 < count)
	{
		if (!is_int(argv[i + 1 - flag]))
			return (0);
		arr[i] = ft_atoi(argv[i + 1 - flag]);
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*parse_in_stack(int argc, int *arr)
{
	t_stack	*stack_a;
	t_stack	*current;
	t_stack	*new;
	int		i;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->content = arr[0];
	stack_a->index = 0;
	i = 1;
	current = stack_a;
	while (i + 1 < argc)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (clear_stack(stack_a));
		new->content = arr[i];
		new->index = 0;
		current->next = new;
		current = new;
		i++;
	}
	current->next = NULL;
	return (assign_index(stack_a));
}

t_stack	*assign_index(t_stack *stack)
{
	int		i;
	t_stack	*current;
	t_stack	*min;
	int		min_val;

	i = 1;
	while (i <= ft_lstsize(stack))
	{
		current = stack;
		while (current->index > 0)
			current = current->next;
		min_val = current->content;
		min = current;
		current = stack;
		while (current != NULL)
		{
			if (current->content < min_val && current->index == 0)
				min = current;
			min_val = min->content;
			current = current->next;
		}
		min->index = i;
		i++;
	}
	return (stack);
}
