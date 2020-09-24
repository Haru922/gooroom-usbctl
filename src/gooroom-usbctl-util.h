#ifndef _GOOROOM_USBCTL_UTIL_H_
#define _GOOROOM_USBCTL_UTIL_H_

#include <stdio.h>
#include <stdlib.h>

#define USB_INFO_FILE               "/var/lib/gooroom-usbctl/usbctl.wl"
#define USB_POLICY_INFO_FILE        "/var/lib/gooroom-usbctl/usbctl.policy"
#define USB_INFO_SET_FAILURE        -1
#define USB_POLICY_INFO_SET_SUCCESS  0
#define USB_POLICY_INFO_SET_FAILURE -1


typedef enum
{
  USB_INFO_SERIAL,
  USB_INFO_TIME,
  USB_INFO_STATE,
  USB_INFO_NAME,
  USB_INFO_PRODUCT,
  USB_INFO_SIZE,
  USB_INFO_VENDOR,
  USB_INFO_SEQ,
  USB_INFO_NUM
} USB_INFO;

typedef enum
{
  USB_POLICY_INFO_USB_LIMIT,
  USB_POLICY_INFO_NUM
} USB_POLICY_INFO;

typedef struct _usb_info
{
  char *value[USB_INFO_NUM];
} usb_info;

typedef struct _usb_policy_info
{
  char *value[USB_POLICY_INFO_NUM];
} usb_policy_info;

int gooroom_usbctl_get_usb_infos       (usb_info **usbs);
int gooroom_usbctl_get_usb_policy_info (usb_policy_info *policy);

#endif
