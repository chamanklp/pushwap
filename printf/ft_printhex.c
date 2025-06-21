/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:02:42 by mbenouis          #+#    #+#             */
/*   Updated: 2025/02/02 17:02:45 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int nb, long long int add)
{
	char		*base;
	static int	count;

	count = add;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_puthex(nb / 16, count);
		ft_puthex(nb % 16, count);
	}
	else
	{
		write(1, &base[nb], 1);
		count ++;
	}
	return (count);
}

int	ft_mputhex(unsigned int nb, long long int add)
{
	char		*base;
	static int	count;

	count = add;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_mputhex(nb / 16, count);
		ft_mputhex(nb % 16, count);
	}
	else
	{
		write (1, &base[nb], 1);
		count ++;
	}
	return (count);
}
