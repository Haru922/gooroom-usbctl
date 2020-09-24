project('gooroom-usbctl', 'c')

cc = meson.get_compiler('c')

gnome = import('gnome')
    
gtk_dep = dependency('gtk+-3.0')
glib_dep = dependency('glib-2.0')
gio_dep = dependency('gio-2.0')

gooroom_usbctl_sources = [
  'src/gooroom-usbctl-application.c',
  'src/gooroom-usbctl-window.c',
  'src/gooroom-usbctl-util.c',
  'src/gooroom-usbctl-main.c'
]

gooroom_usbctl_sources += gnome.compile_resources(
  'gooroom-usbctl-resources',
  'resources/gooroom-usbctl.gresource.xml',
  source_dir: 'resources'
)

gooroom_usbctl = executable(
  'gooroom-usbctl',
  gooroom_usbctl_sources,
  dependencies: [gtk_dep, glib_dep, gio_dep],
)

po_dir = join_paths(meson.source_root(), 'po')

subdir('po')
run_command('/bin/bash', 'makemo')
