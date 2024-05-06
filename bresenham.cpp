#include <graphics.h>

void drawLine(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy, err, e2;

    if (x0 < x1)
        sx = 1;
    else
        sx = -1;

    if (y0 < y1)
        sy = 1;
    else
        sy = -1;

    err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        putpixel(x0, y0, WHITE);
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
    putpixel(x0, y0, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x0, y0, x1, y1;
    printf("Enter the coordinates of the first point (x0 y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Enter the coordinates of the second point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    drawLine(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}
