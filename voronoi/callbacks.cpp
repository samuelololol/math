#include "callbacks.h"
#include <string>
#include <sstream>

using namespace std;

bool myclick(GdkEventButton* event, Glib::RefPtr<Gtk::TextBuffer> buffer)
{
    //std::cout<< "hello, world" << std::endl;
    //std::cout<< "(" << event->x << "," << event->y << ")" << std::endl;
    


    // display on textbuffer
    stringstream ss;
    ss << "(" << event->x << "," << event->y << ")\n" ;
    Glib::ustring  str=buffer->get_text();
    str.append(ss.str());
    buffer->set_text(str);
    


    return true;
}

bool mymove(GdkEventMotion* event, Gtk::Label* label)
{
    // modift label
    stringstream ss;
    ss << "(" << event->x << "," << event->y << ")" ;
    Glib::ustring  str=ss.str();
    label->set_text(str);

    return true;
}
