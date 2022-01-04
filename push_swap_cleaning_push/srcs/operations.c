#include "../includes/push_swap.h"

extern int SCORE_FINAL;

//sa : swap a - swap the first 2 elements at the top of stack a
void	ft_sa(t_stack *a)
{
	t_elem	*tmp;

	if (a->size > 1)
	{
		tmp = a->first->next;
		a->first->next = a->first->next->next;
		tmp->next = a->first;
		a->first = tmp;
	}
}

//sb : swap b - swap the first 2 elements at the top of stack b.
void	ft_sb(t_stack *b)
{
	t_elem	*tmp;

	if (b->size > 1)
	{
		tmp = b->first->next;
		b->first->next = b->first->next->next;
		tmp->next = b->first;
		b->first = tmp;
	}
}

//ss : sa and sb at the same time
void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
}

//pa : push a - take the first element at the top of b  and put it at the top of a
void	ft_pa(t_stack *a, t_stack *b)
{
	long int	value;

	if (b != NULL && b->size > 0)
	{
		value = remove_from_top(b);
		add_to_top(a, value);
		ft_putstr("pa\n");
	}
}

//pb : push b - take the first element at the top of a and put it at the top of b.
void	ft_pb(t_stack *a, t_stack *b)
{
	long int	value;

	if (a != NULL && a->size > 0)
	{
		value = remove_from_top(a);
		add_to_top(b, value);
	}
}

//ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
void	ft_ra(t_stack *a)
{
	t_elem	*tmp;

	if (a->size > 1)
	{
		tmp = a->first;
		a->first = a->first->next;
		a->last = tmp;
	}
}
