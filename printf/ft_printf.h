/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:16:35 by mbenouis          #+#    #+#             */
/*   Updated: 2025/02/02 17:16:41 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_formatchecker(const char *str, int i, va_list va);
int	ft_checkcontent(const char *str, va_list va);
int	ft_printf(const char *str, ...);
int	ft_putnbr(int nb, int add);
int	ft_putnbr_unsigned(unsigned int nb, int count);
int	ft_puthex(unsigned int nb, long long int add);
int	ft_mputhex(unsigned int nb, long long int add);
int	ft_putnbr(int nb, int add);
int	counthexlen(unsigned long long nb);
int	ft_putptr(void *ptr);

#endif
