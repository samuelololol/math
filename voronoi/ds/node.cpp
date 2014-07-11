#include "node.h"

node_t::node_t ():
    x_(0),
    y_(0),
    isnull_(true) {}

node_t::node_t (const int ix, const int iy):
    x_(ix),y_(iy),isnull_(false) {}

node_t::node_t (const rational<int> ix, const rational<int> iy):
    x_(ix),y_(iy),isnull_(false) {}

node_t& node_t::operator=(const node_t& n)
{
    if (this != &n)
    {
        if (n.isnull() == true)
        {
            x_ = y_ = 0;
            isnull_ = true;
        }
        else{
            x_ = n.getx();
            y_ = n.gety();
            isnull_ = n.isnull();
        }
    }
    return *this;
}

node_t::~node_t() {}  

bool node_t::operator<(const node_t& n) const
{
    if (x_ < n.getx()) 
        return true;
    if ((x_ == n.getx()) && (y_ < n.gety())) 
        return true;
    else 
        return false;
}

bool node_t::operator==(const node_t& n) const
{
    if ((isnull() == n.isnull()) && (x_ == n.getx()) && (y_ == n.gety()))
        return true;
    else
        return false;
}

bool node_t::operator!=(const node_t& n) const
{
    return !(*this == n)
}
// distance
//rational<int> node_t::operator-(const node_t& n) const
//{ return sqrt((n.getx() - x_)*(n.getx() - x_) + (n.gety() - y_)*(n.gety() - y_)); }

bool node_t::isnull() const
{
    return isnull_; 
}

rational<int> node_t::getx() const
{ 
    if (isnull_ == true)
        throw nodeexception("Cannot getx() by a null node\n");
    return x_; 
}

rational<int> node_t::gety() const
{ 
    if (isnull_ == true)
        throw nodeexception("Cannot gety() by a null node\n");
    return y_; 
}

ostream& operator<<(ostream& out, const node_t& n)
{
    if (n.isnull() == true)
        out << "Null";
    else
        out << "(" << n.getx() << "," << n.gety() << ")";
    return out;
}
