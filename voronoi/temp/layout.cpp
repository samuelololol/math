
#include <gtkmm.h>

enum
{
    C_WHITE = 0,
    C_RED,
    C_BLACK,
    C_NUM
};


class MyDrawArea : public Gtk::DrawingArea
{
    Glib::RefPtr< Gdk::GC > m_gc;
    Gdk::Color m_col[ C_NUM ];
    Glib::RefPtr< Pango::Layout > m_layout;

    public:
    MyDrawArea();

    protected:
    virtual void on_realize();
    virtual bool on_expose_event( GdkEventExpose* e );
};


MyDrawArea::MyDrawArea()
{
    // カラーマップの登録
    m_col[ C_WHITE ] = Gdk::Color( "white" );
    m_col[ C_RED ] = Gdk::Color( "red" );
    m_col[ C_BLACK ] = Gdk::Color( "black" );

    Glib::RefPtr< Gdk::Colormap > colmap = get_default_colormap();
    for( int i = 0; i < C_NUM; ++i ) colmap->alloc_color( m_col[ i ] );

    // pango layout作成
    m_layout = create_pango_layout( "" );
}


void MyDrawArea::on_realize()
{
    // 元のon_realize()のコールを忘れないこと
    Gtk::DrawingArea::on_realize(); 

    // Gdk::Window からGCを作る
    m_gc = Gdk::GC::create( get_window() );
}


bool MyDrawArea::on_expose_event( GdkEventExpose* event )
{
    int width = get_width();
    int height =get_height();
    int x, y = 10;

    // 背景の塗りつぶし
    get_window()->set_background( m_col[ C_BLACK ] );
    get_window()->clear();

    // フォント指定
    m_layout->set_font_description( Pango::FontDescription( "Serif 20" ) );

    // 表示する文字をセット
    m_layout->set_text("あいうえお");

    // 中央揃え
    x = ( width - m_layout->get_pixel_ink_extents().get_width() ) / 2;

    // 描画
    get_window()->draw_layout( m_gc, x, y, m_layout , m_col[ C_WHITE],  m_col[ C_RED ] );

    // 次のパラグラフのy座標
    y += m_layout->get_pixel_ink_extents().get_height() + 10;

    // フォント指定
    m_layout->set_font_description( Pango::FontDescription( "Monospace 24" ) );

    // 表示する文字をセット
    m_layout->set_text("かきくけこ");

    // 中央揃え
    x = ( width - m_layout->get_pixel_ink_extents().get_width() ) / 2;

    // 描画
    get_window()->draw_layout( m_gc, x, y, m_layout,  m_col[ C_RED ], m_col[ C_WHITE] );

    return true;
}


class MainWin : public Gtk::Window
{
    MyDrawArea m_drawarea;

    public:

    MainWin(){
        add( m_drawarea );
        show_all_children();
    }
};


int main( int argc, char *argv[] )
{
    Gtk::Main kit( argc, argv );
    MainWin mainwin;
    Gtk::Main::run( mainwin );

    return 0;
}
