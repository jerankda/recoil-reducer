#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>

#define MOUSEEVENTF_MOVE 0x0001
#define MOUSEEVENTF_LEFTDOWN 0x0002
#define MOUSEEVENTF_LEFTUP 0x0004

int main()
{
    double recoil_reduction = 0;

    printf("value: (0 - 1): ");
    scanf_s("%lf", &recoil_reduction);

    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;

    while (1)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            dx = 0;
            dy = (int)(recoil_reduction * 10);
        }
        else
        {
            dx = 0;
            dy = 0;
        }

        x += dx;
        y += dy;

        mouse_event(MOUSEEVENTF_MOVE, dx, dy, 0, 0);

        Sleep(10);
    }

    return 0;
}
