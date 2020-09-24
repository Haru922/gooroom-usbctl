#include <gtk/gtk.h>

#include "gooroom-usbctl-application.h"
#include "gooroom-usbctl-window.h"

struct _GooroomUsbctlApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE(GooroomUsbctlApp, gooroom_usbctl_app, GTK_TYPE_APPLICATION);

static void
gooroom_usbctl_app_init (GooroomUsbctlApp *app)
{
}

static void
gooroom_usbctl_app_startup (GApplication *app)
{
  G_APPLICATION_CLASS (gooroom_usbctl_app_parent_class)->startup (app);
}

static void
gooroom_usbctl_app_activate (GApplication *app)
{
  GooroomUsbctlAppWindow *win;

  win = gooroom_usbctl_app_window_new (GOOROOM_USBCTL_APP (app));
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_window_present (GTK_WINDOW (win));
}

static void
gooroom_usbctl_app_class_init (GooroomUsbctlAppClass *class)
{
  G_APPLICATION_CLASS (class)->startup = gooroom_usbctl_app_startup;
  G_APPLICATION_CLASS (class)->activate = gooroom_usbctl_app_activate;
}

GooroomUsbctlApp *
gooroom_usbctl_app_new (void)
{
  return g_object_new (GOOROOM_USBCTL_APP_TYPE,
                       "application-id", "kr.gooroom.gooroom-usbctl",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}
