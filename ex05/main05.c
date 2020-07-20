#include "ft_stock_str.h"
#include "../ex04/ft_strs_to_tab.c"
#include "../ex05/ft_show_tab.c"

int main(int ac, char **av)
{
	t_stock_str *tab;

	tab = ft_strs_to_tab(ac, av);
	ft_show_tab(tab);
	return 0;
}
