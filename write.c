/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:14:13 by abiju-du          #+#    #+#             */
/*   Updated: 2021/03/09 16:10:45 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

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
}

int		main()
{
	int fd;

	fd = open("alph", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr_fd("open() error\n", 1);
		return (1);
	}
	ft_putnbr_fd(fd, 1);
	ft_putstr_fd("Hello World!\n", fd);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() error\n", 1);
		return (1);
	}
	return (0);
}
