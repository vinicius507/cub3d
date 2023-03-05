#include "projection.h"

void	pixel_put(t_img *buffer, int x, int y, int color)
{
	char	*addr;
	int		*pixel;
	int		y_map;
	int		x_map;

	if (x > 1280 || x < 0)
		return ;
	if (y > 720 || y < 0)
		return ;
	y_map = y * buffer->line_len;
	x_map = x * (buffer->bpp / 8);
	addr = buffer->data + y_map + x_map;
	pixel = (int *)addr;
	*pixel = color;
}

int	pixel_get(t_img *buffer, int x, int y)
{
	char	*px;

	px = buffer->data + y * buffer->line_len + (x * (buffer->bpp / 8));
	return (*(unsigned int *)px);
}

int	background(t_img *buffer, t_color ceiling, t_color floor)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 720)
	{
		x = 0;
		while (x <= 1280)
			if (y <= 360)
				pixel_put(buffer, x++, y, ceiling.hex);
			else
				pixel_put(buffer, x++, y, floor.hex);
		y++;
	}
	return (0);
}
