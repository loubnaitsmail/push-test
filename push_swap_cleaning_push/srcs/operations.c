#include "../includes/push_swap.h"

/*
		old_first->next = new_first->next;
		tmp->next->prev = a->first;
		tmp->next = a->first;
		
		a->first = tmp;
		a->first->prev = a->last;
		a->first->next->prev = a->first;
		a->first->next->next->prev = a->first->next;
*/
//sa : swap a - swap the first 2 elements at the top of stack a
void	ft_sa(t_stack *a)
{
	t_elem	*new_first;
	t_elem	*old_first;
	t_elem	*third_elem; // can be the first if size == 2
	t_elem	*last_elem; // can be the first if size == 2

	if (a->size > 1)
	{
		old_first = a->first;
		new_first = a->first->next;
		third_elem = a->first->next->next;
		last_elem = a->last;

		new_first->next = old_first;
		old_first->prev = new_first;
		old_first->next = third_elem;
		third_elem->prev = old_first;
		last_elem->next = new_first;
		new_first->prev = last_elem;
		a->first = new_first;
		if (a->size == 2)
			a->last = old_first;
	}
	ft_putstr("sa\n");
}

//sb : swap b - swap the first 2 elements at the top of stack b.
void	ft_sb(t_stack *a)
{
	t_elem	*new_first;
	t_elem	*old_first;
	t_elem	*third_elem; // can be the first if size == 2
	t_elem	*last_elem; // can be the first if size == 2

	if (a->size > 1)
	{
		old_first = a->first;
		new_first = a->first->next;
		third_elem = a->first->next->next;
		last_elem = a->last;

		new_first->next = old_first;
		old_first->prev = new_first;
		old_first->next = third_elem;
		third_elem->prev = old_first;
		last_elem->next = new_first;
		new_first->prev = last_elem;
		a->first = new_first;
		if (a->size == 2)
			a->last = old_first;
	}
	ft_putstr("sb\n");
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
	}
	ft_putstr("pa\n");
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
	ft_putstr("pb\n");
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
	ft_putstr("ra\n");
}
