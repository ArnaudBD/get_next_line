/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:07:46 by abiju-du          #+#    #+#             */
/*   Updated: 2021/03/08 15:57:57 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int fd;

	fd = open("alph", O_RDONLY);
	ft_putnbr_fd(fd, 1);
	close(fd);
	ft_putnbr_fd(fd, 1);
	return (0);
}
