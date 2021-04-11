/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:26:58 by abiju-du          #+#    #+#             */
/*   Updated: 2021/04/11 16:32:59 by abiju-du         ###   ########.fr       */
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

	if (s == NULL || *s == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *str;
	size_t    i;
	size_t    j;

	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2 != NULL && s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
/*
   char    *ft_strjoin(char const *s1, char const *s2)
   {
   int		len;
   int		i;
   int		j;
   char	*string;

   i = 0;
   j = 0;
   len = ft_strlen(s1) + ft_strlen(s2);
   if (!(string = malloc(sizeof(char) * len + 1)))
   return (NULL);
   if (!*s1)
   {
   while (s2[i])
   {
   string[i] = s2[i];
   i++;
   }
   string[i] = 0;
   return (string);
   }
   if (!*s2)
   {
   while (s1[i])
   {
   string[i] = s1[i];
   i++;
   }
   string[i] = 0;
   return (string);
   }
   while (i < ft_strlen(s1))
   {
   string[i] = s1[i];
   i++;
   }
   while (i <= len)
   {
   string[i] = s2[j];
   i++;
   j++;
   }
   string[len] = 0;
   return (string);
   }
   */
char	*mv_next_line(char **line, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != 0 && str[i] != EOF)
	{
		line[0][i] = str[i];
		i++;
	}
	if (str[i] == EOF)
		line[0][i + 1] = EOF;
	line[0][i] = 0;
	return (str = str + i + 1);
}

int		n_search(char *str)
{
	int i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

int		mv_first_line(char *str, char **dest)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		dest[0] = malloc(1);
		dest[0][0] = 0;
		return (0);
	}
	while (str[i] != '\n' && str[i] != 0 && str[i] != EOF)
		i++;
	if (!(dest[0] = malloc(sizeof(char) * i + 1)))
		return (-1);
	dest[0][i--] = 0;
	while (i >= 0)
	{
		dest[0][i] = str[i];
		i--;
	}
	return (1);
}

char	*cut_first_line(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i] != 0 && str[i] != EOF)
		i++;

	if(!(new_str = malloc(ft_strlen(str) - i)))
		return (0);
	new_str = str + i + 1;
	//	if (str)
	//		free(str);
	return (new_str);

	//	return (str + i + 1);
}

char	*sup_first_line(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str = NULL;

	i = 0;
	j = 0;
	if (str == NULL || *str == 0 || *str == EOF)
		return (0);
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if ((len = ft_strlen(str) - i - 1) >= 0)
	{
		if (!(new_str = malloc(sizeof(*new_str) * len + 1)))
			return (0);
		//	new_str[ft_strlen(str) - i] = 0;
		i++;
		while (j < len)
		{
			new_str[j] = str[i];
			i++;
			j++;
		}
		new_str[j] = 0;
	}
	free(str);
	return (new_str);
}
