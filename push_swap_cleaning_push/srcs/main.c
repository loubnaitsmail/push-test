#include "../includes/push_swap.h"



void	print_reverse_stack(t_stack *a)
{
	t_elem	*actuel;
	int size;

	size = 0;
	actuel = a->last;
	printf("<< ");
	while (size < a->size)
	{
		printf("%2ld ", actuel->value);
		actuel = actuel->prev;
		size ++;
	}
	printf(" >>\n");
}




void	print_stack(t_stack *a)
{
	t_elem	*actuel;
	int size;

	size = 0;
	actuel = a->first;
	printf("<< ");
	while (size < a->size)
	{
		printf("%2ld ", actuel->value);
		actuel = actuel->next;
		size ++;
	}
	printf(" >>\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("stack A : ");
	print_stack(a);
	printf("stack B : ");
	print_stack(b);
}

void	init_stack(t_stack *a, t_stack *b)
{
	a->first = NULL;
	a->last = NULL;
	a->size = 0;
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
}

long	parse(char *str)
{
	int	i;
	long long 	num;

	i = 0;
	if (!str)
		return 0;
	if (!ft_isblank(str[i]) && !ft_isdigit(str[i]) 
		&& str[i] != '+' && str[i] != '-' && str[i] != '\0')
		ft_error();
 	if (ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]) 
	&& !ft_isblank(str[i + 1]) && str[i + 1] != '\0')
		ft_error();
 	if ((str[i] == '+' || str[i] == '-')
		&& !ft_isdigit(str[i + 1]) && str[i + 1] != '\0')
		ft_error();
	num = ft_atoill(&str[i]);
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	return (num);
}
 
void	build_stack(t_stack *a, int ac, char **av)
{
	int	i;
	long	num;

	i = 1;
	while (i < ac)
	{
		num = parse(av[i]);
		add_to_end(a, num);
		i++;
	}
	if (!(check_double(a)))
		ft_error();
	if (i - 1 != a->size)
		ft_error();;
}

int	sorted(t_stack *a)
{
	t_elem	*tmp;
	int i;

	i = 0;
	tmp = a->first;
	while (i < a->size - 1)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return(0);
	init_stack(&a, &b);
	build_stack(&a, ac, av);

	//printf("start\n");
	//print_stacks(&a, &b);

	if (a.size < 2)
		return (0);
	else if (sorted(&a))
		return (0);
	else if (a.size == 3) 
		very_small_sort(&a);
	else if (a.size == 5)
		small_sort(&a, &b);
	else
		tri_version(&a, &b);
	
	//printf("finish\n");
	//print_stacks(&a, &b);
	return(0);

}
