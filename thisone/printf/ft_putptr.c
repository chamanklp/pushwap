/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:04:13 by mbenouis          #+#    #+#             */
/*   Updated: 2025/02/02 17:04:17 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	printptr(unsigned long long nb)
{
	const char	*base = "0123456789abcdef";

	if (nb >= 16)
		printptr (nb / 16);
	write (1, &base[nb % 16], 1);
}

int	counthexlen(unsigned long long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	printptr ((unsigned long long)ptr);
	return (counthexlen((unsigned long long)ptr) + 2);
}
