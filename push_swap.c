/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/06 12:55:35 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//eliminar stdio.h, canviar printf per ft_printf

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*current;
	int		*arr;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !is_valid_input(argc, argv, arr))
	{
		if (arr)
			free(arr);
		return (display_error());
	}
	stack_a = parse_in_stack(argc, arr);
	stack_b = NULL;
	free(arr);
	if (!stack_a)
		return (display_error());
	sort_stack_a(&stack_a, &stack_a, &stack_b);
	current = stack_a;
	while (current != NULL)
	{
		printf("%i/n", current->content);
		current = current->next;
	}
	clear_stack(stack_a);
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
	while (i + 1 < argc)
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

void	sort_stack_a(t_stack **stack_top, t_stack **st_a, t_stack **st_b)
{
	t_stack	*current;
	t_stack	*bottom;
	int		size;
	int		node_pos;
	int		flag;

	current = *stack_top;
	if (current->content > current->next->content)
	{
		bottom = ft_lstlast(*stack_top);
		size = ft_lstsize(*stack_top);
		node_pos = ft_lstpos(*stack_top, current);
		if ((*stack_top)->content > bottom->content)
		{
			//Agrupar en una funcio rotate que valori internament si hem de fer normal o reverse rotate
			if (node_pos < size / 2)
			{
				while (node_pos >= 1)
				{
					exec_and_print("ra", st_a, st_b);
					node_pos--;
				}
			}
			else
			{
				while (node_pos < size)
				{
					exec_and_print("rra", st_a, st_b);
					node_pos++;
				}
			}
		}
		else
		{
			flag = 0;
			if (*st_b != NULL && (*stack_top)->content > (*st_b)->content)
				flag = 1;
			while (node_pos > 1)
			{
				exec_and_print("pb", st_a, st_b);
				if (flag == 1)
					sort_stack_b(st_b, st_a, st_b);
				node_pos--;
			}
			exec_and_print("sa", st_a, st_b);
		}
	}
	if (current->next != NULL)
		sort_stack_a(st_a, st_a, st_b);
	else
	{
		while (st_b != NULL)
			exec_and_print("pa", st_a, st_b);
	}
}

void	sort_stack_b(t_stack **stack_top, t_stack **st_a, t_stack **st_b)
{
	t_stack	*bottom;
	int		size;

	if ((*stack_top)->content > (*stack_top)->next->content)
		return ;
	bottom = ft_lstlast(*stack_top);
	size = ft_lstsize(*stack_top);
	if (size == 2)
		exec_and_print("jokerb", st_a, st_b);
	if ((*stack_top)->content < bottom->content)
		exec_and_print("rb", st_a, st_b);
	else if ((*stack_top)->content > (*stack_top)->next->content)
		exec_and_print("sb", st_a, st_b);
	else
		printf("Creia que no es donaria aquesta condicio");
}

// void print(void)
// {
// 	read ();
// 	cada 2 ordres mirar si pot agrupar-les
// }

void	exec_and_print(char *command, t_stack **st_a, t_stack **st_b)
{
	char	stack_id;
	t_stack	**stack;
	int		command_len;

	command_len = ft_strlen(command);
	stack_id = command[command_len - 1];
	if (stack_id == 'a')
		stack = st_a;
	else if (stack_id == 'b')
		stack = st_b;
	if (command_len >= 3)
		reverse_rotate(stack);
	else if (command[0] == 'r')
		rotate(stack);
	else if (command[0] == 'p')
	{
		if (stack == st_a)
			push(stack, st_b);
		else
			push(stack, st_a);
	}
	else if (command[0] == 's')
		swap(stack);
	write (1, command, command_len);
	//falta la part de printars
}
