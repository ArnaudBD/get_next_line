/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:56:28 by abiju-du          #+#    #+#             */
/*   Updated: 2021/03/10 13:12:49 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUF_SIZE 40

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_fd(fd, s[i]);
		i++;
	}
	write(1, "\n", 1);
}

int		main()
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open("alph", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() error", 1);
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = 0;
		ft_putnbr_fd(ret, 1);
		write(1, "\n", 1);
		ft_putstr_fd(buf, 1);
	}
//	buf[ret] = 0;
//	ft_putnbr_fd(ret, 1);
	write(1, "\n", 1);
//	ft_putstr_fd(buf, 1);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() error", 1);
		return (1);
	}
	return (0);
}
