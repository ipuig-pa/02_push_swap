/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 15:35:21 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*arr;
	int		flag;

	flag = 0;
	if (argc == 2)
	{
		flag = 1;
		argv = ft_split(argv[1], ' ');
		argc = arrlen(argv) + 1;
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
		free_double_pointer(argv);
	return (free(arr), 0);
}
