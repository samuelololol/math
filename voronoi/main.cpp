#include "main.h"

int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  //HelloWorld helloworld;
  ////Shows the window and returns when it is closed.
  //Gtk::Main::run(helloworld);

  //Glib::RefPtr<Gtk::Window*> window;
  Gtk::Window* window;
  window = create_window1("vo.glade");
  Gtk::Main::run(*window);

  return 0;
}
