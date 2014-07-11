#pragma once
#include <math.h>
#include "node.h"
#include <boost/rational.hpp>

#include "exception.h"
using namespace boost;


//
// ay = mx + b
// (a == 1)
// 
//
class line_t {
    friend ostream& operator<<(ostream& out, const line_t& n);

    public:
        line_t();
        line_t(const node_t& n1, const node_t& n2);
        line_t(bool iiv, rational<int> im, const node_t& n);
        //Don't write a copy constructor 
        //      if shallow copies are ok
        //
        //line_t(const line_t& rhs);

        line_t& operator=(const line_t& rhs);
        const node_t operator*(const line_t& rhs) const;
        bool operator==(const line_t& rhs) const;
        bool operator!=(const line_t& rhs) const;

        const line_t normalline(const node_t& xnode) const;

        virtual ~line_t();
        bool isvirtigo() const;
        virtual bool ison(const node_t& n) const;
        bool isnull() const;
        rational<int> getm() const;
        rational<int> geta() const;
        rational<int> getb() const;

    private:
        rational<int> m;
        rational<int> a;
        rational<int> b;

        bool isvirtigo_;
        bool isnull_;
};

class lineexception : public myexception {
public:
    lineexception(){
        message_ = "error made by line_t\n";
    }
    lineexception(const char* message){
        message_ = message;
    }
    lineexception(const int& errtype){
        errtype_ = errtype_;
    }
    virtual const char* message() {
        return message_;
    }
    virtual const int errtype() {
        return errtype_;
    }

private:
    int errtype_;
};
