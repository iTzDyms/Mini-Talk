









#include <stdlib.h>
#include "../libft/includes/libft.h"

void	prompt(int pid, char *line);

int		main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		{
			ft_putendl("Invalid number of argument.");
			exit(0);
		}
	pid = ft_atoi(argv[1]);
	prompt(pid, argv[2]);
	return (0);
}
