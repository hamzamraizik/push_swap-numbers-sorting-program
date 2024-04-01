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
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((result > INT_MAX && sign == 1)
		|| (sign == -1 && (result > 2147483648)) || str[i] != '\0')
		error();
	result *= sign;
	return (result);
}
