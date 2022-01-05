#include "../includes/push_swap.h"

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
	ft_putstr("ra\n");
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
	ft_putstr("rra\n");
}


void	very_small_sort(t_stack *a)
{
	int top;
	int mid;
	int	end;
	
	top = a->first->value;
	mid = a->first->next->value;
	end = a->last->value;

	if (top > mid && mid < end && end > top)
	{
		ft_sa(a);
		ft_putstr("sa\n");
	}
	else if  (top > mid && mid > end && end < top)
	{
		ft_sa(a);
		ft_putstr("sa\n");
		ft_rra_s(a);
	}
	else if  (top > mid && mid < end && end < top)
	{
		ft_ra(a);
		ft_putstr("ra\n");
	}
	else if  (top < mid && mid > end && end > top)
	{
		ft_sa(a);
		ft_putstr("sa\n");
		ft_ra_s(a);
	}
	else if  (top < mid && mid > end && end < top)
	{
		ft_rra(a);
		ft_putstr("rra\n");
	}
}


void small_sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		ft_pb(a, b);
		ft_putstr("pb\n");
	}
	very_small_sort(a);
	/*while (b->size > 0)
	{
		ft_pa(a, b);
		ft_putstr("pa\n");
	}
	tri_version(a, b);*/

	while (b->size > 0)
	{
		printf("b->first %ld a->first %ld b->first %ld a->last %ld\n", b->first->value, a->first->value, b->first->value, a->last->value);
		if (b->first->value < a->first->value)
		{
			printf("cas 1\n");
			ft_pa(a, b);
			ft_putstr("pa\n");
			print_stacks(a, b);
		}
		else if (b->first->value > a->first->value && b->first->value > a->last->value)
		{
			printf("cas 2\n");
			ft_pa(a, b);
			ft_putstr("pa\n");
			print_stacks(a, b);
			ft_ra(a);
			ft_putstr("ra\n");
			print_stacks(a, b);
		}
		else if (b->first->value > a->first->value && b->first->value < a->last->value)
		{
			printf("cas 3\n");
			while (b->first->value > a->first->value && b->first->value < a->last->value)
			{
				printf("cas 3.1\n");
				ft_rra(a);
				ft_putstr("rra\n");
				print_stacks(a, b);
				a->first = a->first->next;
			}
			while (b->size > 1)
			{
				ft_pa(a, b);
				//ici bordel de circulaire
				ft_putstr("pa\n");
				print_stacks(a, b);
			}
			
			while (a->first->value > a->last->value)
			{
				printf("cas 3.2\n");
				ft_ra(a);
				ft_putstr("ra\n");
				print_stacks(a, b);
			}
		}
	}
}