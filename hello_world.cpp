#include <gtk/gtk.h>
#include <string>
GtkWidget* generate_box_with_outline(const char* title)
{
  GtkWidget* textbox;
  GtkWidget* box_outline;
  box_outline = gtk_frame_new(title);
  textbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
  gtk_frame_set_child(GTK_FRAME(box_outline) ,textbox);
  return box_outline;

}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget* grid_manager;
  grid_manager = gtk_grid_new();
  gtk_grid_set_column_homogeneous(GTK_GRID(grid_manager), false);
  std::string varLen = "a";
  for(int i = 1; i <= 9; i++)
  {
    GtkWidget* box_with_outlines;
    box_with_outlines = generate_box_with_outline(varLen.c_str());
    gtk_grid_attach(GTK_GRID(grid_manager), box_with_outlines, i%2, i*4, 1, 2); //number parameters go like this: horizontal offset, vertical offset, colspan, rowspan
    varLen.append("a");
  }
  GtkWidget* window;
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "CCG");
  gtk_window_set_default_size (GTK_WINDOW (window), 1920, 1080);
  gtk_window_set_child(GTK_WINDOW(window), grid_manager);
  gtk_window_maximize(GTK_WINDOW(window));
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

