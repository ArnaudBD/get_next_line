#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			bytes_read;

	bytes_read = BUFFER_SIZE;
	while (n_search(str) == -1 && bytes_read != 0)
	{
		if(!(buf = malloc(BUFFER_SIZE + 1)))
			return (-1);
		if ((bytes_read = read(fd, buf, BUFFER_SIZE)) == 0
				|| bytes_read == -1)
		{
			free(buf);
			if (bytes_read == -1)
				return (-1);
			break;
		}
		else
			buf[BUFFER_SIZE] = 0;
		str = ft_strjoin(str, buf);
		free(buf);
	}
	if (mv_first_line(str, line) == -1)
		return (-1);
	str = cut_first_line(str);
	if (bytes_read == 0)
		return (0);
	return (1);
}
