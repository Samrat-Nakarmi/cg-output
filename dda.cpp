#include <graphics.h>
#include <math.h>

void drawLine(int x0, int y0, int x1, int y1)
{
    int steps, k;
    float dx, dy, xIncrement, yIncrement, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    xIncrement = dx / steps;
    yIncrement = dy / steps;

    x = x0;
    y = y0;

    for (k = 0; k < steps; k++)
    {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
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
