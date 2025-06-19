/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:03:48 by mbenouis          #+#    #+#             */
/*   Updated: 2025/02/02 17:03:51 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb, int add)
{
	static int	count;

	count = add;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		count ++;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
	{
		ft_putchar(nb + '0');
		count ++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb, int add)
{
	static int	count;

	count = add;
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
		count++;
		return (count);
	}
	count = ft_putnbr_unsigned(nb / 10, count);
	count = ft_putnbr_unsigned(nb % 10, count);
	return (count);
}
