#include <graphics.h>

void scale(int x[], int y[], int sx, int sy, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] *= sx;
        y[i] *= sy;
    }
}

void drawPolygon(int x[], int y[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x[] = {150, 250, 300, 200, 150}; // Different x coordinates
    int y[] = {100, 100, 200, 200, 100};
    int n = sizeof(x) / sizeof(x[0]);

    // Original polygon
    setcolor(YELLOW);
    drawPolygon(x, y, n);

    // Scaling factors
    int sx = 2, sy = 2;

    // Scaling the polygon
    scale(x, y, sx, sy, n);

    // Scaled polygon
    setcolor(WHITE);
    drawPolygon(x, y, n);

    getch();
    closegraph();

    return 0;
}
