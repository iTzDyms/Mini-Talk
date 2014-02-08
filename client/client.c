









#include <stdlib.h>
#include "../libft/includes/libft.h"

void	prompt(int pid);

int		main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
		{
			ft_putendl("Invalid number of argument.");
			exit(0);
		}
	pid = ft_atoi(argv[1]);
	prompt(pid);
	return (0);
}
