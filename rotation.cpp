#include <graphics.h>
#include <math.h>

#define PI 3.14159265

void rotate(int x[], int y[], int n, float angle)
{
    int i;
    float rad = angle * PI / 180; // Convert angle to radians
    for (i = 0; i < n; i++)
    {
        int tempX = x[i];
        x[i] = round(x[i] * cos(rad) - y[i] * sin(rad));
        y[i] = round(tempX * sin(rad) + y[i] * cos(rad));
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
    initgraph(&gd, &gm, "");

    int x[] = {150, 250, 300, 200, 150}; // Different x coordinates
    int y[] = {100, 100, 200, 200, 100};
    int n = sizeof(x) / sizeof(x[0]);

    // Original polygon
    setcolor(YELLOW);
    drawPolygon(x, y, n);

    // Rotation angle (in degrees)
    float angle = 15.0; // Rotate by 45 degrees

    // Rotate the polygon
    rotate(x, y, n, angle);

    // Rotated polygon
    setcolor(WHITE);
    drawPolygon(x, y, n);

    getch();
    closegraph();

    return 0;
}
