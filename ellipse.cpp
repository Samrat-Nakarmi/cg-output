#include <graphics.h>
#include <math.h>

void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0, y = ry;
    long rxSq = rx * rx;
    long rySq = ry * ry;
    long twoRxSq = 2 * rxSq;
    long twoRySq = 2 * rySq;
    long p;
    long px = 0, py = twoRxSq * y;

    // Region 1
    p = round(rySq - (rxSq * ry) + (0.25 * rxSq));
    while (px < py)
    {
        x++;
        px += twoRySq;
        if (p < 0)
        {
            p += rySq + px;
        }
        else
        {
            y--;
            py -= twoRxSq;
            p += rySq + px - py;
        }
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    // Region 2
    p = round(rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq);
    while (y > 0)
    {
        y--;
        py -= twoRxSq;
        if (p > 0)
        {
            p += rxSq - py;
        }
        else
        {
            x++;
            px += twoRySq;
            p += rxSq - py + px;
        }
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, rx, ry;
    printf("Enter the coordinates of the center (xc yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the horizontal radius (rx): ");
    scanf("%d", &rx);
    printf("Enter the vertical radius (ry): ");
    scanf("%d", &ry);

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();

    return 0;
}
