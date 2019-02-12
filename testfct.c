/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:41:58 by magrinbe          #+#    #+#             */
/*   Updated: 2019/02/11 16:54:08 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		try_pos(char *map, char **tab, int j, int o)
{
	int i;
	int start;
	int len;

	start = j;
	len = 0;
	i = 0;
	while (map[len] != '\n')
		len++;
	len++;
	if (map[j] != '.')
		return (0);
	while (tab[o][i])
	{
		if (tab[o][i] == '\n')
		{
			j = start + len;
			while (tab[o][i])
			{
				if ((map[j] != '.' && tab[o][i]) || (map[j] == '\n' && tab[o][i] != map[j]))
					return (0);
				i++;
				j++;
			}
		}
		i++;
		j++;
		if ((map[j] != '.' && tab[o][i]) || (map[j] == '\n' && tab[o][i] != map[j]))
			return (0);
	}
	return (1);
}

int		main()
{
	char tablo[21];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 21)
	{
		tablo[i] = '.';
		i++;
	}
	tablo[4] = '\n';
	tablo[9] = '\n';
	tablo[14] = '\n';
	tablo[19] = '\n';
	tablo[20] = '\0';

	tablo[1] = '#';
	tablo[5] = '#';
	tablo[6] = '#';
	tablo[7] = '#';

	ft_putstr(tablo);
	return (0);
}