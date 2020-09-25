#include <glib.h>
#include <glib/gi18n.h>
#include <locale.h>
#include "gooroom-usbctl-application.h"

int
main (int   argc,
      char *argv[])
{
  int status;
  GooroomUsbctlApp *gooroom_usbctl_app;

  setlocale (LC_ALL, "");
  bindtextdomain ("gooroom-usbctl", "/usr/share/gooroom/locale");
  bind_textdomain_codeset ("gooroom-usbctl", "UTF-8");
  textdomain ("gooroom-usbctl");

  gooroom_usbctl_app = gooroom_usbctl_app_new ();
  status = g_application_run (G_APPLICATION (gooroom_usbctl_app), argc, argv);
  g_object_unref (gooroom_usbctl_app);

  return status;
}
