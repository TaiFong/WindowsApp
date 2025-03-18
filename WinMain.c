#include <windows.h>
#include <shlobj.h>
#include <stdio.h>

// Define constants for button IDs
#define BUTTON1_ID 101
#define BUTTON2_ID 102
#define BUTTON3_ID 103
#define BUTTON4_ID 104
#define BUTTON5_ID 105
#define BUTTON6_ID 106


// Function declarations
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OnButton1Click(HWND hwnd);
void OnButton2Click(HWND hwnd);
void OnButton3Click(HWND hwnd);


//main
int main() {
    // Initialize window class
    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char *className = "SimpleAppClass";
    HICON hIcon = (HICON) LoadImage(NULL, "File Path For Icon ", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);


    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc; // Window procedure
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hIcon = hIcon;  // Set the icon for the window class
    RegisterClass(&wc);

    // Create window
    HWND hwnd = CreateWindowEx(
        0, className, "My Application", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, hInstance, NULL
    );

    // Create buttons
    CreateWindow("BUTTON", "Button 1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 100, 50, 150, 30, hwnd, (HMENU)BUTTON1_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Button 2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 100, 100, 150, 30, hwnd, (HMENU)BUTTON2_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Button 3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 100, 150, 150, 30, hwnd, (HMENU)BUTTON3_ID, hInstance, NULL);

    // Show window
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Window procedure for handling messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case BUTTON1_ID:
                    OnButton1Click(hwnd);  // Call the button 1 function
                    break;
                case BUTTON2_ID:
                    OnButton2Click(hwnd);
                    break;
                case BUTTON3_ID:
                    OnButton3Click(hwnd);
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Button 1 functionality
void OnButton1Click(HWND hwnd) {
    MessageBox(NULL, "Button 1 clicked", "Information", MB_OK);
}
// Button 2 functionality
void OnButton2Click(HWND hwnd) {
    MessageBox(NULL, "Button 2 clicked", "Information", MB_OK);
}

// Button 3 functionality
void OnButton3Click(HWND hwnd) {
    MessageBox(NULL, "Button 3 clicked", "Information", MB_OK);
}
