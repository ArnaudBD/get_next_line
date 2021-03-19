/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:26:58 by abiju-du          #+#    #+#             */
/*   Updated: 2021/03/19 13:31:38 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

void	writing(int odg, int n, int fd)
{
	char	c;

	if (n == 0)
	{
		write(fd,"0",1);
		return ;
	}
	while (odg > 1)
	{
		odg = odg / 10;
		c = n / odg + '0';
		write(fd, &c, 1);
		n = n - (n / odg) * odg;
	}
	return ;
}

void	isminmax(int n, int fd)
{
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int			odg;
	long int	nb;

	odg = 1;
	nb = n;
	if (n == 2147483647 || n == -2147483648)
	{
		isminmax(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (nb != 0 && odg != 0)
	{
		odg = odg * 10;
		nb = n;
		nb = nb / odg;
	}
	writing(odg, n, fd);
	return ;
}

int             ft_strlen(const char *s)
{
	int     i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s1 == NULL)
	{
		while (s2)
		{
			str[i] = s2[i];
			i++;
		}
		str[i] = 0;
		return (str);
	}
	if (s2 == NULL)
	{
		while (s1)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = 0;
		return (str);
	}
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i <= len)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[len] = 0;
	return (str);
}


