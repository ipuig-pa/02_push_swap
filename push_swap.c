/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/11 15:09:02 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//eliminar stdio.h, canviar printf per ft_printf

int	main(int argc, char **argv)
{
	int		*st_a;
	int		*st_b;
	int		i;

	st_a = (int *)malloc((argc - 1) * sizeof(int));
	st_b = (int *)malloc((argc - 1) * sizeof(int));
	if (!st_a || !st_b || !create_array(argc, argv, st_a))
	{
		if (st_a)
			free(st_a);
		if (st_b)
			free(st_b);
		return (display_error());
	}
	if (!a_is_in_order(st_a, argc - 1))
		sort_stack_a(st_a, st_b, argc - 1, 0);
	//checker
	// if (b_size == 0)
	// {
	// 	i = 0;
	// 	while (i <= argc - 1)
	// 	{
	// 		if (st_a[i] > st_a[i + 1])
	// 			printf("KO\n");
	// 		i++;
	// 	}
	// 	printf("OK\n");
	// }
	//visual checking
	i = 0;
	while (i <= argc - 2)
	{
		printf("%d\n", st_a[i]);
		i++;
	}
	free(st_a);
	free(st_b);
	return (0);
}

void	sort_stack_a(int *st_a, int *st_b, int a_size, int b_size)
{
	int	i;
	int	flag;

	i = 0;
	while (i < (a_size - 2))
	{
		if (st_a[i] > st_a[i + 1])

			if (a_size == 2)
				exec_and_print("joker", 'a', st_a, st_b, a_size, b_size);
			else if (st_a[0] > st_a[a_size - 1])
			{
				if (i < a_size / 2)
				{
					while (i >= 0)
					{
						exec_and_print("r", 'a', st_a, st_b, a_size, b_size);
						i--;
					}
				}
				else
				{
					while (i < (a_size - 1))
					{
						exec_and_print("rr", 'a', st_a, st_b, a_size, b_size);
						i++;
					}
				}
				i = -1;
			}
			else if (i >= a_size / 2)
			{
				while (i < a_size - 1)
				{
					exec_and_print("rr", 'a', st_a, st_b, a_size, b_size);
					i++;
				}
				i = -1;
			}
			else
			{
				if ((i == 0) || (i == 1 && st_a[0] < st_a[2]))
					exec_and_print("s", 'a', st_a, st_b, a_size, b_size);
				else
				{
					flag = 0;
					if (b_size != 0 && st_a[0] < st_b[0])
						flag = 1;
					while (i >= 0)
					{
						exec_and_print("p", 'b', st_a, st_b, a_size, b_size);
						a_size--;
						b_size++;
						i--;
					}
					if (flag == 1)
						sort_stack_b(st_a, st_b, a_size, b_size);
					i = -1;
				}
			}
		}
		i++;
	}
	// j = 0;
	// while (j <= b_size - 1)
	// {
	// 	printf("b.%i: %i\n", j, st_b[j]);
	// 	j++;
	// }
	// j = 0;
	// while (j <= a_size - 1)
	// {
	// 	printf("a.%i: %i\n", j, st_a[j]);
	// 	j++;
	// }
	while (b_size != 0)
	{
		//afegir aquesta condici'o
		while (st_a[i] < st_b[0])
			i++; 
		if (i < size / 2)
			rotate fins que toqui entrar
		exec_and_print("p", 'a', st_a, st_b, a_size, b_size);
		a_size++;
		b_size--;
	}
	if (!a_is_in_order(st_a, a_size))
		sort_stack_a(st_a, st_b, a_size, b_size);
	//com fer que printi l'ultima de manera m'es elegant que aix[o que repeteix exec_and_print 2 vegades en va.] potser fer des d-aquesta funcio la variable estatica de previous_command?
	exec_and_print("last", 'b', st_a, st_b, a_size, b_size);
}

int	a_is_in_order(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack_b(int *st_a, int *st_b, int a_size, int b_size)
{
	if (b_size == 2)
		exec_and_print("joker", 'b', st_a, st_b, a_size, b_size);
	else if (st_b[0] < st_b[b_size - 1])
		exec_and_print("r", 'b', st_a, st_b, a_size, b_size);
	else if (st_b[0] < st_b[1])
		exec_and_print("s", 'b', st_a, st_b, a_size, b_size);
	else
		printf("Creia que no es donaria aquesta condicio\n");
}

void	exec_and_print(char *command, char stack_id, int *st_a, int *st_b, int a_size, int b_size)
{
	int		*stack;
	int		*other_stack;
	int		size;
	int		other_size;
	static char	*previous_command;
	static char	previous_id;

	if (command[0] == 'l')
	{
		previous_command = print_command(previous_command, command, previous_id, 'b');
		return ;
	}
	stack = st_a;
	size = a_size;
	other_stack = st_b;
	other_size = b_size;
	if (stack_id == 'b')
	{
		stack = st_b;
		size = b_size;
		other_stack = st_a;
		other_size = a_size;
	}
	if (command[0] == 's' || command[0] == 'j')
		swap(stack);
	else if (command[0] == 'r')
	{
		if (command[1] == '\0')
			rotate(stack, size);
		else
			reverse_rotate(stack, size);
	}
	else if (command[0] == 'p')
		push(stack, other_stack, size, other_size);
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
				if (command[0] != 'j' && command[0] != 'l')
					previous_command = command;
				else
					previous_command = "s";
			}
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

*/