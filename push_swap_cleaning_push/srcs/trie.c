#include "../includes/push_swap.h"

int	is_extrem(long int value, t_stack *p)
{
	long int	min;
	long int	max;
	int	size;

	size = 0;
	min = p->first->value;
	max = p->first->value;
	while (size < p->size)
	{
		if (p->first->value > max)
			max = p->first->value;
		else if (p->first->value < min)
			min = p->first->value;
		p->first = p->first->next;
		size ++;
	}
	if (value < min)
		return (-1);
	else if (value > max)
		return (1);
	else
		return (0);
}

//find nbr of rotations  for extrem value
int	find_closet_extrem(t_elem *by_next, t_elem *by_previous)
{
	int	score;

	score = 0;
	while (!(by_next->prev->value < by_next->value
			|| by_previous->prev->value < by_previous->value))
	{
		by_next = by_next->next;
		by_previous = by_previous->prev;
		score++;
	}
	if (by_next->prev->value < by_next->value)
		return (score);
	else
		return (-1 * score);
}

//find nbr of rotations 
int	find_closet(long int value, t_stack *p)
{
	t_elem	*by_next;
	t_elem	*by_previous;
	int		score;
	int		extrem;

	score = 0;
	by_next = p->first;
	by_previous = p->first;
	extrem = is_extrem(value, p);
	if (extrem == 0)
	{
		while ((value < by_next->value || value > by_next->prev->value) &&
			(value < by_previous->value || value > by_previous->prev->value))
		{
			by_next = by_next->next;
			by_previous = by_previous->prev;
			score++;
		}
		if (value > by_next->value && value < by_next->prev->value)
			return (score);
		else
			return (-1 * score);
	}
	else
		return (find_closet_extrem(by_next, by_previous));
}

//rotate b for extrem value
void	rotate_b_extrem(int sens_rotation, t_stack *b)
{
	while (b->last->value > b->first->value)
	{
		if (sens_rotation > 0)
		{
			ft_rb(b);
			write(1, "rb\n", 3);
		}
		else
		{
			ft_rrb(b);
			write(1, "rrb\n", 4);
		}
	}
}

//rotate b and put value in it (remove SCORE_ATTENDU)
void	push_b_sorted(t_stack *a, t_stack *b)
{
	int value;
	int sens_rotation;
	int extrem;

	if (b->size < 2)
	{
		ft_pb(a, b);
		write(1, "pb\n", 3);
		return;
	}
	value = a->first->value;
	sens_rotation = find_closet(value, b);
	extrem = is_extrem(value, b);
	if (extrem == 0)
	{
		while (!(value > b->first->value && value < b->last->value))
		{
			if (sens_rotation > 0)
			{
				ft_rb(b);
				write(1, "rb\n", 3);
			}
			else
			{
				ft_rrb(b);
				write(1, "rrb\n", 4);
			}
		}
	}
	else
		rotate_b_extrem(sens_rotation, b);
	ft_pb(a, b);
	write(1, "pb\n", 3);
}

//find the elem with minimun rotation (orientation->previous)
int count_rrotate(t_stack *a, t_stack *b)
{
	int min_score;
	int rr_count;
	int current_count;
	int tmp_count;
	t_elem *elem;

	rr_count = 0;
	current_count = 0;
	elem = a->first;
	min_score = ft_abs(find_closet(elem->value, b));
	while (current_count < min_score && current_count < a->size)
	{
		tmp_count = ft_abs(find_closet(elem->value, b));
		if (tmp_count + current_count < min_score)
		{
			min_score = tmp_count + current_count;
			rr_count = current_count;
		}
		current_count ++;
		elem = elem->prev;
	}
	return (rr_count);
}

//find the elem with  minimun rotation (orientation->next)
int	count_rotate(t_stack *a, t_stack *b)
{
	int min_score;
	int r_count;
	int current_count;
	int tmp_count;
	t_elem *elem;

	r_count = 0;
	current_count = 0;
	elem = a->first;
	min_score = ft_abs(find_closet(elem->value, b));
	while (current_count < min_score && current_count < a->size)
	{
		tmp_count = ft_abs(find_closet(elem->value, b));
		if (tmp_count + current_count < min_score)
		{
			min_score = tmp_count + current_count;
			r_count = current_count;
		}
		current_count++;
		elem = elem->next;
	}
	return (r_count);
}

//find the orientation with minimun rotation
int best_count(t_stack *a, t_stack *b)
{
	int	r_count;
	int rr_count;

	if (b->size < 2)
		return (0);
	r_count = count_rotate(a,b);
	rr_count = count_rrotate(a, b);
	if (rr_count < r_count)
		return (-1 * rr_count);
	else
		return (r_count);
}

//put back in A sorted
void	push_a_sorted(t_stack *a, t_stack *b)
{
	int sens_rotation;

	while (b->size > 0)
	{
		ft_pa(a, b);
		write(1, "pa\n", 3);
	}
	sens_rotation = find_closet(INT_MAX, a);
	while (a->last->value < a->first->value)
	{
		if (sens_rotation == 1)
		{
			ft_ra(a);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_rra(a);
			write(1, "rra\n", 4);
		}
	}
}

void	tri_version(t_stack *a, t_stack *b)
{
	int best_count_r;

	while (a->size > 0)
	{
		best_count_r =  best_count(a, b);
		while (ft_abs(best_count_r) > 0)
		{
			if (best_count_r > 0)
			{
				ft_ra(a);
				write(1, "ra\n", 3);
				best_count_r --;
			}
			else
			{
				ft_rra(a);
				write(1, "rra\n", 4);
				best_count_r++;
			}
		}
		push_b_sorted(a, b);
	}
	push_a_sorted(a, b);
}

















