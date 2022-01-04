#include "../includes/push_swap.h"

void	add_to_end(t_stack *a, long int val)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		ft_error();
	new->value = val;
	if (a->size > 0)
	{
		new->prev = a->last;
		new->next = a->first;
		a->first->prev = new;
		a->last->next = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		a->first = new;
	}
	a->last = new;
	a->size += 1;
}

void	add_to_top(t_stack *a, long val)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		ft_error();
	new->value = val;
	if (a->size > 0)
	{
		new->next = a->first;
		new->prev = a->last;
		a->first->prev = new;
		a->last->next = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		a->last = new;
	}
	a->first = new;
	a->size += 1;
}

long int	remove_from_top(t_stack *a)
{
	long int	val;
	t_elem	*tmp;

	tmp = a->first;
	if (a->size == 0)
		return (-1);
	val = tmp->value;
	if (a->size > 1)
	{
		a->first = tmp->next;
		a->last->next = a->first;
		a->first->prev = a->last;
	}
	else
	{
		a->first = NULL;
		a->last = NULL;
	}
	a->size -= 1;
	free(tmp);
	return	(val);
}
