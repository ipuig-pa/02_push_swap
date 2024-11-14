/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/14 17:18:37 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//eliminar stdio.h, canviar printf per ft_printf

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_stack	*current;
	int		*arr;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !is_valid_input(argc, argv, arr))
	{
		if (arr)
			free(arr);
		return (display_error());
	}
	stack_a = NULL;
	if (!is_arr_order(arr, argc - 1))
	{
		stack_a = parse_in_stack(argc, arr);
		free(arr);
		if (!stack_a)
			return (display_error());
		assign_index(stack_a);
		stack_b = NULL;
		sort_stack_a(&stack_a, &stack_b);
		//com fer que printi l'ultima de manera m'es elegant que aix[o que repeteix exec_and_print 2 vegades en va.] potser fer des d-aquesta funcio la variable estatica de previous_command?
		exec_and_print("last", 'b', &stack_a, &stack_b);
	}
	else
		free(arr);
	//checker
	// if (stack_a)
	// {
	// 	current = stack_a;
	// 	if (stack_b == NULL)
	// 	{
	// 		current = stack_a;
	// 		while (current->next != NULL)
	// 		{
	// 			if (current->content > current->next->content)
	// 				printf("KO\n");
	// 			current = current->next;
	// 		}
	// 		printf("OK\n");
	// 	}
	// 	//visual checking
	// 	current = stack_a;
	// 	while (current != NULL)
	// 	{
	// 		printf("%i\n", current->content);
	// 		//printf("ind: %i\n", current->index);
	// 		current = current->next;
	// 	}
	// 	clear_stack(stack_a);
	// }
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
	return (stack_a);
}

void	assign_index(t_stack *stack)
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
}

void	sort_stack_a(t_stack **st_a, t_stack **st_b)
{
	int		size;
	int		range;
	t_stack	*current;
	int		node_pos;
	int		flag;
	int		flag2;

	size = ft_lstsize(*st_a);
	if (size == 2)
	{
		exec_and_print("joker", 'a', st_a, st_b);
		return ;
	}
	else if (size == 3)
	{
	 	current = *st_a;
		if (current->content > current->next->content)
		{
			if (current->next->content > current->next->next->content)
			{
				exec_and_print("s", 'a', st_a, st_b);
				exec_and_print("rr", 'a', st_a, st_b);
			}
			else if (current->index == 3)
				exec_and_print("r", 'a', st_a, st_b);
			else
				exec_and_print("s", 'a', st_a, st_b);
		}
		else 
			exec_and_print("rr", 'a', st_a, st_b);
		if (current->index == 3)
		{
			exec_and_print("s", 'a', st_a, st_b);
			exec_and_print("rr", 'a', st_a, st_b);
		}
		return ;
	}
	else
	{
		range = size / 10;
		//printf("range: %i\n", range);
		while (ft_lstsize(*st_a) > 3 && !is_order(*st_a))
		{
			//printf("size: %i\n", ft_lstsize(*st_a));
			current = *st_a;
			//printf("index:%i\n", current->index);
			//printf("comparing:%i\n", ((size / 2) - range));
			if (current->index >= ((size / 2) - range) && current->index <= ((size / 2) + range))
			{
				flag = 0;
				if (*st_b != NULL && current->index < (size / 2))
					flag = 1;
				exec_and_print("p", 'b', st_a, st_b);
				if (flag == 1)
					exec_and_print("r", 'b', st_a, st_b);
				range = range + (size / 4);
			}
			else
				exec_and_print("r", 'a', st_a, st_b);
			//printf("range: %i\n", range);
		}
		if (!is_order(*st_a))
			sort_stack_a(st_a, st_b);
	}
	//printf("size: %i\n", ft_lstsize(*st_a));
	while (*st_b != NULL)
	{
		current = *st_a;
		//printf("b: %i, a: %i, current: %i, next: %i, lst: %i, order: %i\n", (*st_b)->content, (*st_a)->content, current->content, current->next->content, (ft_lstlast(*st_a))->content, is_order(*st_a));
		if (is_order(*st_a))
		{
			//printf("mark1\n");
			while ((*st_b)->content > current->content && current->next != NULL)
			{
				current = current->next;
				//printf("b: %i, a: %i, current: %i, next: %i, lst: %i\n", (*st_b)->content, (*st_a)->content, current->content, current->next->content, (ft_lstlast(*st_a))->content);
			}
			node_pos = ft_lstpos(*st_a, current);
			if (current->next == NULL && (*st_b)->content > current->content)
				node_pos++;
		}
		else
		{
			//printf("mark2\n");
			flag2 = 0;
			if ((*st_b)->content < current->content)
			{
				//printf("mark2.1\n");
				while ((current->next != NULL) && (*st_b)->content < current->content)
					current = current->next;
				if (current->next == NULL && (*st_b)->content < current->content)
					node_pos = ft_lstpos(*st_a, current) + 1;
				else if (current->next != NULL)
				{
					while ((current->next != NULL) && (*st_b)->content > current->content)
						current = current->next;
					if (current->next == NULL && (*st_b)->content > current->content)
						node_pos = ft_lstpos(*st_a, current) + 1;
					else
						node_pos = ft_lstpos(*st_a, current);
				}
				else
					node_pos = ft_lstpos(*st_a, current);
			}
			else
			{
				//printf("mark2.2\n");
				while ((current->next != NULL) && (*st_b)->content > current->content)
					current = current->next;
				if (current->next == NULL && (*st_b)->content > current->content)
					flag2 = 1;
				node_pos = ft_lstpos(*st_a, current);
			}
			if (flag2 == 1)
			{
				printf("mark2.3\n");
				current = *st_a;
				while (current->content > current->next->content)
				{
					current = current->next;
					printf("b: %i, a: %i, current: %i, next: %i, lst: %i\n", (*st_b)->content, (*st_a)->content, current->content, current->next->content, (ft_lstlast(*st_a))->content);
				}
				node_pos = ft_lstpos(*st_a, current);
			}
		}
		size = ft_lstsize(*st_a);
		//printf("num: %i, node: %i, size: %i\n", (*st_b)->content, node_pos, size);
		if (node_pos != 1)
		{
			if (node_pos <= size / 2)
			{
				while (node_pos > 1)
				{
					exec_and_print("r", 'a', st_a, st_b);
					node_pos--;
				}
			}
			else
			{
				while (node_pos <= size)
				{
					exec_and_print("rr", 'a', st_a, st_b);
					node_pos++;
				}
			}
		}
		exec_and_print("p", 'a', st_a, st_b);
	}
	if (!is_order(*st_a))
	{
		current = *st_a;
		while (current->content < current->next->content)
			current = current->next;
		node_pos = ft_lstpos(*st_a, current);
		if (node_pos <= size / 2)
			{
				while (node_pos > 1)
				{
					exec_and_print("r", 'a', st_a, st_b);
					node_pos--;
				}
			}
			else
			{
				while (node_pos <= size)
				{
					exec_and_print("rr", 'a', st_a, st_b);
					node_pos++;
				}
			}
	}
}

