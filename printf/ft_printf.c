/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:39:11 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/23 11:48:53 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write(const char *str, va_list ap, int res)
{
	if (*str == 'c')
		res = ft_putchar(va_arg(ap, int), 1);
	else if (*str == 'd' || *str == 'i')
		res = ft_itoa(va_arg(ap, int));
	else if (*str == 'X')
		res = ft_change_base(va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
	else if (*str == 'x')
		res = ft_change_base(va_arg(ap, unsigned int), 16, "0123456789abcdef");
	else if (*str == 's')
		res = ft_putstr(va_arg(ap, char *));
	else if (*str == 'u')
		res = ft_uitoa(va_arg(ap, unsigned int));
	else if (*str == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		res = ft_change_base(va_arg(ap, unsigned long), 16, "0123456789abcdef");
	}
	else if (*str == '%')
		res = ft_putchar(*str, 1);
	else
		return (-1);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;

	if (str == NULL)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_write(++str, ap, 0) == -1)
				return (-1);
		}
		else
			if (ft_putchar(*str, 1) == -1)
				return (-1);
		str++;
	}
	va_end(ap);
	res = ft_putchar(0, 0);
	ft_putchar(0, 2);
	return (res);
}
