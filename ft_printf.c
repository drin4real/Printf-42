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
int	main(void)
{
	char *str = "Vere nec si meo adulescenti meo hac existimare descensurum";
	int nb = -2147483648;
	int n = 846599;
	char c = 'q';

	printf("bytes : %d\n", ft_printf("MINE (%%s)> %s,\n", str));
	printf("bytes : %d\n\n", printf("REAL (%%s)> %s,\n", str));
	printf("bytes : %d\n", ft_printf("MINE (%%d)> %d,\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%d)> %d,\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%i)> %i,\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%i)> %i,\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%u)> %u,\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%u)> %u,\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%x)> %x,\n", n));
	printf("bytes : %d\n\n", printf("REAL (%%x)> %x,\n", n));
	printf("bytes : %d\n", ft_printf("MINE (%%X)> %X,\n", n));
	printf("bytes : %d\n\n", printf("REAL (%%X)> %X,\n", n));
	printf("bytes : %d\n", ft_printf("MINE (%%p)> %p,\n", &nb));
	printf("bytes : %d\n\n", printf("REAL (%%p)> %p,\n", &nb));
	printf("bytes : %d\n", ft_printf("MINE (%%c)> %c,\n", c));
	printf("bytes : %d\n\n", printf("REAL (%%c)> %c,\n", c));
	printf("bytes : %d\n", ft_printf("MINE (%%)> %%,\n"));
	printf("bytes : %d\n\n", printf("REAL (%%)> %%,\n"));
//gcc ft_printf.c printf_utils/ft_printf_utils1.c printf_utils/ft_printf_utils2.c
}*/