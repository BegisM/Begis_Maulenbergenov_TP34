#include <windows.h>
#include <iostream>

// Function to set a window always on top
void SetAlwaysOnTop(HWND hwnd, bool alwaysOnTop) {
    if (alwaysOnTop) {
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    } else {
        SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
}

int main() {
    // Find the Notepad window by the specific file title (e.g., name.txt)
    HWND hwnd = FindWindow(NULL, "name.txt - Notepad");

    if (hwnd == NULL) {
        std::cout << "Could not find the Notepad window with name.txt open." << std::endl;
        return 1;
    }

    // Set the Notepad window to be always on top
    SetAlwaysOnTop(hwnd, true);

    std::cout << "Notepad window with name.txt is now set to always on top." << std::endl;

    return 0;
}
