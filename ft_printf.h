/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 09:30:05 by dbislimi          #+#    #+#             */
/*   Updated: 2024-04-23 09:30:05 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbrhex(unsigned long nb, char c, int i);
int		ft_putuinbr(unsigned int n);
int		ft_nbrlen(int nb);
int		manage_limits(long long nb, char c);
char	*ft_strdup(const char *s);

#endif