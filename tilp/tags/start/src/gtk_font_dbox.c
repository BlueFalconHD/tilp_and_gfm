/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "gtk_font_cb.h"
#include "gtk_font_dbox.h"
#include "support.h"

GtkWidget*
create_font_dbox (void)
{
  GtkWidget *font_dbox;
  GtkWidget *ok_button1;
  GtkWidget *cancel_button1;
  GtkWidget *apply_button1;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();

  font_dbox = gtk_font_selection_dialog_new (_("Select Font (right window)"));
  gtk_object_set_data (GTK_OBJECT (font_dbox), "font_dbox", font_dbox);
  gtk_container_set_border_width (GTK_CONTAINER (font_dbox), 4);
  gtk_window_set_policy (GTK_WINDOW (font_dbox), FALSE, TRUE, TRUE);

  ok_button1 = GTK_FONT_SELECTION_DIALOG (font_dbox)->ok_button;
  gtk_object_set_data (GTK_OBJECT (font_dbox), "ok_button1", ok_button1);
  gtk_widget_show (ok_button1);
  GTK_WIDGET_SET_FLAGS (ok_button1, GTK_CAN_DEFAULT);
  gtk_widget_add_accelerator (ok_button1, "clicked", accel_group,
                              GDK_Return, 0,
                              GTK_ACCEL_VISIBLE);

  cancel_button1 = GTK_FONT_SELECTION_DIALOG (font_dbox)->cancel_button;
  gtk_object_set_data (GTK_OBJECT (font_dbox), "cancel_button1", cancel_button1);
  gtk_widget_show (cancel_button1);
  GTK_WIDGET_SET_FLAGS (cancel_button1, GTK_CAN_DEFAULT);
  gtk_widget_add_accelerator (cancel_button1, "clicked", accel_group,
                              GDK_Escape, 0,
                              GTK_ACCEL_VISIBLE);

  apply_button1 = GTK_FONT_SELECTION_DIALOG (font_dbox)->apply_button;
  gtk_object_set_data (GTK_OBJECT (font_dbox), "apply_button1", apply_button1);
  gtk_widget_show (apply_button1);
  GTK_WIDGET_SET_FLAGS (apply_button1, GTK_CAN_DEFAULT);
  gtk_widget_add_accelerator (apply_button1, "clicked", accel_group,
                              GDK_A, 0,
                              GTK_ACCEL_VISIBLE);

  gtk_signal_connect (GTK_OBJECT (font_dbox), "show",
                      GTK_SIGNAL_FUNC (on_font_dbox_show),
                      font_dbox);
  gtk_signal_connect (GTK_OBJECT (ok_button1), "clicked",
                      GTK_SIGNAL_FUNC (on_font_ok_button1_clicked),
                      font_dbox);
  gtk_signal_connect (GTK_OBJECT (cancel_button1), "clicked",
                      GTK_SIGNAL_FUNC (on_font_cancel_button1_clicked),
                      font_dbox);
  gtk_signal_connect (GTK_OBJECT (apply_button1), "clicked",
                      GTK_SIGNAL_FUNC (on_font_apply_button1_clicked),
                      font_dbox);

  gtk_window_add_accel_group (GTK_WINDOW (font_dbox), accel_group);

  return font_dbox;
}

