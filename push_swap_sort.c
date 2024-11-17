/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:37:53 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 13:14:07 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stack **st_a)
{
	int		size;

	size = ft_lstsize(*st_a);
	if (size <= 3)
		small_size_sort(size, st_a);
	else if (size <= 10)
		middle_size_sort(size, st_a);
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

void	middle_size_sort(int size, t_stack **st_a)
{
	t_stack	*st_b;
	int		i;

	i = 1;
	st_b = NULL;
	while (size > 3 && !is_order(*st_a))
	{
		prepare_push(st_a, &st_b, i, 'a');
		exec_and_print("p", 'b', st_a, &st_b);
		size--;
		i++;
	}
	if (size == 3 && !is_order(*st_a))
		small_size_sort(size, st_a);
	while (st_b != NULL)
		exec_and_print("p", 'a', st_a, &st_b);
}

void	big_size_sort(int size, t_stack **st_a)
{
	t_stack	*st_b;

	st_b = NULL;
	st_b = *move_to_b(size, st_a, &st_b);
	back_to_a(size, st_a, &st_b);
}
