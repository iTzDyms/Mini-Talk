









#include <stdlib.h>
#include "../libft/includes/libft.h"

void	prompt(int pid, char *line);
void	ft_send_len(int pid, size_t len);

int		main(int argc, char **argv)
{
	int		pid;
	size_t	len;

	if (argc != 3)
		{
			ft_putendl("Invalid number of argument.");
			exit(0);
		}
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	ft_send_len(pid, len);
	prompt(pid, argv[2]);
	return (0);
}

