#include <gtkmm.h>
#include <iostream>

bool myclick(GdkEventButton* event, Glib::RefPtr<Gtk::TextBuffer> buffer);
bool mymove(GdkEventMotion* event,Gtk::Label* label);
