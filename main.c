#include "minignl.h"
#include "minignl_priv.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*b;

	i = 1;
	fd = open("../cube3d/test.cub", O_RDONLY);
	while (b = get_next_line(fd), b)
	{
		printf("%d:\"%s\"\n", i++, b);
		free(b);
	}
	close(fd);
}
