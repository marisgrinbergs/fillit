/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tppower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:39:23 by magrinbe          #+#    #+#             */
/*   Updated: 2019/02/06 04:43:12 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	**tranform_line(char **tab)
{
	int i;
	int o;

	o = 0;
	while (tab[o])
	{
		i = 0;
		while (tab[o][i])
		{
			if (tab[o][i] == '.' && tab[o][i + 1] == '.'
				&& tab[o][i + 2] == '.' && tab[o][i + 3] == '.')
			{
				while (tab[o][i] == '.')
				{
					tab[o][i] = '?';
					i++;
				}
				i++;
			}
			else
				i = i + 5;
		}
		o++;
	}
	return (tab);
}

char	**tranform_colonne(char **tab)
{
	int i;
	int o;

	o = 0;
	while (tab[o])
	{
		i = 0;
		while (tab[o][i] != '\n')
		{
			if ((tab[o][i] == '.' || tab[o][i] == '?') && (tab[o][i + 5] == '.'
			|| tab[o][i + 5] == '?') && (tab[o][i + 10] == '.' || tab[o][i + 10]
			== '?') && (tab[o][i + 15] == '.' || tab[o][i + 15] == '?'))
			{
				tab[o][i] = '?';
				tab[o][i + 5] = '?';
				tab[o][i + 10] = '?';
				tab[o][i + 15] = '?';
			}
			i++;
		}
		o++;
	}
	return (tab);
}

int		ignore_empty_lines(char *str)
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
	- (ft_strlen(tab[o]) - ignore_empty_lines(tab[o])))
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
	(tab[o][l] == '?' && tab[o][l + 1] == '?' &&
	tab[o][l + 2] == '?' && tab[o][l + 3] == '?'))
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

char	**get_the_fuckin_piece(char **tab)
{
	int		i;
	int		o;
	int		j;
	char	str[11];

	o = 0;
	while (tab[o])
	{
		i = 0;
		j = 0;
		while (tab[o][i])
		{
			if (tab[o][i] != '?')
				str[j++] = tab[o][i];
			i++;
		}
		str[j] = '\0';
		ft_bzero(tab[o], 21);
		j = 0;
		i = 0;
		while (str[j])
			tab[o][i++] = str[j++];
		o++;
	}
	return (tab);
}


int			count_line(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

char		**stock_tab(char *str)
{
	int		i;
	int		j;
	int		o;
	char	**tab;

	i = 0;
	o = 0;
	tab = NULL;
	tab = (char **)malloc(sizeof(char *) * ((count_line(str) + 1) / 5) + 1);
	if (!str || !tab)
		return (NULL);
	while (o < ((count_line(str) + 1) / 5))
	{
		j = 0;
		tab[o] = (char*)malloc(sizeof(char) * 20 + 1);
		while (str[i] && (str[i] != '\n' || str[i - 1] != '\n'))
			tab[o][j++] = str[i++];
		if (str[i] == '\n' || str[i - 1] == '\n')
			i++;
		tab[o][j] = '\0';
		o++;
	}
	tab[o] = 0;
	return (tab);
}

void	ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}

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
	// o = ft_sqrt(nb_pieces(tab) * 4);
	o = 6;
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

char	**ft_dstrnew(int y, int x)
{
	char	**dstr;
	int		i;

	i = 0;
	dstr = (char **)malloc(sizeof(char *) * (y + 1));
	if (!dstr)
		return (NULL);
	i = 0;
	while (i < y)
	{
		dstr[i] = ft_strnew(x);
		i++;
	}
	dstr[i] = 0;
	return (dstr);
}

char	**converpiece(char *piece)
{
	int i = 0;
	int y = 0;
	int x = 0;
	int p;
	char **t;
	int n;

	n = (int)ft_strlen(piece) / 2;
	t = ft_dstrnew(n, n);

	i = 0;
	while (t[y])
	{	
		while (piece[i])
		{
			t[y][x] = piece[i]; 
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (t);
}

void show_everything(char **tab)
{
	char **x;

	for (int i = 0; tab[i]; i++)
	{
		x = converpiece(tab[i]);
		for (int i = 0; x[i]; i++)
			ft_putstr(x[i]);
		ft_putchar('\n');
	}
}

char	*algogo(char *map, char **tab)
{

	int i;
	int j;
	int o;
	int x;

	o = 0;
	j = 0;
	x = 0;

	
}




int		main(void)
{
	char *str;
	int fd;
	char **tab;

	str = (char*)malloc(sizeof(char) * 547);
	fd = open("test.txt", O_RDONLY);
	char	*map;

	map = create_map(tab);
	bzero(str, 547);
	read(fd, str, 546);
	tab = stock_tab(str);
	tranform_line(tab);
	tranform_colonne(tab);
	del_empty_line(tab);
	get_the_fuckin_piece(tab);
	//map = algogo(map, tab);

	show_everything(tab);

	//ft_print_words_tables(tab);
	//ft_putstr(map);
	return (0);
}