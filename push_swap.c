/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/16 13:37:59 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;
	int		flag;
	// t_stack	*current;

	flag = 0;
	if (argc == 2)
	{
		flag = 1;
		argv = ft_split(argv[1], ' ');
		argc = arrlen(argv);
	}
	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !valid_input_to_arr(argc, argv, arr))
		return (handle_error(flag, argv, arr));
	if (!is_arr_order(arr, argc - 1))
	{
		stack_a = parse_in_stack(argc, arr);
		if (!stack_a)
			return (display_error());
		sort_stack_a(&stack_a);
		// current = stack_a;
		// while (current->next != NULL)
		// {
		// 	if (current->content > current->next->content)
		// 		printf("KO\n");
		// 	current = current->next;
		// }
		// printf("OK\n");
		// //visual checking
		// current = stack_a;
		// while (current != NULL)
		// {
		// 	printf("%i: %i\n", current->index, current->content);
		// 	current = current->next;
		// }
		clear_stack(stack_a);
	}
	if (flag == 1)
		free(argv);
	return (free(arr), 0);
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

void	sort_stack_a(t_stack **st_a)
{
	int		size;

	size = ft_lstsize(*st_a);
	if (size <= 3)
		small_size_sort(size, st_a);
	else
		big_size_sort(size, st_a);
	exec_and_print("last", 'a', st_a, NULL);
}

void	small_size_sort(int size, t_stack **st_a)
{
	t_stack	**st_b;

	st_b = NULL;
	if (size == 2)
		exec_and_print("s", 'a', st_a, st_b);
	else
	{
		if ((*st_a)->content > (*st_a)->next->content)
		{
			if ((*st_a)->next->content > (*st_a)->next->next->content)
			{
				exec_and_print("s", 'a', st_a, st_b);
				exec_and_print("rr", 'a', st_a, st_b);
			}
			else if ((*st_a)->content > (*st_a)->next->next->content)
				exec_and_print("r", 'a', st_a, st_b);
			else
				exec_and_print("s", 'a', st_a, st_b);
		}
		else
			exec_and_print("rr", 'a', st_a, st_b);
		if ((*st_a)->content > (*st_a)->next->content)
			exec_and_print("s", 'a', st_a, st_b);
	}
}

void	big_size_sort(int size, t_stack **st_a)
{
	t_stack	*st_b;

	st_b = NULL;
	st_b = *move_to_b(size, st_a, &st_b);
	back_to_a(size, st_a, &st_b);
}

t_stack	**move_to_b(int size, t_stack **st_a, t_stack **st_b)
{
	int		range;
	int		i;

	range = ft_sqrt(size) * 14 / 10;
	i = 1;
	while (*st_a != NULL)
	{
		if ((*st_a)->index <= i)
		{
			exec_and_print("p", 'b', st_a, st_b);
			if ((*st_b)->next != NULL)
				exec_and_print("r", 'b', st_a, st_b);
			i++;
		}
		else if ((*st_a)->index <= (i + range))
		{
			exec_and_print("p", 'b', st_a, st_b);
			i++;
		}
		else
			exec_and_print("r", 'a', st_a, st_b);
	}
	return (st_b);
}

void	back_to_a(int size, t_stack **st_a, t_stack **st_b)
{
	t_stack	*current;
	int		node_pos;

	while (*st_b != NULL)
	{
		current = *st_b;
		while (current->index != size)
			current = current->next;
		node_pos = ft_lstpos(*st_b, current);
		if (node_pos != 1 && node_pos <= (size / 2))
		{
			while (node_pos-- > 1)
				exec_and_print("r", 'b', st_a, st_b);
		}
		else if (node_pos != 1)
		{
			while (node_pos++ <= size)
				exec_and_print("rr", 'b', st_a, st_b);
		}
		exec_and_print("p", 'a', st_a, st_b);
		size--;
	}
}

void	exec_and_print(char *comm, char st_id, t_stack **st_a, t_stack **st_b)
{
	t_stack		**stack;
	t_stack		**other_stack;
	static char	*prev_comm;
	static char	prev_id;

	if (comm[0] != 'l')
	{
		stack = st_a;
		other_stack = st_b;
		if (st_id == 'b')
		{
			stack = st_b;
			other_stack = st_a;
		}
		if (comm[0] == 's')
			swap(stack);
		else if (comm[0] == 'p')
			push(stack, other_stack);
		else if (comm[1] == '\0')
			rotate(stack);
		else
			reverse_rotate(stack);
	}
	prev_comm = print(prev_comm, comm, prev_id, st_id);
	prev_id = st_id;
}

char	*print(char *prev_comm, char *comm, char prev_id, char st_id)
{
	int	joined_commands;

	if (!prev_comm || prev_comm[0] == 'l')
		return (comm);
	joined_commands = 0;
	if (prev_comm == comm)
	{
		if (st_id != prev_id)
		{
			joined_commands = 1;
			prev_id = 's';
			if (prev_comm[0] == 'r')
				prev_id = 'r';
		}
	}
	write (1, prev_comm, ft_strlen(prev_comm));
	write (1, &prev_id, 1);
	write (1, "\n", 1);
	if (joined_commands == 1)
		prev_comm = NULL;
	else
		prev_comm = comm;
	return (prev_comm);
}
