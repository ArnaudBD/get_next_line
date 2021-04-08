#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;

	if ((bytes_read = BUFFER_SIZE) < 1)
		return (-1);
	while (n_search(str) == -1 && bytes_read != 0)
	{
		if ((bytes_read = read(fd, buf, BUFFER_SIZE)) <= 0)
		{
			if (bytes_read == -1)
			{
				line[0] = malloc(1);
				line[0] = 0;
				return (-1);
			}
			break;
		}
		else
			buf[bytes_read] = 0;
		str = ft_strjoin(str, buf);
	}
	if (mv_first_line(str, line) == -1)
		return (-1);
	str = cut_first_line(str);
	if (bytes_read <= 0)
	{
		str = NULL;
		return (bytes_read);
	}
	return (1);
}
