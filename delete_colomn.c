/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_colomn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:56:21 by magrinbe          #+#    #+#             */
/*   Updated: 2019/01/17 17:38:34 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			count_pts(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '#')
		i--;
	while (str[i] != '\n')
		i++;
	return (i);
}

char		**swap_line(char **tab, int i, int j, int o)
{
	char str[20];

	while (tab[o][i] && i <= ft_strlen(tab[o])
	- (ft_strlen(tab[o]) - count_pts(tab[o])))
		str[j++] = tab[o][i++];
	str[j] = '\0';
	ft_bzero(tab[o], 21);
	j = 0;
	i = 0;
	while (str[j])
		tab[o][i++] = str[j++];
	return (tab);
}

void		check_dots(char **tab, int i, int j, int o)
{
	int l;

	l = 0;
	while ((i == 0 || i == 5) &&
	(tab[o][l] == '.' && tab[o][l + 5] == '.' &&
	tab[o][l + 10] == '.' && tab[o][l + 15] == '.'))
	{
		while (tab[o][l] != '\n')
			l++;
		l++;
		i = l;
	}
	tab = swap_line(tab, i, j, o);
}

char		**del_empty_line(char **tab)
{
	int		i;
	int		j;
	int		o;
	int		l;
	char	str[21];

	o = 0;
	while (tab[o])
	{
		l = 0;
		while (tab[o][l])
		{
			i = 0;
			j = 0;
			check_dots(tab, i, j, o);
			l++;
		}
		o++;
	}
	return (tab);
}
