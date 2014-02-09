









#include <stdlib.h>
#include <signal.h>
#include "../libft/includes/libft.h"

void	prompt(int pid, char *line);
//void	ft_send_len(int pid, size_t len);
static void		handler(int sig);

int		main(int argc, char **argv)
{
	int		pid;
	//	size_t	len;

	if (argc != 3)
		{
			ft_putendl("Invalid number of argument.");
			exit(0);
		}
	signal(SIGUSR2, handler);
	pid = ft_atoi(argv[1]);
	//	len = ft_strlen(argv[2]);
	//	ft_send_len(pid, len);
	prompt(pid, argv[2]);
	return (0);
}

static void		handler(int sig)
{
	if (sig == 0)
		return ;
	return ;
}
