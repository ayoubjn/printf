/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajana <ajana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:15:27 by ajana             #+#    #+#             */
/*   Updated: 2021/11/23 18:10:20 by ajana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conver(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 's' || c == 'p' || c == 'c')
		return (1);
	return (0);
}

int	put(char c, void *arg)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr_dec((int)arg);
	else if (c == 'u')
		count += ft_putnbr_dec((unsigned int)arg);
	else if (c == 'X')
		count += ft_putnbr_hex((unsigned int)arg, "0123456789ABCDEF");
	else if (c == 'x')
		count += ft_putnbr_hex((unsigned int)arg, "0123456789abcdef");
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex((unsigned long long)arg, "0123456789abcdef");
	}
	else if (c == 's')
		count += ft_putstr((char *)arg);
	else if (c == 'c')
		count += ft_putchar((char)arg);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (is_conver(*s))
				count += put(*s, va_arg(ptr, void *));
			else
				count += ft_putchar(*s);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(ptr);
	return (count);
}
