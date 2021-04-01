#include "get_next_line.h"

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
	nb = BUFFER_SIZE;
	i = n_search(str, len);

	while (i == -1)
	{
		if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		if ((nb = read(fd, buf, BUFFER_SIZE)) == 0)
		{
			if (!(line[0] = malloc(sizeof(char) * (i + 1))))
			return (-1);
			str = mv_next_line(line, str);
			return (0);
		}
		buf[nb] = '\0';
		len = ft_strlen(str) + nb;
		if (!(temp = malloc(sizeof(char) * (len - nb))))
			return (-1);
		if (str != NULL)
			while (str[j])
			{
				temp[j] = str[j];
				j++;
			}
		temp[j] = 0;
		j = 0;
		if (!(str = malloc(sizeof(char) * (len))))
			return (-1);
		str = ft_strjoin(temp, buf);
		free(buf);
		i = n_search(str, len);
	}
	if (!(line[0] = malloc(sizeof(char) * (i + 1))))
		return (-1);
	str = mv_next_line(line, str);
	if ((nb < BUFFER_SIZE && i == nb - 1) || (line[0][ft_strlen(str)] == EOF))
		return (0);
	else
		return (1);
}
