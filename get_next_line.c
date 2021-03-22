#include "get_next_line.h"

int		n_search(char *str, int len)
{
	int i;

	if (str == NULL || str[0] == 0)
		return (-1);
	i = 0;
	
	while (str[i] != '\n' && str[i] != 0 && i < len)
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
	char		*temp;
	int			i;
	int			j;
	int			nb;
	int			len;

	j = 0;
	len = BUFFER_SIZE;
	i = n_search(str, len);
	while (i == -1)
	{
		if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		if ((nb = read(fd, buf, BUFFER_SIZE)) == 0)
			return (0);
		buf[nb] = '\0';
		len = ft_strlen(str) + nb;
		if (!(temp = malloc(sizeof(char) * ft_strlen(str))))
			return (-1);
		if (str != NULL)
			while (str[j])
			{
				temp[j] = str[j];
				j++;
			}
		temp[j] = 0;
		if (!(str = malloc(sizeof(char) * (len))))
			return (-1);
		str = ft_strjoin(temp, buf);
		free(buf);
		i = n_search(str, len);
	}
	if (!(line[0] = malloc(sizeof(char) * (i + 1))))
		return (-1);
	str = fill_the_line(line, str);
	if (nb < BUFFER_SIZE && i == nb - 1)
		return (0);
	else
		return (1);
}
