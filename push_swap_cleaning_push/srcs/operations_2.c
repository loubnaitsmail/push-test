#include "../includes/push_swap.h"

//rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
void	ft_rb(t_stack *b)
{
	t_elem	*tmp;

	if (b->first && b->first->next)
	{
		tmp = b->first;
		b->first = b->first->next;
		b->last = tmp;
	}
}

//rr : ra and rb at the same time.
void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}

//rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
void	ft_rra(t_stack *a)
{
	t_elem	*tmp;
	if (a->first && a->first->next)
	{
		tmp = a->last;
		a->last = a->last->prev;
		a->first = tmp;
	}
}

//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
void	ft_rrb(t_stack *b)
{
	t_elem	*tmp;

	if (b->first && b->first->next)
	{
		tmp = b ->last;
		b->last = b->last->prev;;
		b->first = tmp;
	}
}

//rrr : rra and rrb at the same time.
void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}
