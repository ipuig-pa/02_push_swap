/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/07 12:24:27 by ipuig-pa         ###   ########.fr       */
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
	free(arr);
	if (!stack_a)
		return (display_error());
	stack_b = NULL;
	sort_stack_a(&stack_a, &stack_b);
	current = stack_a;
	//checker
	if (stack_b == NULL)
	{
		current = stack_a;
		while (current->next != NULL)
		{
			if (current->content > current->next->content)
				printf("KO\n");
			current = current->next;
		}
		printf("OK\n");
	}
	//visual checking
	current = stack_a;
	while (current != NULL)
	{
		printf("%i\n", current->content);
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

void	sort_stack_a(t_stack **st_a, t_stack **st_b)
{
	t_stack	*current;
	t_stack	*bottom;
	int		size;
	int		node_pos;
	int		flag;

	if (!st_a || !*st_a || !(*st_a)->next)
		return ;
	current = *st_a;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
		{
			bottom = ft_lstlast(*st_a);
			size = ft_lstsize(*st_a);
			node_pos = ft_lstpos(*st_a, current);
			current = current->next;
			if (size == 2)
				exec_and_print("jokera", st_a, st_b);
			if ((*st_a)->content > bottom->content)
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
				if ((*st_b != NULL && (*st_a)->content < (*st_b)->content))
					flag = 1;
				while (node_pos > 1)
				{
					exec_and_print("pb", st_a, st_b);
					if (flag == 1)
						sort_stack_b(st_a, st_b);
					node_pos--;
				}
				exec_and_print("sa", st_a, st_b);
				current = current->next;
			}
		}
		else
			current = current->next;
	}
	while (*st_b != NULL)
	{
		exec_and_print("pa", st_a, st_b);
		sort_stack_a(st_a, st_b);
	}
}

void	sort_stack_b(t_stack **st_a, t_stack **st_b)
{
	t_stack	*bottom;
	int		size;

	if (!st_b || !*st_b || !(*st_b)->next)
		return ;
	bottom = ft_lstlast(*st_b);
	size = ft_lstsize(*st_b);
	if (size == 2)
		exec_and_print("jokerb", st_a, st_b);
	else if ((*st_b)->content < bottom->content)
		exec_and_print("rb", st_a, st_b);
	else if ((*st_b)->content < (*st_b)->next->content)
		exec_and_print("sb", st_a, st_b);
	else
		printf("Creia que no es donaria aquesta condicio\n");
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
	else
		return ;
	if (command_len >= 3)
		reverse_rotate(stack);
	else if (command[0] == 'r')
		rotate(stack);
	else if (command[0] == 'p')
	{
		if (stack_id == 'a')
			push(stack, st_b);
		else
			push(stack, st_a);
	}
	else if (command[0] == 's')
		swap(stack);
	write (1, command, command_len);
	write (1, "\n", 1);
	//falta la part de printar(que ajunti sa i sb, ra i rb, etc. i fer servir ft_printf en lloc de printf)
}
