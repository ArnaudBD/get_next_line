/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:38:30 by abiju-du          #+#    #+#             */
/*   Updated: 2021/04/13 15:47:22 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int			i;

	if (s == NULL || *s == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	char		*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if (dst == src)
		return (dst);
	if (src_cpy < dst_cpy)
	{
		while (len--)
			*(dst_cpy + len) = *(src_cpy + len);
		return (dst);
	}
	else
	{
		while (len--)
			*dst_cpy++ = *src_cpy++;
	}
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*str_join;
	size_t		s1_len;
	size_t		s2_len;
	size_t		s_len;

	if (s1 == NULL && s2 == NULL)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	s_len = s1_len + s2_len;
	if (!(str_join = malloc(sizeof(*str_join) * s_len + 1)))
		return (0);
	ft_memmove(str_join, s1, s1_len);
	ft_memmove(str_join + s1_len, s2, s2_len);
	str_join[s_len] = '\0';
	free((char *)s1);
	return (str_join);
}

char	*mv_next_line(char **line, char *str)
{
	int			i;

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

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;

	if ((bytes_read = BUFFER_SIZE) < 1 || !line || fd < 0
			|| read(fd, buf, 0) != 0)
		return (-1);
	while (n_search(str) == -1 && bytes_read != 0)
	{
		if ((bytes_read = read(fd, buf, BUFFER_SIZE)) <= 0)
			if (bytes_read == -1)
			{
				line[0] = malloc(1);
				line[0] = 0;
				return (-1);
			}
		buf[bytes_read] = 0;
		str = ft_strjoin(str, buf);
	}
	if (mv_first_line(str, line) == -1)
		return (-1);
	str = sup_first_line(str);
	if (bytes_read <= 0)
		return (bytes_read);
	return (1);
}
