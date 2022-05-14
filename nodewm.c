/*
 * NoDE is written by o6n <https://github.com/o6n/>
 *
 * This software is in the public domain
 * and is provided AS IS, with NO WARRANTY.
 *
 * gcc -o nodewm nodewm.c -lX11
 *
 * su cp nodewm /usr/bin/nodewm
 *
 * su cp nodewm.desktop /usr/share/xsessions/nodewm.desktop
 */

#include <X11/Xlib.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void){
	Display * dsp;
	Screen *screen;
	XWindowAttributes attr;
	XButtonEvent start;
	XEvent ev;

	if(!(dsp = XOpenDisplay(0x0))) return 1;

	screen = DefaultScreenOfDisplay(dsp);

	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F1")), Mod4Mask, DefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F2")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F3")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F4")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F10")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F11")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("F12")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Tab")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Up")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Down")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Left")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Right")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Return")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Menu")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);
	XGrabKey(dsp, XKeysymToKeycode(dsp, XStringToKeysym("Delete")), Mod4Mask, XDefaultRootWindow(dsp), True, GrabModeAsync, GrabModeAsync);

	XGrabButton(dsp, 1, Mod4Mask, DefaultRootWindow(dsp), True, ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
	XGrabButton(dsp, 3, Mod4Mask, DefaultRootWindow(dsp), True, ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
	/*
	XGrabButton(dsp, 4, Mod4Mask, DefaultRootWindow(dsp), True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
	XGrabButton(dsp, 5, Mod4Mask, DefaultRootWindow(dsp), True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
	*/

	start.subwindow = None;
	for(;;){
		XNextEvent(dsp, &ev);
		if(ev.type == KeyPress){
			if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Return"))){
				system("xterm &");
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Menu"))){
				system("rofi -show drun &");
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Tab"))){
				system("rofi -show window &");
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("F12"))){
				exit(0);
			}
		}

		if(ev.type == KeyPress && ev.xkey.subwindow != None){
			/* Super_L + Delete chiude la finestra */
			if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Delete")) && ev.xkey.subwindow != None){
						XEvent event;
  						event.xclient.type = ClientMessage;
						event.xclient.window = ev.xkey.subwindow;
						event.xclient.message_type = XInternAtom(dsp, "WM_PROTOCOLS", True);
						event.xclient.format = 32;
						event.xclient.data.l[0] = XInternAtom(dsp, "WM_DELETE_WINDOW", False);
						event.xclient.data.l[1] = CurrentTime;
						XSendEvent(dsp, ev.xkey.subwindow, False, NoEventMask, &event);
						/* kill_win(ev.xbutton.subwindow); */
			}
			/*
				+-------+-------+
				|       |       |
				|       |       |
				| left  | right |
				|       |       |
				|       |       |
				+-------+-------+
			*/
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Left")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, 0, 0, screen->width / 2, screen->height);
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Right")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, screen->width / 2, 0, screen->width / 2, screen->height);
			}
			/*
				+-------+-------+
				|       |       |
				|  F1   |  F2   |
				|       |       |
				+-------+-------+
				|       |       |
				|  F3   |  F4   |
				|       |       |
				+-------+-------+
			*/
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("F1")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, 0, 0, screen->width / 2, screen->height / 2);
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("F2")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, screen->width / 2, 0, screen->width / 2, screen->height / 2);
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("F3")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, 0, screen->height / 2, screen->width / 2, screen->height);
			}
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("F4")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, screen->width / 2, screen->height / 2, screen->width, screen->height);
			}
			/* Super_L + F11 finestra a pieno schermo */
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("F11")) && ev.xkey.subwindow != None){
				XMoveResizeWindow(dsp, ev.xkey.subwindow, 0, 0, screen->width, screen->height);
			}
			/* Super_L + Up mette in primo piano la finestra */
			else if(ev.xbutton.button == XKeysymToKeycode(dsp,XStringToKeysym("Up"))){
				XRaiseWindow(dsp, ev.xkey.subwindow);
				XSetInputFocus(dsp, ev.xkey.subwindow, RevertToParent, CurrentTime);
			}
		}
		else if(ev.type == ButtonPress && ev.xbutton.subwindow != None){
			XGetWindowAttributes(dsp, ev.xbutton.subwindow, &attr);
			start = ev.xbutton;
		}
		else if(ev.type == MotionNotify && start.subwindow != None){
				int xdiff = ev.xbutton.x_root - start.x_root;
				int ydiff = ev.xbutton.y_root - start.y_root;
				XMoveResizeWindow(dsp, start.subwindow,
					attr.x + (start.button==1 ? xdiff : 0),
					attr.y + (start.button==1 ? ydiff : 0),
					MAX(1, attr.width + (start.button==3 ? xdiff : 0)),
					MAX(1, attr.height + (start.button==3 ? ydiff : 0)));
		}
		else if(ev.type == ButtonRelease){
			start.subwindow = None;
		}
	}
}
