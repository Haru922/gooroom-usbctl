#ifndef _GOOROOM_USBCTL_APPLICATION_H_
#define _GOOROOM_USBCTL_APPLICATION_H_

#include <gtk/gtk.h>

#define GOOROOM_USBCTL_APP_TYPE (gooroom_usbctl_app_get_type ())
G_DECLARE_FINAL_TYPE (GooroomUsbctlApp, gooroom_usbctl_app, GOOROOM_USBCTL, APP, GtkApplication)

GooroomUsbctlApp *gooroom_usbctl_app_new (void);

#endif
