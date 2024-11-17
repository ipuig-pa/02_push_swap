/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:35:26 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/17 16:37:29 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error(int flag, char **argv, int *arr, int argc)
{
	if (flag == 1)
		free_double_pointer(argv);
	if (arr)
		free(arr);
	if (argc >= 2)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}

int	arrlen(char **arr)
{
	int	len;

	if (arr == NULL)
		return (0);
	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

int	is_int(char *str)
{
	int		i;
	long	integer;
	long	sign;

	integer = 0;
	sign = 1;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + (str[i] - '0');
		if (integer * sign > INT_MAX || integer * sign < INT_MIN)
			return (0);
		i++;
	}
	if (str[i] != '\0' || i == 0)
		return (0);
	return (1);
}

int	is_arr_order(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int num)
{
	int	i;

	if (num < 4)
		return (1);
	i = 2;
	while (i * i < num)
	{
		if (i * i == num)
			return (i);
		i++;
	}
	return (i);
}
