/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:46:47 by jgoudema          #+#    #+#             */
/*   Updated: 2023/10/23 14:09:05 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (s == NULL)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
	}
	else
	{
		while (*s)
		{
			if (ft_putchar(*s, 1) == -1)
				return (-1);
			s++;
		}
	}
	return (0);
}

int	ft_putchar(char c, int f)
{
	static int	s = 0;

	if (f == 1)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		s++;
	}
	else if (f == 2)
		s = 0;
	return (s);
}
