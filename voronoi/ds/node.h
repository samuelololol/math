#pragma once
#include <ostream>
#include <math.h>
#include <boost/rational.hpp>

#include "exception.h"

using namespace boost;

using std::ostream;
class node_t {

    friend ostream& operator<<(std::ostream& out, const node_t& n);
    public:
        node_t ();
        node_t (const int ix, const int iy);
        node_t (const rational<int> ix, const rational<int> iy);
        //node_t (const node_t& n);
        node_t& operator=(const node_t& n);
        ~node_t();

        bool operator<(const node_t& n) const;
        bool operator==(const node_t& n) const;
        bool operator!=(const node_t& n) const;
        // distance
        //rational<int> operator-(const node_t& n) const;

        bool isnull() const;
        rational<int> getx() const;
        rational<int> gety() const;

    private:
        rational<int> x_;
        rational<int> y_;
        bool isnull_;
};

class nodeexception : public myexception {
public:
    nodeexception(){
        message_ = "error made by node_t\n";
    }
    nodeexception(const char* message){
        message_ = message;
    }
    virtual const char* message() {
        return message_;
    }
};
