#include <stdio.h>
#include <X11/XKBlib.h>

int main(void) {
	int xkb_event;
	int xkb_error;
	int reason_rtrn;
	int xkb_mjr = XkbMajorVersion;
	int xkb_mnr = XkbMinorVersion;

	Display *dispay = XkbOpenDisplay(NULL, &xkb_event, &xkb_error, &xkb_mjr, &xkb_mnr, &reason_rtrn);

	if (reason_rtrn != XkbOD_Success) {
		printf("FAIL\n");
	}
	else {
		printf("Yay!\n");
	}

	if (!XkbSelectEvents(dispay, XkbUseCoreKbd, XkbStateNotifyMask, XkbStateNotifyMask)) {
		printf("FAIL2\n");
	}

	XkbEvent event;

	while (1) {
		XNextEvent(dispay, &event.core);
		if (event.type == xkb_event && event.any.xkb_type == XkbStateNotify) {
			unsigned char caps = (event.state.mods & 1); // shift presed
			if (event.state.mods & 2) { // caps pressed
				caps = !caps;
			}
			if (event.state.group == 1) {
				if (caps) {
					printf("RU\n");
				}
				else {
					printf("ru\n");
				}
			} 
			else {
				if (caps) {
					printf("EN\n");
				}
				else {
					printf("en\n");
				}
			}
		}
	}

	return 0;
}
