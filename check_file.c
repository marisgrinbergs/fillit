/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:59:06 by magrinbe          #+#    #+#             */
/*   Updated: 2019/01/03 22:17:38 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_line(char *str)
{
	int i;
	int n;
	int c;

	i = 0;
	n = 0;
	c = 1;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			n++;
		else if (str[i] == '\n' && str[i - 1] == '\n')
			c++;
		i++;
	}
	if ((str[i - 1] == '\n' && str[i - 2] == '\n') || c > 26)
		return (0);
	if (n == c * 4)
		return (1);
	return (0);
}

int		check_carac(char *str)
{
	int i;
	int c;
	int n;

	i = 0;
	c = 0;
	n = 1;
	while (str[i] && (str[i] == '.' || str[i] == '\n' || str[i] == '#'))
	{
		if (str[i] && (str[i] == '.' || str[i] == '\n'))
			i++;
		if (str[i] == '#')
		{
			c++;
			i++;
		}
		if (str[i] == '\n' && str[i - 1] == '\n')
		{	
			if (c != n * 4)
				return (0);
			n++;
		}
	}
	if (c == n * 4)
		return (1);
	return (0);
}
