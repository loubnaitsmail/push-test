#include "../includes/push_swap.h"

void	add_s_to_top(t_stack *a, long val)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		ft_error();
	new->value = val;
	if (a->size > 0)
	{
		new->next = a->first;
		new->prev = NULL;
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

long	remove_s_from_top(t_stack *a)
{
	long val;
	t_elem	*tmp;

	tmp = a->first;
	if (!tmp)
		return (-1);
	val = tmp->value;
	if (tmp->next)
		a->first = tmp->next;
	else
	{
		a->first = NULL;
		a->last = NULL;
	}
	free(tmp);
	a->size--;
	return	(val);
}

void		ft_pa_s(t_stack *a, t_stack *b)
{
	long value;
	if (b->size > 0)
	{
		value = remove_s_from_top(b);
		add_s_to_top(a, value);
	}
	ft_putstr("pa_s\n");
}

void		ft_ra_s(t_stack *a)
{
	t_elem	*tmp;
	t_elem *head;
	int	i;

	if (a->first && a->first->next)
	{
		i = 0;
		tmp = a->first;
		a->first = a->first->next;
		head = a->first;
		tmp->next = NULL;
		while (i < a->size)
		{
			a->first = a->first->next;
			i++;
		}
		a->first->next = tmp;
		a->first = head;
	}
	ft_putstr("ra_s\n");
}

void		ft_rra_s(t_stack *a)
{
	t_elem	*head;
	t_elem	*tmp;
	int	i;

	if (a->first && a->first->next)
	{
		head = a->first;
		i = 0;
		while (i < a->size)
		{
			a->first = a->first->next;
			i++;
		}
		tmp = a->first->next;
		a->first->next = NULL;
		a->first = head;
		tmp->next = a->first;
		a->first = tmp;
	}
	ft_putstr("rra_s\n");
}

// tri une list de 3 
void	very_small_sort(t_stack *a)
{
	int top;
	int mid;
	int	end;
	
	top = a->first->value;
	mid = a->first->next->value;
	end = a->last->value;

	if (top > mid && mid < end && end > top)
		ft_sa(a);
	else if  (top > mid && mid > end && end < top)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if  (top > mid && mid < end && end < top)
		ft_ra(a);
	else if  (top < mid && mid > end && end > top)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if  (top < mid && mid > end && end < top)
		ft_rra(a);
}

//tri pas encore la liste de 5
void small_sort(t_stack *a, t_stack *b)
{
	//Divise en 2
	while (a->size > 3)
		ft_pb(a, b);
	//sort list de 3
	very_small_sort(a);
	//print_stacks(a, b);
	//put b -> a sorted
	while (b->size > 0)
		push_a_sorted(a, b);
}
