#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int maxx, maxy, midx, midy;
void axis()
{
    getch();
    cleardevice();
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}
int main()
{
    int x, y, z, o, x1, x2, y1, y2;
    int gd = DETECT, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, NULL);
    // setfillstyle(0,getmaxcolor());
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    axis();

    bar3d(midx + 30, midy - 150, midx + 90, midy - 50, 40, 1);
    printf("Enter scaling factors");
    scanf("%d%d%d", &x, &y, &z);
    // axis();
    printf("After scaling");
    bar3d(midx + (x * 50), midy - (y * 100), midx + (x * 60), midy - (y * 90), 5 * z, 1);
    // axis();
    getch();
    closegraph();
}