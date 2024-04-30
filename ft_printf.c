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

static int	manage_format(char c, va_list arg)
{
	long	p;

	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putuinbr(va_arg(arg, unsigned int)));
	else if (c == 'p')
	{
		p = va_arg(arg, long long);
		if (p == 0)
			return (ft_putstr("(nil)"));
		else
			return (ft_putstr("0x") + ft_putnbrhex(p, c, 0));
	}
	else if (c == 'x' || c == 'X')
		return (ft_putnbrhex(va_arg(arg, long long), c, 0));
	return (ft_putchar('%'));
}

static int	analyse_the_string(const char *s, va_list arg)
{
	int	i;
	int	printed_char;

	i = 0;
	printed_char = 0;
	while (s[i])
	{
		while (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
		{
			printed_char += manage_format(s[++i], arg);
			i++;
		}
		if (s[i])
		{
			write(1, &s[i++], 1);
			printed_char++;
		}
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
	char	*str = "Vere nec si meo adulescenti meo hac existimare descensurum";
	int		nb = -2147483648;
	int 	n = -846599;
	char	c = 'a';

	printf("bytes : %d\n", ft_printf("MINE (%%s)> %s%s%s,\n", str, str, str));
	printf("bytes : %d\n\n", printf("REAL (%%s)> %s%s%s,\n", str, str, str));
	printf("bytes : %d\n", ft_printf("MINE (%%d)> %d,\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%d)> %d,\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%i)> %i,\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%i)> %i,\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%u)> %u,\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%u)> %u,\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%x)> %x\n", nb));
	printf("bytes : %d\n\n", printf("REAL (%%x)> %x\n", nb));
	printf("bytes : %d\n", ft_printf("MINE (%%X)> %X,\n", LONG_MIN));
	printf("bytes : %d\n\n", printf("REAL (%%X)> %X,\n", LONG_MIN));
	printf("bytes : %d\n", ft_printf("MINE (%%p)> %p,\n",ULONG_MAX));
	printf("bytes : %d\n\n", printf("REAL (%%p)> %p,\n",ULONG_MAX));
	printf("bytes : %d\n", ft_printf("MINE (%%c)> %c,\n", c));
	printf("bytes : %d\n\n", printf("REAL (%%c)> %c,\n", c));
	printf("bytes : %d\n", ft_printf("MINE (%%%%)> %%,\n"));
	printf("bytes : %d\n\n", printf("REAL (%%%%)> %%,\n"));
//gcc ft_printf.c printf_utils/ft_printf_utils1.c printf_utils/ft_printf_utils2.c
}*/