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

int	ft_putnbr_hexa(unsigned long nb, char c)
{
	int		len;
	char	*base;

	len = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb >= 16)
	{
		len = ft_putnbr_hexa(nb / 16, c);
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
