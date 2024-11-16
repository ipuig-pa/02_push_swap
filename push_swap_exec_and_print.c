/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exec_and_print.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:45:47 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/16 13:58:22 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
