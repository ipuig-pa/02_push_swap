/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/16 13:58:28 by ipuig-pa         ###   ########.fr       */
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
		argc = arrlen(argv);
	}
	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !valid_input_to_arr(argc, argv, arr))
		return (handle_error(flag, argv, arr));
	if (!is_arr_order(arr, argc - 1))
	{
		stack_a = parse_in_stack(argc, arr);
		if (!stack_a)
			return (handle_error(flag, argv, arr));
		sort_stack_a(&stack_a);
		clear_stack(stack_a);
	}
	if (flag == 1)
		free(argv);
	return (free(arr), 0);
}
