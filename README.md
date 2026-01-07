# Windows App Template Minimal **Win32 API C application template** for building native Windows desktop applications without frameworks, runtimes, or abstractions.

This project serves as a starting point for low-level Windows development using the raw Windows API (`windows.h`), making it ideal for learning, prototyping, or building lightweight native tools.

---

## Features

* Pure **C + Win32 API**
* Custom window class and message loop
* Native Windows buttons (`BUTTON` controls)
* Message handling via `WindowProc`
* Modular button click handlers
* Optional custom window icon support
* No dependencies beyond the Windows SDK

---

## Project Structure

```
WindowsApp/
├── main.c        # Entry point and Win32 application code
├── README.md     # Project documentation
```

---

## How It Works

* Registers a custom `WNDCLASS`
* Creates a top-level window using `CreateWindowEx`
* Adds three native buttons as child controls
* Uses `WM_COMMAND` to route button events
* Each button triggers its own handler function
* Runs a standard Win32 message loop

This mirrors how *real* Windows applications work under the hood—no MFC, no .NET, no Qt.

---

## Buttons

| Button   | Action                |
| -------- | --------------------- |
| Button 1 | Displays a MessageBox |
| Button 2 | Displays a MessageBox |
| Button 3 | Displays a MessageBox |

Each button is wired via a unique `HMENU` ID and handled inside `WM_COMMAND`.

---

## Build Instructions

### Using MSVC (Developer Command Prompt)

```bat
cl main.c user32.lib gdi32.lib shell32.lib
```

### Using MinGW (GCC)

```bash
gcc main.c -o WindowsApp.exe -luser32 -lgdi32 -lshell32
```

> Make sure you are compiling on Windows with the Windows SDK available.

---

## Custom Icon

The window icon is loaded using:

```c
LoadImage(NULL, "File Path For Icon", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
```

To use a custom icon:

1. Replace `"File Path For Icon"` with an absolute or relative `.ico` file path
2. Ensure the file exists at runtime

---

## Why This Template?

This project is useful if you want to:

* Learn **Win32 internals**
* Understand Windows message handling
* Build lightweight native tools
* Avoid heavy UI frameworks
* Work closer to the OS (security, tooling, RE, automation)

It’s especially useful for systems programmers, security engineers, and anyone interested in Windows internals.

---

## Next Ideas / Extensions

* Add menus (`CreateMenu`)
* Keyboard shortcuts / accelerators
* Custom drawing with GDI
* Multiple windows
* Dialog boxes
* File system interaction
* Replace buttons with custom controls

---

## License

MIT License
