/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajana <ajana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:15:31 by ajana             #+#    #+#             */
/*   Updated: 2021/11/22 16:59:16 by ajana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recu(unsigned long long n, char *base, int *count)
{
	if (n > 15)
		recu(n / 16, base, count);
	*count += ft_putchar(base[n % 16]);
}

int	ft_putnbr_hex(unsigned long long n, char *base)
{
	int	count;

	count = 0;
	recu(n, base, &count);
	return (count);
}
