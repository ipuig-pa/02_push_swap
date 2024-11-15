/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:35:26 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/15 15:04:45 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	display_error(void)
{
	printf("Error\n");
	return (1);
}

int	is_valid_input(int argc, char **argv, int *arr)
{
	int	i;
	int	j;

	i = 0;
	if (argc <= 2)
		return (0);
	while (i + 1 < argc)
	{
		if (!is_int(argv[i + 1]))
			return (0);
		arr[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
	if (str[i] != '\0')
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

int	ft_sqrt(int nb)
{
	int	res;
	int	previous_approx;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
	{
		return (nb);
	}
	res = nb / 2;
	previous_approx = 0;
	while (res != previous_approx)
	{
		previous_approx = res;
		res = 0.5 * (res + nb / res);
	}
	if (res * res == nb)
		return (res);
	return (0);
}


//eliminar ft_atoi d-aqui si es posa a libft
int	ft_atoi(const char *str)
{
	int	integer;
	int	sign;

	integer = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		integer = integer * 10 + (*str - '0');
		str++;
	}
	return (integer * sign);
}

//eliminar strlen d-aqui
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
