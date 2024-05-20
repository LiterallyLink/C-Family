#include <windows.h>

int main(void) {

    MessageBoxW(
        NULL,
        L"MESSAGEBOXES BE LIKE",
        L"Hello World!",
        0x00000003L | MB_ICONEXCLAMATION
    );

    return EXIT_SUCCESS;
}
