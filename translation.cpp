#include <graphics.h>

void translate(int x[], int y[], int tx, int ty, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] += tx;
        y[i] += ty;
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

    int x[] = {100, 200, 200, 100, 100};
    int y[] = {100, 100, 200, 200, 100};
    int n = sizeof(x) / sizeof(x[0]);

    // Original polygon
    setcolor(YELLOW);
    drawPolygon(x, y, n);

    // Translation factors
    int tx = 50, ty = 50;

    // Translating the polygon
    translate(x, y, tx, ty, n);

    // Translated polygon
    setcolor(WHITE);
    drawPolygon(x, y, n);

    getch();
    closegraph();

    return 0;
}
