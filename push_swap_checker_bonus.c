/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:18:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 12:35:26 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	int		*arr;
	int		flag;

	if (push_swap(argc, argv) == 1)
		return (1);
	flag = 0;
	if (argc == 2)
	{
		flag = 1;
		argv = ft_split(argv[1], ' ');
		argc = arrlen(argv);
	}
	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !valid_input_to_arr(argc, argv, arr, flag))
		return (handle_error(flag, argv, arr, 1));
	st_a = parse_in_stack(argc, arr);
	st_b = NULL;
	if (!read_and_exec(&st_a, &st_b))
		return (handle_error(flag, argv, arr, 3));
	checker(&st_a, &st_b);
	if (flag == 1)
		free(argv);
	return (free(arr), 0);
}

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		flag = 1;
		argv = ft_split(argv[1], ' ');
		argc = arrlen(argv);
	}
	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !valid_input_to_arr(argc, argv, arr, flag))
		return (handle_error(flag, argv, arr, argc));
	if (!is_arr_order(arr, argc - 1))
	{
		stack_a = parse_in_stack(argc, arr);
		if (!stack_a)
			return (handle_error(flag, argv, arr, argc));
		sort_stack_a(&stack_a);
		clear_stack(stack_a);
	}
	if (flag == 1)
		free(argv);
	return (free(arr), 0);
}

int	read_and_exec(t_stack **st_a, t_stack **st_b)
{
	char	*read;
	char	*command;
	char	*st_id;
	int		read_len;

	read = get_next_line(1);
	while (read)
	{
		read_len = ft_strlen(read);
		if (read_len == 2)
			command = ft_substr(read, 0, 1);
		else if (read_len == 3)
			command = ft_substr(read, 0, 2);
		else
			return (free(read), 0);
		st_id = ft_substr(read, read_len - 1, 1);
		if (!exec (command, *st_id, st_a, st_b))
			return (free(read), 0);
		read = get_next_line(1);
	}
	return (free(read), 1);
}

int	exec(char *comm, char st_id, t_stack **st_a, t_stack **st_b)
{
	if (comm[0] == 's' && comm[1] == '\0')
	{
		if (st_id == 'a')
			swap(st_a);
		else if (st_id == 'b')
			swap(st_b);
		else if (st_id == 's')
		{
			swap(st_a);
			swap(st_b);
		}
		else
			return (0);
	}
	else if (comm[0] == 'p' && comm[1] == '\0')
	{
		if (st_id == 'a')
			push(st_a, st_b);
		else if (st_id == 'b')
			push(st_b, st_a);
		else
			return (0);
	}
	else if (comm[0] == 'r' && comm[1] == '\0')
	{
		if (st_id == 'a')
			rotate(st_a);
		else if (st_id == 'b')
			rotate(st_b);
		else if (st_id == 'r')
		{
			rotate(st_a);
			rotate(st_b);
		}
		else
			return (0);
	}
	else if (comm[0] == 'r' && comm[1] == 'r' && comm[2] == '\0')
	{
		if (st_id == 'a')
			reverse_rotate(st_a);
		else if (st_id == 'b')
			reverse_rotate(st_b);
		else if (st_id == 'r')
		{
			reverse_rotate(st_a);
			reverse_rotate(st_b);
		}
		else
			return (0);
	}
	else
		return (0);
}

void	checker(t_stack **st_a, t_stack **st_b)
{
	t_stack	*current;

	if (!st_a || !st_b || !*st_a)
		exit_and_print(0, st_a, st_b);
	if (*st_b == NULL)
	{
		current = *st_a;
		while (current->next != NULL)
		{
			if (current->content > current->next->content)
				exit_and_print(0, st_a, st_b);
			current = current->next;
		}
		exit_and_print(1, st_a, st_b);
	}
	else
		exit_and_print(0, st_a, st_b);
}

void	exit_and_print(int result, t_stack **st_a, t_stack **st_b)
{
	if (result == 1)
		ft_printf("OK\n");
	else if (result == 0)
		ft_printf("KO\n");
	if (*st_a)
		clear_stack(*st_a);
	if (*st_b)
		clear_stack(*st_b);
}
