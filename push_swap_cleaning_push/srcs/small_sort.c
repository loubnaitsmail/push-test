#include "../includes/push_swap.h"

void	small_sort(t_stack *a, t_stack *b)
{
	printf("small_sort\n");

	int top;
	int mid;
	int	end;
	
	top = a->first->value;
	mid = a->first->next->value;
	end = a->last->value;

	if (top > mid && mid < end && end > top)
	{
		ft_sa(a);
		write(1, "sa\n", 3);
	}
	else if  (top > mid && mid > end && end < top)
	{
		ft_sa(a);
		write(1, "sa\n", 3);
		print_stack(a);
		ft_rra(a);
		write(1, "rra\n", 4);
		print_stack(a);
	}
	else if  (top > mid && mid < end && end < top)
	{
		ft_ra(a);
		write(1, "ra\n", 3);
	}
	else if  (top < mid && mid > end && end > top)
	{
		ft_sa(a);
		write(1, "sa\n", 3);
		ft_ra(a);
		write(1, "ra\n", 4);
	}
	else if  (top < mid && mid > end && end < top)
	{
		ft_rra(a);
		write(1, "rra\n", 4);
	}
}
