/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:31:37 by magrinbe          #+#    #+#             */
/*   Updated: 2019/01/30 19:33:40 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
					if (map[j] != '.')
					{
						i = 0;
						exit;
					}
				}
			if (tab[o][i] == '\n')
			{
				i++;
				j = start + length;
				while ()
			}
			while (map[j] == '#' || map[j] == '\n')
				j++;
		}
}