#include "get_next_line.h"

int		main()
{
	int		i;
	int		fd;
	char	**line = NULL;

	fd = open("alph", O_RDONLY);
	i = 0;

	while ((printf("GNL = %d\n", get_next_line(fd, line)) > 0))
	{
		while (line[i])
		{
			printf("|%s|\n", line[i]);
			i++;
		}

	}
	close(fd);
}
