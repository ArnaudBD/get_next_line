#include "get_next_line.h"

int		main()
{
	int		gnl;
	int		fd;
	char	*line[] = {""};

	fd = open("Nimon77/42cursus_gnl_tests/tests/normal/1.txt", O_RDONLY);


	while ((gnl = get_next_line(fd, line)) == 1)
	{
		printf("|GNL return is %d|\n", gnl);
		printf("|%s|\n", line[0]);
		free(line[0]);
	}
	printf("|GNL return is %d|\n", gnl);
	printf("|%s|\n", line[0]);
	close(fd);
}
