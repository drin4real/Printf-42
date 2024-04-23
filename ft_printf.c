/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 09:27:56 by dbislimi          #+#    #+#             */
/*   Updated: 2024-04-23 09:27:56 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	manage_format(char c, va_list arg, int *printed)
{
	if (c == 'c')
		*printed += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		*printed += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		*printed += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		*printed += ft_putuinbr(va_arg(arg, unsigned int));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		*printed += ft_putnbr_hexa(va_arg(arg, long), c) + 2;
	}
	else if (c == 'x' || c == 'X')
		*printed += ft_putnbr_hexa(va_arg(arg, long), c);
	else if (c == '%')
		*printed += ft_putchar('%');
}

static int	analyse_the_string(const char *s, va_list arg)
{
	int	i;
	int	printed_char;

	i = 0;
	printed_char = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
		{
			manage_format(s[++i], arg, &printed_char);
			i++;
		}
		write(1, &s[i++], 1);
		printed_char++;
	}
	return (printed_char);
}

int	ft_printf(const char *s, ...)
{
	int		printed_char;
	va_list	ap;

	va_start(ap, s);
	printed_char = analyse_the_string(s, ap);
	va_end(ap);
	return (printed_char);
}
/*
int	main()
{
	char *str =  "OUI";
//	int nb = -2147483648;
//	char c = 'q';
//	printf("    %d\n", ft_putnbr_hexa(nb));
	ft_printf("%d\n", ft_printf("MINE > %s,\n", str));
	printf("%d\n", printf("REAL > %s,\n", str));
}*/