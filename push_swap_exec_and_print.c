/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exec_and_print.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:45:47 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/19 16:36:31 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_push(t_stack **st_a, t_stack **st_b, int ind, char id)
{
	t_stack	*stack;
	t_stack	*current;
	int		node_pos;
	int		size;

	stack = *st_a;
	if (id == 'b')
		stack = *st_b;
	current = stack;
	size = ft_lstsize(stack);
	while (current->index != ind)
		current = current->next;
	node_pos = ft_lstpos(stack, current);
	if (node_pos != 1 && node_pos <= (size / 2))
	{
		while (node_pos-- > 1)
			exec_and_print("r", id, st_a, st_b);
	}
	else if (node_pos != 1)
	{
		while (node_pos++ <= size)
			exec_and_print("rr", id, st_a, st_b);
	}
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
	while (*st_b != NULL)
	{
		prepare_push(st_a, st_b, size, 'b');
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
	if (prev_comm == comm && comm[0] != 'p')
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
