#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int maxx, maxy, midx, midy;

void axis()
{
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}

int main()
{
    int x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    axis();

    // Draw the original cube
    bar3d(midx + 30, midy - 150, midx + 90, midy - 50, 40, 1);

    printf("Enter translation factor: ");
    scanf("%d%d", &x, &y);

    // Draw the translated cube
    printf("After translation:\n");
    bar3d(midx + x + 30, midy - (y + 150), midx + x + 90, midy - (y + 50), 40, 1);

    getch();
    closegraph();
    return 0;
}
