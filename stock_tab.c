/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:43:22 by magrinbe          #+#    #+#             */
/*   Updated: 2019/01/07 18:57:24 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		ft_strlenl(const char *str, char c[2])
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i - 1] == c[0] && str[i] == c[1] || i == 0)
		&& str[i] != c[0] && str[i] != c[1])
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit2(char const *s, char c[2])
{
	char	**tab;
	int		i;
	int		j;
	int		o;

	i = 0;
	o = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_strlenl(s, c[2]) + 1));
	if (!s || !tab)
		return (NULL);
	while (o < ft_strlenl(s, c))
	{
		j = 0;
		tab[o] = (char*)malloc(sizeof(char) * ft_strlen((char*)s));
		while (s[i] && s[i] != c[0] && s[i + 1] != c[1])
			tab[o][j++] = s[i++];
		while (s[i] && s[i] == c[0] && s[i + 1] == c[1])
			i++;
		tab[o][j] = '\0';
		o++;
	}
	tab[o] = 0;
	return (tab);
}