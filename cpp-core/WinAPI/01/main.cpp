#include <windows.h>

// https://rsdn.org/article/baseserv/api32.xml
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCommandLine, int nCommandShow) {
    MessageBox(NULL, "Hello World", "WinAPI App", 0);

    return 0;
}