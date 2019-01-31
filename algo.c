/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:31:37 by magrinbe          #+#    #+#             */
/*   Updated: 2019/01/31 23:05:21 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**algogo(char **tab, char *map)
{
	int i;
	int o;
	int j;
	int length;
	int start;
	int save;
	char *str;

	o = 0;
	length = 0;
	while (map[length] != '\n')
		length++;
	length++;
	while (tab[o])
	{
		i = 0;
		start = j;
		while (map[j])
		{
			while (map[j] == '.' && tab[o][i] != '\n')
				{
					map[j] = tab[o][i];
					j++;
					i++;
					if (map[j] == '#')
					{
						i = 0;
						map[j - 1] = '.';
						break;
					}
					else if (map[j] == '\n')
						{
							j++;
							map[j - 1] = '.';
							break;
						}
				}
			if (tab[o][i++] == '\n')
			{
				if (map[j] == '\n')
					j++;
				while ()
			}
			while (map[j] == '#' || map[j] == '\n')
				j++;
		}
}