#include "push_swap.h"
#include <stdio.h>

void	printstack(t_stack *stacka)
{
	int	largestindex;

	largestindex = stacka->top;
	while (largestindex >= 0)
	{
		ft_printf("%d ", stacka->arr[largestindex]);
		largestindex--;
	}
	ft_printf("\n");
}

int main(int argc, char **str)
{
    t_stack a;
    t_stack b;

    setupstacks(&a, &b, argc - 1);
    populatestacka(&a, &str[1], argc - 1);
    printf("%d\n", a.arr[findmaxreturnindex(&a)]);
    // printstack(&a);
    return (0);
}
