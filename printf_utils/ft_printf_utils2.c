/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 09:54:33 by dbislimi          #+#    #+#             */
/*   Updated: 2024-04-23 09:54:33 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	manage_limits(long long nb, char c)
{
	if (c == 'p' && nb == LONG_MIN)
		return (ft_putstr("8000000000000000"));
	else if (c == 'p' && nb == (long long)ULONG_MAX)
		return (ft_putstr("ffffffffffffffff"));
	else if ((nb == LONG_MAX || nb == (long long)ULONG_MAX) && c == 'X')
		return (ft_putstr("FFFFFFFF"));
	else if ((nb == LONG_MAX || nb == (long long)ULONG_MAX) && c == 'x')
		return (ft_putstr("ffffffff"));
	return (ft_putchar('0'));
}

int	ft_putnbrhex(long long nb, char c, int i)
{
	char	*base;
	int		len;

	len = 0;
	if ((c == 'p' && (nb == LONG_MIN || nb == (long long)ULONG_MAX))
		|| (c != 'p' && (nb == LONG_MAX || nb == LONG_MIN
				|| nb == (long long)ULONG_MAX)))
		return (manage_limits(nb, c));
	else if (i == 8 && c != 'p')
		return (0);
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb >= 16)
	{
		len = ft_putnbrhex(nb / 16, c, ++i);
		ft_putchar(base[nb % 16]);
	}
	else
		ft_putchar(base[nb]);
	return (len + 1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = ft_nbrlen(n);
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	return (len);
}

int	ft_putuinbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		i = ft_putuinbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	return (i + 1);
}
