/*
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

char	**str_to_dstr(char *piece)
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
	while (y < n)
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
		x = str_to_dstr(tab[i]);
		for (int i = 0; x[i]; i++)
			ft_putstr(x[i]);
		ft_putchar('\n');
	}
}


void show_dstr(char **tab)
{
	int		y;
	int		x;
	int 	i;

	y = 0;
	x = 0;
	i = 0;
	while (i < 1)//(tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
	ft_putstr(tab[0]);
	ft_putchar('\n');
	ft_putstr(tab[1]);

}
*/