// {
// 	t_stack	*current;
// 	t_stack	*bottom;
// 	int		size;
// 	int		node_pos;
// 	int		flag;
// 	//int		j;
// 	int		flag2;

// 	if (!st_a || !*st_a || !(*st_a)->next)
// 		return ;
// 	current = *st_a;
// 	while (current->next != NULL)
// 	{
// 		if (current->content > current->next->content)
// 		{
// 			bottom = ft_lstlast(*st_a);
// 			size = ft_lstsize(*st_a);
// 			node_pos = ft_lstpos(*st_a, current);
// 			current = current->next;
// 			if (size == 2)
// 				exec_and_print("joker", 'a', st_a, st_b);
// 			else if (size == 3)
// 				if (current->content > current->next->content)
// 			{
// 			else if (((*st_a)->content < find_cutoff(st_a)))
// 			if ((*st_a)->content > bottom->content)
// 			{
// 				//Agrupar en una funcio rotate que valori internament si hem de fer normal o reverse rotate
// 				if (node_pos <= size / 2)
// 				{
// 					while (node_pos >= 1)
// 					{
// 						exec_and_print("r", 'a', st_a, st_b);
// 						node_pos--;
// 					}
// 				}
// 				else
// 				{
// 					while (node_pos < size)
// 					{
// 						exec_and_print("rr", 'a', st_a, st_b);
// 						node_pos++;
// 					}
// 				}
// 			}
// 			else if (node_pos > (size - node_pos))
// 			{
// 				while (node_pos <= size)
// 				{
// 					exec_and_print("rr", 'a', st_a, st_b);
// 					node_pos++;
// 				}
// 				exec_and_print("s", 'a', st_a, st_b);
// 				sort_stack_a(st_a, st_b);
// 			}
// 			else
// 			{
// 				flag = 0;
// 				if ((*st_b != NULL && (*st_a)->content < (*st_b)->content))
// 					flag = 1;
// 				while (node_pos > 1)
// 				{
// 					exec_and_print("p", 'b', st_a, st_b);
// 					//if (flag == 1)
// 					//	sort_stack_b(st_a, st_b);
// 					node_pos--;
// 				}
// 				if (flag == 1 && !is_inverse_order(*st_b))
// 					sort_stack_b(st_a, st_b);
// 				exec_and_print("s", 'a', st_a, st_b);
// 				current = current->next;
// 			}
// 		}
// 		else
// 			current = current->next;
// 	}
// 	//j = 0;
// 	//while (j <= 15)
// 	while (*st_b != NULL)
// 	{
// 		current = *st_a;
// 		//printf("b: %i, a: %i, current: %i, next: %i, lst: %i, order: %i\n", (*st_b)->content, (*st_a)->content, current->content, current->next->content, (ft_lstlast(*st_a))->content, is_order(*st_a));
// 		if (is_order(*st_a))
// 		{
// 			//printf("mark1\n");
// 			while ((*st_b)->content > current->content && current->next != NULL)
// 			{
// 				current = current->next;
// 				//printf("b: %i, a: %i, current: %i, next: %i, lst: %i\n", (*st_b)->content, (*st_a)->content, current->content, current->next->content, (ft_lstlast(*st_a))->content);
// 			}
// 			node_pos = ft_lstpos(*st_a, current);
// 			if (current ->next == NULL && (*st_b)->content > current->content)
// 				node_pos++;
// 		}
// 		else
// 		{
// 			//printf("mark2\n");
// 			flag2 = 0;
// 			if ((*st_b)->content < current->content)
// 			{
// 				//printf("mark2.1\n");
// 				while ((current->next != NULL) && (*st_b)->content < current->content)
// 					current = current->next;
// 				if (current->next == NULL && (*st_b)->content < current->content)
// 					flag2 = 1;
// 				while ((current->next != NULL) && (*st_b)->content > current->content)
// 					current = current->next;
// 				if (current->next == NULL && (*st_b)->content > current->content)
// 					flag2 = 1;
// 				node_pos = ft_lstpos(*st_a, current);
// 			}
// 			else
// 			{
// 				//printf("mark2.2\n");
// 				while ((current->next != NULL) && (*st_b)->content > current->content)
// 					current = current->next;
// 				if (current->next == NULL && (*st_b)->content > current->content)
// 					flag2 = 1;
// 				node_pos = ft_lstpos(*st_a, current);
// 			}
// 			if (flag2 == 1)
// 			{
// 				//printf("mark2.3\n");
// 				current = *st_a;
// 				while (current->content < current->next->content)
// 				{
// 					current = current->next;
// 					//printf("b: %i, a: %i, current: %i, next: %i, lst: %i\n", (*st_b)->content, (*st_a)->content, current->content, current->next->content, (ft_lstlast(*st_a))->content);
// 				}
// 				node_pos = ft_lstpos(*st_a, current) + 1;
// 			}
// 		}
// 		size = ft_lstsize(*st_a);
// 		//printf("num: %i, node: %i, size: %i\n", (*st_b)->content, node_pos, size);		
// 		if (node_pos != 1)
// 		{
// 			if (node_pos <= size / 2)
// 			{
// 				while (node_pos > 1)
// 				{
// 					exec_and_print("r", 'a', st_a, st_b);
// 					node_pos--;
// 				}
// 			}
// 			else
// 			{
// 				while (node_pos <= size)
// 				{
// 					exec_and_print("rr", 'a', st_a, st_b);
// 					node_pos++;
// 				}
// 			}
// 		}
// 		exec_and_print("p", 'a', st_a, st_b);
// 		//j++;
// 	}
// 	if (!is_order(*st_a))
// 		sort_stack_a(st_a, st_b);
// 	//com fer que printi l'ultima de manera m'es elegant que aix[o que repeteix exec_and_print 2 vegades en va.] potser fer des d-aquesta funcio la variable estatica de previous_command?
// 	exec_and_print("last", 'b', st_a, st_b);
// }

