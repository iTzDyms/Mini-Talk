





typedef struct		s_dat
{
	char				c[2];
	int					i;
	char				*str;
}						t_dat;

typedef void (*t_handler)(int);
t_handler signal(int sig, t_handler func);
