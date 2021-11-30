/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajana <ajana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:50:48 by ajana             #+#    #+#             */
/*   Updated: 2021/11/22 16:57:49 by ajana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recu(unsigned long long n, int *count)
{
	char	*dec;

	dec = "0123456789";
	if (n > 9)
		recu(n / 10, count);
	*count += ft_putchar(dec[n % 10]);
}

int	ft_putnbr_dec(long long n)
{
	unsigned long long	nu;
	int					count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		nu = n * -1;
	}
	else
		nu = n;
	recu(nu, &count);
	return (count);
}
