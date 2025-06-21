/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:01:56 by mbenouis          #+#    #+#             */
/*   Updated: 2025/02/02 17:02:02 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_formatchecker(const char *str, int i, va_list va)
{
	int	adding;

	adding = 0;
	if (str[i] == 'c')
		adding += ft_putchar(va_arg(va, int));
	else if (str[i] == 's')
		adding += ft_putstr(va_arg(va, char *));
	else if (str[i] == 'p')
		adding += ft_putptr(va_arg(va, void *));
	else if (str[i] == 'd' || str[i] == 'i')
		adding += ft_putnbr(va_arg(va, int), 0);
	else if (str[i] == 'u')
		adding += ft_putnbr_unsigned(va_arg(va, unsigned int), 0);
	else if (str[i] == 'x')
		adding += ft_puthex(va_arg(va, unsigned int), 0);
	else if (str[i] == 'X')
		adding += ft_mputhex(va_arg(va, unsigned int), 0);
	else if (str[i] == '%')
		adding += ft_putchar('%');
	return (adding);
}

int	ft_checkcontent(const char *str, va_list va)
{
	unsigned long long	counter;
	int					i;

	counter = 0 ;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			counter++;
		}
		else
		{
			i++;
			counter += ft_formatchecker(str, i, va);
		}
		i++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;

	va_start(va, str);
	if (str != NULL)
		return (ft_checkcontent(str, va));
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	va_end (va);
}
