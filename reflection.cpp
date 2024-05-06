#include <graphics.h>

void reflectX(int x[], int y[], int n)
{
    int i;
    int maxY = getmaxy(); // Get maximum y-coordinate of the screen

    for (i = 0; i < n; i++)
    {
        y[i] = maxY - y[i]; // Reflect along x-axis
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

    int x[] = {100, 200, 200, 100, 100}; // Coordinates for a square
    int y[] = {100, 100, 200, 200, 100}; 
    int n = sizeof(x) / sizeof(x[0]);

    // Original polygon
    setcolor(YELLOW);
    drawPolygon(x, y, n);

    // Reflecting the polygon along the x-axis
    reflectX(x, y, n);

    // Reflected polygon
    setcolor(WHITE);
    drawPolygon(x, y, n);

    getch();
    closegraph();

    return 0;
}
