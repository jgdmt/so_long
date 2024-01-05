/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:47:19 by jgoudema          #+#    #+#             */
/*   Updated: 2023/10/23 13:59:52 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_change_base(unsigned long int nbr, int base_num, char *base)
{
	if (nbr >= (unsigned) base_num)
	{
		if (ft_change_base(nbr / base_num, base_num, base) == -1)
			return (-1);
		if (ft_change_base(nbr % base_num, base_num, base) == -1)
			return (-1);
	}
	else if (nbr < 0)
	{
		if (ft_putchar('-', 1) == -1)
			return (-1);
		if (ft_change_base(-nbr, base_num, base) == -1)
			return (-1);
	}
	else
		if (ft_putchar(base[nbr], 1) == -1)
			return (-1);
	return (0);
}
