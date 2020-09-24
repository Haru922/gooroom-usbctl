#ifndef _GOOROOM_USBCTL_WINDOW_H_
#define _GOOROOM_USBCTL_WINDOW_H_

#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib/gi18n.h>
#include "gooroom-usbctl-application.h"
#include "gooroom-usbctl-util.h"

#define AGENT_DBUS_NAME    "kr.gooroom.agent"
#define AGENT_DBUS_OBJ     "/kr/gooroom/agent"
#define AGENT_DBUS_IFACE   "kr.gooroom.agent"
#define AGENT_DBUS_MSG_FMT "{ \"module\": { \"module_name\": \"%s\", \"task\": { \"task_name\": \"%s\", \"in\": %s } } }"

#define DIALOG_WIDTH       250
#define DIALOG_HEIGHT      100

#define GOOROOM_USBCTL_USB_LIMIT   10000

#define GOOROOM_USBCTL_APP_WINDOW_TYPE (gooroom_usbctl_app_window_get_type ())
G_DECLARE_FINAL_TYPE (GooroomUsbctlAppWindow, gooroom_usbctl_app_window, GOOROOM_USBCTL, APP_WINDOW, GtkApplicationWindow)

typedef enum 
{
  USB_SIGNAL_TYPE,
  USB_SIGNAL_LOGIN_ID,
  USB_SIGNAL_USB_SERIAL,
  USB_SIGNAL_USB_NAME,
  USB_SIGNAL_USB_PRODUCT,
  USB_SIGNAL_USB_SIZE,
  USB_SIGNAL_USB_VENDOR,
  USB_SIGNAL_USB_SEQ,
  USB_SIGNAL_NUM
} USB_SIGNAL;

typedef enum 
{
  EXCEPT_SIGNAL_TYPE,
  EXCEPT_ERROR_CODE,
  EXCEPT_EXCEPT_MSG,
  EXCEPT_INFO_NUM
} EXCEPT_INFO;

typedef struct _except_info
{
  gboolean occured;
  char *error_code;
  char *except_msg;
} except_info;

GooroomUsbctlAppWindow *gooroom_usbctl_app_window_new (GooroomUsbctlApp *app);

#endif
