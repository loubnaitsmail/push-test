#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "limits.h"
#include "../libft/libft.h"

typedef struct	s_elem
{
	long	value;
	struct s_elem *prev;
	struct s_elem *next;
}				t_elem;

typedef struct	s_stack
{
	t_elem	*first;
	t_elem	*last;
	int		size;
}				t_stack;

void	tri_version(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rrb(t_stack *b);
void	ft_rra(t_stack *a);

void	print_reverse_stack(t_stack *a);
void	print_stack(t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);
long	remove_from_top(t_stack *a);
long	remove_from_end(t_stack *a);
void	add_to_top(t_stack *a, long  val);
void	add_to_end(t_stack *a, long val);

int		ft_isblank(int c);
void	ft_error(void);
long long	ft_atoill(const char *str);
int		count_nbr(t_stack *a);
int		check_double(t_stack *a);
void	ft_putstr(char *s);
void	push_a_sorted(t_stack *a, t_stack *b);
void	very_small_sort(t_stack *a);
void 	small_sort(t_stack *a, t_stack *b);
int	find_closet(long int value, t_stack *p);

#endif
