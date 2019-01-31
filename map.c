/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:36:22 by magrinbe          #+#    #+#             */
/*   Updated: 2019/01/30 18:18:21 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nb_pieces(char **tab)
{
	int o;

	o = 0;

	while (tab[o])
		o++;
	return (o);
}

char	*create_map(char **tab)
{
	int		i;
	int		o;
	int		j;
	int		a;
	char	*map;

	a = 1;
	i = 0;
	j = 0;
	o = ft_sqrt(nb_pieces(tab) * 4);
	map = (char *)malloc(sizeof(char) * (o * o + o + 1));
	while (i < o * o + o)
	{
		map[i] = '.';
		if (i == (o) * a + j)
		{
			map[i] = '\n';
			a++;
			if (a > 1)
				j++;
		}
		i++;
	}
	map[i] = '\0';
	return (map);
}