// // void	prepare_b_to_recieve(t_stack **st_a, t_stack **st_b)
// // {
// // 	t_stack	*current;
// // 	int		size;
// // 	int		node_pos;
// // 	int		flag2;

// // 	current = *st_b;
// // 	if (is_inverse_order(*st_b))
// // 	{
// // 		printf("mark1\n");
// // 		while ((*st_a)->content < current->content && current->next != NULL)
// // 			current = current->next;
// // 		node_pos = ft_lstpos(*st_b, current);
// // 		if ((*st_a)->content < current->content && current->next == NULL)
// // 			node_pos++;
// // 	}
// // 	else
// // 	{
// // 		flag2 = 0;
// // 		if ((*st_a)->content < current->content)
// // 		{
// // 			while ((current->next != NULL) && (*st_a)->content < current->content)
// // 				current = current->next;
// // 			if (current->next == NULL && (*st_a)->content < current->content)
// // 				flag2 = 1;
// // 			node_pos = ft_lstpos(*st_b, current);
// // 		}
// // 		else
// // 		{
// // 			while ((current->next != NULL) && (*st_a)->content > current->content)
// // 				current = current->next;
// // 			if (current->next == NULL && (*st_a)->content > current->content)
// // 				flag2 = 1;
// // 			while ((current->next != NULL) && (*st_a)->content < current->content)
// // 				current = current->next;
// // 			if (current->next == NULL && (*st_a)->content < current->content)
// // 				flag2 = 1;
// // 			node_pos = ft_lstpos(*st_b, current);
// // 		}
// // 		if (flag2 == 1)
// // 		{
// // 			current = *st_b;
// // 			while (current->content > current->next->content)
// // 				current = current->next;
// // 			node_pos = ft_lstpos(*st_b, current) + 1;
// // 		}
// // 	}
// // 	size = ft_lstsize(*st_b);
// // 	if (node_pos != 1)
// // 	{
// // 		if (node_pos <= size / 2)
// // 		{
// // 			while (node_pos > 1)
// // 			{
// // 				exec_and_print("r", 'b', st_a, st_b);
// // 				node_pos--;
// // 			}
// // 		}
// // 		else
// // 		{
// // 			while (node_pos <= size)
// // 			{
// // 				exec_and_print("rr", 'b', st_a, st_b);
// // 				node_pos++;
// // 			}
// // 		}
// // 	}
// // }

