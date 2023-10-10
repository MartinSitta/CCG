#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget* window;
  GtkWidget* textbox;
  GtkWidget* text;
  text = gtk_label_new("Hello World");
  textbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
  gtk_box_prepend(GTK_BOX(textbox), text);
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "CCG");
  gtk_window_set_default_size (GTK_WINDOW (window), 1920, 1080);
  gtk_window_set_child(GTK_WINDOW(window), textbox);
  gtk_window_present (GTK_WINDOW(window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *ccg_application;
  int status;

  ccg_application = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (ccg_application, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (ccg_application), argc, argv);
  g_object_unref (ccg_application);

  return status;
}

