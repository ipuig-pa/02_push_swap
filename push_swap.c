/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:44 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//eliminar stdio.h, canviar printf per ft_printf


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || argc <= 2 || !is_valid_input(argc, argv, arr))
		return (display_error());
	printf("first check");
	stack_a = parse_in_stack(argc, arr);
	free(arr);
	if (!stack_a)
		return (display_error());
	while (stack_a != NULL)
	{
		printf("%i, ", stack_a->content);
		stack_a = stack_a->next;
	}
	//get_instructions(stack_a, argc - 1, 0, 0);
	return (0);
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
	i = 1;
	current = stack_a;
	while (i < argc - 2)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (clear_stack(stack_a));
		new->content = arr[i];
		current->next = new;
		current = new;
		i++;
	}
	current->next = NULL;
	return (stack_a);
}

// void	get_instructions(int *arr_a, int a_length, int curr_a, int b_length)
// {
// 	int	i;
// 	int	first_a;
// 	int	last_a;

// 	i = 0;
// 	fist_a = 0;
// 	last_a = length - 1;
// 	if (arr_a[curr_a] > arr_a[curr_a + 1])
// 	{
// 		if (arr_a[first_a] > arr_a[last_a])
// 		{
// 			if (curr_a + 1 > length / 2)
// 			{
// 				while (i <= curr_a)
// 				{
// 					ra;
// 					d-alguna manera ha de quedar registrat que l-ultim de l-array ara es diferent
// 					i++;
// 				}
// 			}
// 			else
// 			{
// 				while (i <= curr_a)
// 				{
// 					rra;
// 					d-alguna manera ha de quedar registrat que l-ultim de l-array ara es diferent
// 					i++;
// 				}
// 			}
// 		}
// 		else
// 		{
// 			//mirar si es mes alt que el del pilo B i si cal correr el pilo B, cap amunt o cap avall
// 			if (curr_a)
// 			while (i < curr_a)
// 			{
// 				pb;
// 				b_length++;
// 				i++;
// 			}
// 			sa;
// 		}
// 	}
// 	if (curr_a < length - 1)
// 		get_instructions(arr_a, length, curr_a + 1, b_length);
// 	else
// 	{
// 		while (b_length > 0)
// 		{
// 			pa;
// 			i++;
// 		}
// 	}
// }

// void	swap(char	stack)
// {
// 	if (stack == 'a' || stack == 's')

// 	if (stack == 'b' || stack == 's')

// }

// void	push(char	stack)
// {
// 	if (stack == 'a')

// 	else if (stack == 'b')
// }
// void	rotate(char	stack)
// {
// 	if (stack == 'a' || stack == 'r')

// 	if (stack == 'b' || stack == 'r')

// }

// void	reverse_rotate(char	stack)
// {
// 	if (stack == 'a' || stack == 'r')

// 	if (stack == 'b' || stack == 'r')

// }