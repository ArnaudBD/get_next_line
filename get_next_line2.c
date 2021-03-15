#include "get_next_line.h"

int		n_search(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	
	while (str[i] != '\n' && str[i] != 0)
	{
		write(1, "OK\n", 3);
		i++;
	}
	return (i);
}

char	*fill_the_line(char **line, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		*line[i] = str[i];
		i++;
	}
	*line[i] = 0;
	return (str = str + i + 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str + i)
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	int			i;
	int			nb;

	i = n_search(str);



//-----------------------------------------------------------------------------
	char	c;
	c = i + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
//-----------------------------------------------------------------------------



	while (i == 0)
	{
		if (!(str = malloc(sizeof(char) * (ft_strlen(str) + BUFFER_SIZE))))
			return (-1);
		if ((nb = read(fd, str, BUFFER_SIZE)) == 0 || nb < BUFFER_SIZE)
			return (-1);
																				printf("str = %s", str);
		i = n_search(str);
	}
	if (!(*line = malloc(sizeof(char) *(i + 1))))
		return (-1);
	str = fill_the_line(line, str);
	if (nb < BUFFER_SIZE)
		return (0);
	else
		return (1);
}


