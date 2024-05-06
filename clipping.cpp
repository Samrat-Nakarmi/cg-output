#include <graphics.h>
#include <stdio.h>

// Define region codes
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Define the window boundaries
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 400
#define Y_MAX 300

// Define the size of the region codes
#define MAX_CODE 15

// Function to compute region code for a point (x, y)
int computeCode(int x, int y)
{
    int code = INSIDE;
    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;
    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;
    return code;
}

// Function to clip a line segment
void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1, code2;
    int accept = 0, done = 0;
    code1 = computeCode(x1, y1);
    code2 = computeCode(x2, y2);
    do
    {
        if (!(code1 | code2))
        {
            accept = 1;
            done = 1;
        }
        else if (code1 & code2)
        {
            done = 1;
        }
        else
        {
            int x, y;
            int codeOut = code1 ? code1 : code2;
            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            }
            else if (codeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    } while (!done);
    if (accept)
    {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(BLACK);
    cleardevice();

    outtextxy(50, 20, "Before Clipping");
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
    line(50, 250, 350, 50);
    getch();
    cleardevice();
    // Draw the clipping window

    outtextxy(50, 20, "After Clipping");
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Draw lines to be clipped
    // Line 1: Completely inside

    // Line 4: Crossing top and bottom
    cohenSutherland(50, 250, 350, 50);

    getch();
    closegraph();
    return 0;
}
