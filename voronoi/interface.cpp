#include "interface.h"
#define MY_TBUFP_T Glib::RefPtr<Gtk::TextBuffer>

Gtk::Window* create_window1(string argv)
{
    Gtk::Window*      window1;
    Gtk::DrawingArea* drawingarea1;
    Gtk::Label*       label1;

    Gtk::TextView*    textview1;
    Gtk::TextView*    textview2;



    //load the glade file and instiate tis widgets:
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    try
    {
        builder->add_from_file(argv);
    }
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 0;
    }
    catch(const Gtk::BuilderError& ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 0;
    }

    // get widgets

    builder->get_widget("window1",window1);
    builder->get_widget("drawingarea1",drawingarea1);
    builder->get_widget("label1",label1);
    builder->get_widget("textview1", textview1);
    builder->get_widget("textview2", textview2);

    Glib::RefPtr<Gtk::TextBuffer> buffer1 = textview1->get_buffer();

    // connect with drawingarea1
    //drawingarea1->signal_button_press_event().connect(sigc::bind<Glib::RefPtr<Gtk::TextBuffer> >(sigc::ptr_fun(&myclick), buffer1));
    drawingarea1->signal_button_press_event().connect(sigc::bind<MY_TBUFP_T>(sigc::ptr_fun(&myclick), buffer1));
    drawingarea1->signal_motion_notify_event().connect(sigc::bind<Gtk::Label*>(sigc::ptr_fun(&mymove),label1));

    // get textbuffers



    return window1;
}

