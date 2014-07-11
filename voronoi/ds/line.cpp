#include "line.h"

line_t::line_t():
    m(0),
    a(0),
    b(0),
    isvirtigo_(false),
    isnull_(true) {}  

line_t::line_t(const node_t& n1,const node_t& n2)
{
    try{
        if ((n1.isnull() == true) || (n2.isnull() == true))
        {
            throw lineexception(0);
        }

        // a*y = mx + b, (a = 1)
        // slope: m = (y2-y1)/(x2-x1)
        // so, b = y - mx
        m = ((n2.gety()) - (n1.gety()))/((n2.getx()) - (n1.getx()));
        if (m = 0)
            throw lineexception(1);

        b = n2.gety() - m*n2.getx();
        a = 1;
        isnull_ = false;

    }
    catch(lineexception &le)
    {
        if (le.errtype() == 0) {
            isnull_ = true;
            m = a = b = 0;
            isvirtigo_ = false;
        }
        else if (le.errtype() == 1) 
        {
            isvirtigo_ = true;
            m = 1;
            a = 0;
            b = -1 * (n1.getx());
        }
    }
}

line_t::line_t (bool iiv, rational<int> im, const node_t& n):
    m(im),
    isvirtigo_(iiv)
{
    try
    {
        if (n.isnull() == true)
            throw lineexception(0);

        else if (iiv) 
            throw lineexception(1);

        a = 1;
        b = n.gety() - m*(n.getx());
        isnull_ = false;
    }
    catch(lineexception &le)
    {
        if ( le.errtype() == 0)
        {
            isnull_ = true;
            m = a = b = 0;
            isvirtigo_ = false;
        }
        else if ( le.errtype() == 1)
        {
            a = 0;
            b = (-1)*(n.getx());
            isnull_ = false;
        }
    }
}


//Don't write a copy constructor if shallow copies are ok
//
//line_t::line_t(const line_t& rhs)
//{
//    isvirtigo_ = rhs.isvirtigo();
//    m = rhs.getm();
//    a = rhs.geta();
//    b = rhs.getb();
//    isnull_ = rhs.isnull();
//}

line_t& line_t::operator=(const line_t& rhs)
{
    if ( this != & rhs)
    {
        if (rhs.isnull() == true)
        {
            m = a = b = 0;
            isvirtigo_ = false;
            isnull_ = true;
        }
        else {
            isvirtigo_ = rhs.isvirtigo();
            m = rhs.getm();
            a = rhs.geta();
            b = rhs.getb();
            isnull_ = rhs.isnull();
        }
    }
    return *this;
}


bool line_t::operator==(const line_t& rhs) const
{
    // null
    if ((rhs.isnull() == true) && (isnull() == true))
        return true;
    // virtigo line
    else if (
            (isnull()        == false) &&
            (rhs.isnull()    == false) &&
            (isvirtigo()     == true)  && 
            (rhs.isvirtigo() == true)  &&
            (getb()          == rhs.getb())
            )
        return true;
    // normal line
    else if (
            (isnull()        == false) &&
            (rhs.isnull()    == false) &&
            (isvirtigo()     == false) && 
            (rhs.isvirtigo() == false) && 
            (getm()          == rhs.getm()) &&
            (geta()          == rhs.geta()) &&
            (getb()          == rhs.getb()) 
            ) 
        return true;
    else 
        return false;
}

bool line_t::operator!=(const line_t& rhs) const
{
    return !(*this == rhs);
}
const node_t line_t::operator*(const line_t& rhs) const
{
    // mx - ay + b = 0
    //
    // (a: m, b: -a, c: -b)
    // a1*X + b1*Y = c1
    // a2*X + b2*Y = c2
    //
    // delta  = (a1 * b2) - (a2 * b1)
    // deltax = (c1 * b2) - (c2 * b1)
    // deltay = (a1 * c2) - (a2 * c1)
    if ( this == & rhs)
        return node_t();

    if ((rhs.isnull() == true) || (isnull() == true))
        return node_t();

    rational<int> delta  = (getm() * ((-1)*rhs.geta())) - (rhs.getm() * ((-1)*geta()));
    rational<int> deltax = ((-1)*getb() * ((-1)*rhs.geta())) - ((-1)*rhs.getb() * ((-1)*geta()));
    rational<int> deltay = (getm() * (-1)*rhs.getb()) - (rhs.getm() * (-1)*getb());

    if (delta == 0)
        return node_t();
    else
        return node_t(deltax/delta, deltay/delta);

}

const line_t line_t::normalline(const node_t& xnode) const
{
    // normal line to be returned
    line_t nline;

    if ( 
        (isnull() == true) || 
        (xnode.isnull() == true) || 
        (ison(xnode) == false) 
       )
        return nline;
    // if line is virtigo, nline will be a horizontal line: y = b
    if (isvirtigo() == true) 
        nline = line_t(false, 0, xnode) ;
                                                                                            
    // if line is horizontal, nline will be a virtigo line: x = -b
    else if (getm() == 0)
        nline = line_t(true, 1, xnode);
                                                                                            
    // general case
    else {
        nline = line_t(false, ((-1)*getm()),xnode);
    }
    return nline;
}

bool line_t::ison(const node_t& n) const
{
    if (
        (isnull() == false) && 
        (n.isnull() == false) && 
        ((m*(n.getx()) + b) == a*(n.gety()))
       )
        return true;
    return false;
}

bool line_t::isvirtigo() const
{return isvirtigo_;}



line_t::~line_t ()
{}  


ostream& operator<<(ostream& out, const line_t& n)
{
    if (n.isnull() == true)
        out << "Null-Line";
    else if (n.isvirtigo() == true) {
        out << "x = " << (-1)*n.getb();
    }
    else{
        out << "y = ";
        if (n.getm() == 0)
            out << n.getb();
        else if (n.getb() > 0)
            out << "(" << n.getm() << ")x + " << n.getb();
        else if (n.getb() < 0)
            out << "(" << n.getm() << ")x - " << (-1)*n.getb();
        else 
            out << "(" << n.getm() << ")x";
    }
    return out;
}

bool line_t::isnull() const
{ return isnull_; }

rational<int> line_t::getm() const
{
    if (isnull_ == true)
        throw lineexception("Cannot getm() by a null line\n");
    return m; 
}
rational<int> line_t::geta() const
{
    if (isnull_ == true)
        throw lineexception("Cannot geta() by a null line\n");
    return a; 
}
rational<int> line_t::getb() const
{
    if (isnull_ == true)
        throw lineexception("Cannot getb() by a null line\n");
    return b; 
}

