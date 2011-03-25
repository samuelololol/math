#include "fire.h"

using std::cout;
using std::cout;

fire_t::fire_t():
    line_t(),
    startnode() {}  

fire_t::fire_t(const node_t& start, const node_t& n2):
    line_t(start, n2),
    startnode(start) 
{
    //if (
    //    (start.isnull() == true) ||
    //    (n2.isnull() == true)
    //   )
    line_t nline;
    nline = this->normalline(start);
    direction_ = (((nline.geta())*(n2.gety()) - (nline.getm())*(n2.getx()) - (nline.getb())) >= 0);
}

fire_t::fire_t(const node_t& start, const line_t& l1, bool side):
    line_t(l1),
    startnode(start),
    direction_(side) {}

fire_t::fire_t(const fire_t& rhs):
    line_t(rhs),
    startnode(rhs.getsnode()),
    direction_(rhs.direction()) {}  


fire_t& fire_t::operator=(const fire_t& ifire)
{
    if (this != &ifire)
    {
        startnode = ifire.getsnode();
        direction_ = ifire.direction_;
        static_cast<line_t&>(*this) = static_cast<const line_t&>(ifire);
    }
    return *this;
}

bool fire_t::operator==(const fire_t& ifire) const
{
    if (this == &ifire)
        return true;

    const line_t& tline = static_cast<const line_t&>(*this);
    const line_t& iline = static_cast<const line_t&>(ifire);

    if ( (getsnode() == ifire.getsnode()) &&
            (direction() == ifire.direction()) &&
            (tline == iline)
            )
        return true;
    else
        return false;
}


fire_t::~fire_t(){}  

bool fire_t::direction() const
{ return direction_; }

node_t fire_t::getsnode() const
{ return startnode; }

ostream& operator<<(ostream& out, const fire_t& f)
{
    line_t tmpl = static_cast<const line_t&>(f);
    out << "start node:" << f.getsnode() 
        << "\nline: " << static_cast<const line_t&>(f)
        << ", side: ";
    if (tmpl.isvirtigo() == false){
        out << "(" << (-1)*f.getm() 
            << ")x + (" <<f.geta() << ")y + (" 
            << (-1)*f.getb() << ")";
    }
    else
        cout << "(" << (-1)*f.getm() << ")x + ("
            << (-1)*f.getb() << ")";


    if (f.direction() > 0)
        out << " > 0";
    else if (f.direction() == 0)
        out << " = 0";
    else if (f.direction() < 0)
        out << " < 0";

    return out;
}
