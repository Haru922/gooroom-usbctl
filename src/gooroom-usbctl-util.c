#include "gooroom-usbctl-util.h"
#include <glib.h>
#include <glib/gprintf.h>

int
gooroom_usbctl_get_usb_infos (usb_info **usbs)
{
  FILE  *fp = NULL;
  char **usb_field = NULL;
  int    usb_num = 0;
  int    i = 0;
  char   buf[BUFSIZ] = { 0, };

  fp = fopen (USB_INFO_FILE, "r");
  if (!fp)
    return USB_INFO_SET_FAILURE;

  while (fgets (buf, BUFSIZ, fp))
  {
    usbs[usb_num] = (usb_info *) calloc (1, sizeof (usb_info));
    for (i=0; buf[i]!='\n'; i++);
    buf[i] = '\0';
    usb_field = g_strsplit (buf, ",", 0);
    for (i=0; i<USB_INFO_NUM; i++)
      usbs[usb_num]->value[i] = g_strdup (usb_field[i]);
    usb_num++;
  }
  fclose (fp);

  return usb_num;
}

int
gooroom_usbctl_get_usb_policy_info (usb_policy_info *policy)
{
  FILE *fp = NULL;
  char buf[BUFSIZ] = { 0, };
  int i;

  fp = fopen (USB_POLICY_INFO_FILE, "r");
  if (!fp)
    return USB_POLICY_INFO_SET_FAILURE;

  fgets (buf, BUFSIZ, fp);
  for (i=0; buf[i]!='\n'; i++);
  buf[i] = '\0';
  policy->value[USB_POLICY_INFO_USB_LIMIT] = g_strdup (buf);
  fclose (fp);

  return USB_POLICY_INFO_SET_SUCCESS;
}
