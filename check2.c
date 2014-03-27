#include "includes/rtv1.h"

void	check_cylinders(void)
{
	t_cylinder	*c;

	c = get_scene()->cylinders;

	while (c != NULL)
	{
		if (c->center == NULL || c->color == NULL || c->axis == NULL)
		{
			ft_putendl("Invalid cylinder");
			exit(-1);
		}
		c = c->next;
	}
}
