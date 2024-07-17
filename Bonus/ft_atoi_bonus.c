/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:55 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/03 02:45:43 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r');
}

long	ft_isdigit(long i)
{
	return (i >= '0' && i <= '9');
}

int	ft_atoi(const char *str, long i)
{
	int	sign;
	int	result;
	int	number;

	sign = 1;
	result = 0;
	number = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	(str[i] == '\0' && (error()));
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = number * 10 + str[i++] - '0';
		if ((result < number && sign == 1) || (-result > number && sign == -1))
			error ();
		number = result;
	}
	(str[i]) && (error());
	return (result * sign);
}
