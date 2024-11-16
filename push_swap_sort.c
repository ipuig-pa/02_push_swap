/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:37:53 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/16 13:58:24 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
