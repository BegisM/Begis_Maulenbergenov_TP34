Always on Top C++ Program for Ubuntu
This program sets a specific window (like Gedit) to always stay on top of other windows in Ubuntu using the X11 library.

Requirements
Before compiling and running this program, make sure you have the necessary development packages installed:

```sudo apt-get install libx11-dev```
```g++ -o ubuntu_pinning_name ubuntu_pinning_name.cpp -lX11```

Usage
After compiling, run the program using:

```./ubuntu_pinning_name```

The program will search for a window with the title "name.txt" and set it to always be on top of other windows. If you want to pin a different window, edit the code and replace "name.txt" with the title of the desired window.

----------------------------------------------------

Always on Top C++ Program for Windows

This program sets a specific Notepad window with an open file (e.g., name.txt) to always stay on top of other windows in Windows using the Windows API.

Requirements
You need a C++ compiler for Windows, such as MinGW or Microsoft Visual Studio, to compile the program.

Compilation
Save the C++ source code file as always_on_top.cpp.
Open a terminal or command prompt in the directory where the file is saved.
Use one of the following methods to compile the program:
With MinGW (Command Prompt):

```g++ -o always_on_top always_on_top.cpp -mwindows```

With Visual Studio (Developer Command Prompt):

```cl always_on_top.cpp /EHsc```

Usage
Open Notepad and open the file name.txt (or any file you want to set to always be on top).
Run the compiled always_on_top.exe program from the terminal or by double-clicking the executable.
The program will set the Notepad window with the file "name.txt" to always be on top of other windows.
Customization
To target a different file or window title in Notepad, modify the window title in the code. For example, if you open a file called example.txt, change this line:


```HWND hwnd = FindWindow(NULL, "example.txt - Notepad");```

Make sure the window title exactly matches the one shown in Notepad.

How It Works
The program uses the Windows API to find the Notepad window by its title.
It then uses the ```SetWindowPos()``` function with the ```HWND_TOPMOST``` flag to make the window always stay on top.
To disable "Always on Top," you can change the function call to use ```HWND_NOTOPMOST```.