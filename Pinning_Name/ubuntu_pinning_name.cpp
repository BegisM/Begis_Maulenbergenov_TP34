#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <iostream>
#include <cstring>

// Function to set the window always on top
void SetAlwaysOnTop(Display* display, Window window) {
    Atom wm_state = XInternAtom(display, "_NET_WM_STATE", False);
    Atom wm_state_above = XInternAtom(display, "_NET_WM_STATE_ABOVE", False);

    XEvent event;
    std::memset(&event, 0, sizeof(event));

    event.xclient.type = ClientMessage;
    event.xclient.message_type = wm_state;
    event.xclient.display = display;
    event.xclient.window = window;
    event.xclient.format = 32;
    event.xclient.data.l[0] = 1;  // Add property
    event.xclient.data.l[1] = wm_state_above;
    event.xclient.data.l[2] = 0;
    event.xclient.data.l[3] = 0;
    event.xclient.data.l[4] = 0;

    XSendEvent(display, DefaultRootWindow(display), False, SubstructureRedirectMask | SubstructureNotifyMask, &event);
    XFlush(display);
}

int main() {
    // Open connection to the X server
    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cerr << "Unable to open X display." << std::endl;
        return 1;
    }

    // Query the root window to find the window tree
    Window root = DefaultRootWindow(display);
    Window parent;
    Window* children;
    unsigned int nchildren;
    XQueryTree(display, root, &root, &parent, &children, &nchildren);

    // Iterate through the windows to find the target window
    for (unsigned int i = 0; i < nchildren; i++) {
        char* window_name;
        if (XFetchName(display, children[i], &window_name) > 0) {
            if (window_name && std::string(window_name).find("name.txt") != std::string::npos) {
                SetAlwaysOnTop(display, children[i]);
                std::cout << "name.txt window is now set to always on top." << std::endl;
                XFree(window_name);
                break;
            }
            XFree(window_name);
        }
    }

    // Free allocated memory and close connection
    if (children) {
        XFree(children);
    }
    XCloseDisplay(display);

    return 0;
}

