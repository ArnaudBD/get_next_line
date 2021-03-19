#include "get_next_line.h"

int		n_search(char *str)
{
	int i;

	if (str == NULL)
		return (-1);
	i = 0;
	
	while (str[i] != '\n' && str[i] != 0 && i <= BUFFER_SIZE)
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

char	*fill_the_line(char **line, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		line[0][i] = str[i];
		i++;
	}
	line[0][i] = 0;
	return (str = str + i + 1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			i;
	int			nb;
	int			len;

	i = n_search(str);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
	while (i == -1)
	{
		if ((nb = read(fd, buf, BUFFER_SIZE)) == 0 || nb < BUFFER_SIZE)
			return (-1);
		buf[BUFFER_SIZE] = 0;
		len = ft_strlen(str) + nb;
		if (!(str = malloc(sizeof(char) * (len))))
			return (-1);
		str = ft_strjoin(str, buf);
		i = n_search(str);
	}
	if (!(line[0] = malloc(sizeof(char) * (i + 1))))
		return (-1);
	str = fill_the_line(line, str);
	if (nb < BUFFER_SIZE && i == ?)
		return (0);
	else
		return (1);
}
