#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*str;
	char			*buf;
	int				i;
	int				len;
	int				nb;

	if (str)
		len = ft_strlen(str);
	else
		len = BUFFER_SIZE;
	nb = BUFFER_SIZE;
	i = n_search(str, len, nb);

	while (i == -1)
	{
																				printf("1\n");
		if (!(buf = malloc(sizeof(char**) * (BUFFER_SIZE + 1))))
			return (-1);
		(nb = read(fd, buf, BUFFER_SIZE));
		buf[nb] = 0;
		if (str)
			str = ft_strjoin(str, buf);
		else
		{
			if (!(str = malloc(sizeof(char*) * nb + 1)))
				return (-1);
			str = buf;
			str[nb] = 0;
		}
		i = n_search(str, len, nb);
	}
	if (!(line[0] = malloc(sizeof(char**) * i + 1)))
		return (-1);
	str = mv_next_line(line, str);
	if (((ft_strlen(str) == 0) && (nb < BUFFER_SIZE)) || str[0] == EOF)
		return (0);
	return (1);
}
