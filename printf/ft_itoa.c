/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:45:35 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 15:41:08 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_write(int n, int i, int sign, char *str)
{
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (n % 10 * sign) + 48;
		n = n / 10; 
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

int	ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = ft_intlen(n);
	str = malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (-1);
	str = ft_itoa_write(n, i, sign, str);
	if (ft_putstr(str) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

static int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_uintlen(n);
	str = malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (-1);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10; 
	}
	if (ft_putstr(str) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}
