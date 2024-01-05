/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:16:04 by jgoudema          #+#    #+#             */
/*   Updated: 2023/12/05 15:16:08 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
}

static char	**ft_free_str(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(strs[i++]);
	free(strs);
	return (0);
}

char	**ft_map_copy(t_map *mdata)
{
	char	**copy;
	char	*str;
	int		i;

	copy = malloc((mdata->height + 1) * sizeof(char *));
	if (!copy)
		return (0);
	i = 0;
	while (i < mdata->height)
	{
		str = malloc(mdata->width + 1);
		if (!str)
			return (ft_free_str(copy, i));
		ft_strcpy(str, mdata->map[i]);
		copy[i++] = str;
	}
	copy[i] = 0;
	return (copy);
}
