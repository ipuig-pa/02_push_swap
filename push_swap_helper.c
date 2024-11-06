/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:35:26 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/06 09:29:56 by ipuig-pa         ###   ########.fr       */
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

t_stack	*clear_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (NULL);
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

