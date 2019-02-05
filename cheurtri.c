/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheurtri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:22:00 by magrinbe          #+#    #+#             */
/*   Updated: 2019/02/05 19:22:03 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_piece(char *map, char **tab_piece, int cote)
{
	int		i;
	int		piece;
	char	*save_map;

	save_map = cpy_map(map);
	piece = 0;
	i = 0;
	while (try_piece(map, tab_piece, piece, i) == 0)
	{
		ft_strcpy(map, save_map);
		i++;
		if (map[i + 1] == '\0')
		{
			cote++;
			free(map);
			if (!(map = (char*)malloc(sizeof(char) * (cote + 1) * cote + 1)))
				return (-1);
			fill_map(map, cote);
			save_map = cpy_map(map);
			i = 0;
		}
	}
	ft_putstr(map);
	return (1);
}

char	*cpy_map(char *map)
{
	char *cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * ft_strlen(map) + 1)))
		return (0);
	ft_strcpy(cpy, map);
	return (cpy);
}

int		next_line(char *map, int next_carac, int x_map, int line)
{
	int len;

	len = 0;
	line = 0;
	while (map[len] != '\0')
		len++;
	while (map[line] != '\n')
		line++;
	while (map[x_map] != '\n')
		x_map++;
	if (map[x_map] == '\n' && map[x_map + 1] != '\0')
	{
		while (next_carac < x_map)
			next_carac = next_carac + line + 1;
		if (next_carac < len)
			return (next_carac);
		else
			return (-1);
	}
	else
		return (-1);
}

int		try_piece(char *map, char **t, int piece, int x_map)
{
	int		first_carac;
	char	*save_map;
	int		i;

	i = 0;
	first_carac = x_map;
	save_map = cpy_map(map);
	while (t[piece] != 0 && t[piece][i] != '\0')
	{
		if (t[piece][i] != '.' && t[piece][i] != '\n')
		{
			if (map[x_map] != '.' && t[piece] && map[x_map])
				return (0);
			else
				map[x_map] = t[piece][i];
		}
		x_map++;
		i++;
		if (t[piece][i + 1] != '\0' && t[piece][i] == '\n')
			if ((x_map = next_line(map, first_carac, x_map, i++)) == -1)
				return (0);
		if (t[piece][i] == '\n' && t[piece][i + 1] == '\0' && t[++piece] != 0)
			return (try_nextplace(save_map, map, t, piece));
	}
	return (1);
}

int		try_nextplace(char *save_map, char *map, char **tab_piece, int piece)
{
	int pt;

	pt = -1;
	save_map = cpy_map(map);
	while (try_piece(map, tab_piece, piece, pt) == 0)
	{
		ft_strcpy(map, save_map);
		pt++;
		if (pt == -1 || map[pt + 1] == '\0')
			return (0);
	}
	return (1);
}