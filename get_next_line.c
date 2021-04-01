#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*str;
	char			*buf;
	int				i;
	int				len;
	int				nb;

	if (str && str[0] == EOF)
		return (0);
	if (str)
		len = ft_strlen(str);
	else
		len = BUFFER_SIZE;
	i = n_search(str, len);
	nb = BUFFER_SIZE;

	while (i == -1)
	{
		if (!(buf = malloc(sizeof(char**) * (BUFFER_SIZE + 1))))
			return (-1);
		if (!(nb = read(fd, buf, BUFFER_SIZE)))
			return (-1);
		len = ft_strlen(str) + nb;
		if (str)
			str = ft_strjoin(str, buf);
		else
		{
			if (!(str = malloc(sizeof(char*) * nb + 1)))
				return (-1);
			str = buf;
			str[nb] = 0;
		}
		i = n_search(str, len);
	}
	if (nb < BUFFER_SIZE)
		str[ft_strlen(str)] = EOF;
	if (!(line[0] = malloc(sizeof(char**) * i + 1)))
		return (-1);
	str = mv_next_line(line, str);
	return (1);
}
