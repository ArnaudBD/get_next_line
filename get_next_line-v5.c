#include "get_next_line.h"
/*
static int n_search2(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
*/

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
	if ((bytes_read = BUFFER_SIZE) < 1 || !line || fd < 0 || read(fd, buf, 0) != 0)
		return (-1);

	// while (n_search2(str) == 0 && bytes_read != 0)
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
			// break;
		}
		// printf("GO HERE\n");
		buf[bytes_read] = 0;
		str = ft_strjoin(str, buf);
			// printf("GO HERE\n");

	}
	if (mv_first_line(str, line) == -1)
		return (-1);
	str = sup_first_line(str);
	// if (n_search2(str) != 0)
	// 	free(str);
	if (bytes_read <= 0)
	{
		str = NULL;
		return (bytes_read);
	}
	return (1);
}