// void	sort_stack_b(t_stack **st_a, t_stack **st_b)
// {
// 	t_stack	*bottom;
// 	int		size;

// 	if (!st_b || !*st_b || !(*st_b)->next)
// 		return ;
// 	bottom = ft_lstlast(*st_b);
// 	size = ft_lstsize(*st_b);
// 	if (size == 2)
// 		exec_and_print("joker", 'b', st_a, st_b);
// 	else if ((*st_b)->content < bottom->content)
// 		exec_and_print("r", 'b', st_a, st_b);
// 	else if ((*st_b)->content < (*st_b)->next->content)
// 		exec_and_print("s", 'b', st_a, st_b);
// 	//if (!is_inverse_order(*st_b))
// 	//	sort_stack_b(st_a, st_b);
// }

void	exec_and_print(char *command, char stack_id, t_stack **st_a, t_stack **st_b)
{
	t_stack		**stack;
	t_stack		**other_stack;
	static char	*previous_command;
	static char	previous_id;

	if (command[0] == 'l')
	{
		previous_command = print_command(previous_command, command, previous_id, 'a');
		return ;
	}
	other_stack = st_b;
	if (stack_id == 'a')
		stack = st_a;
	else
	{
		stack = st_b;
		other_stack = st_a;
	}
	if (command[0] == 's' || command[0] == 'j')
		swap(stack);
	else if (command[0] == 'r')
	{
		if (command[1] == '\0')
			rotate(stack);
		else
			reverse_rotate(stack);
	}
	else if (command[0] == 'p')
		push(stack, other_stack);
	previous_command = print_command(previous_command, command, previous_id, stack_id);
	previous_id = stack_id;
}

char	*print_command (char *previous_command, char *command, char previous_id, char stack_id)
{
	int	joined_commands;

	if (!previous_command || previous_command[0] == 'l')
		return (command);
	joined_commands = 0;
	if (previous_command[0] == command[0] || previous_command[0] == 'j' || command[0] == 'j')
	{
		if (stack_id != previous_id)
		{
			joined_commands = 1;
			if (previous_command[0] == 'j')
			{
				if (command[0] != 'j')
					previous_command = command;
				else
					previous_command = "s";
			}
			previous_id = 's';
		}
	}
	write (1, previous_command, ft_strlen(previous_command));
	write (1, &previous_id, 1);
	write (1, "\n", 1);
	if (joined_commands == 1)
		previous_command = NULL;
	else
		previous_command = command;
	return (previous_command);
}


/*
./a.out -127 156 -67 92 -143 37 -82 198 -12 73 -195 113 -31 168 -96 22 -158 147 -52 83 -173 128 -6 191 -116 47 -137 162 -41 98 -184 133 -26 177 -91 58 -148 107 -61 88 -169 123 -16 187 -106 42 -132 152 -36 93 -179 118 -21 172 -86 53 -153 142 -46 78 -164 138 -11 182 -101 32 -146 157 -56 68 -189 143 -1 167 -111 27 -147 132 -71 63 -159 148 -76 197 -124 17 -122 137 -51 103 -174 134 -39 192 -81 12 -157 155 -34 108 | wc -l
primer algoritme: 5654
incloent que faci rra si es mes de la meitat: 5010
incloent que faci rra si es mes de la meitat + sort b nomes quan hagi acabat de push tots els d'a: 4989
collocant al lloc on toca cada numero abans de "pa": 1971

*/