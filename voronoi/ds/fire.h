#pragma once

#include <iostream>
#include <ostream>
#include "node.h"
#include "line.h"

using std::ostream;
class fire_t : public line_t
{
    friend ostream& operator<<(ostream& out, const fire_t& f);

public:
    fire_t();
    fire_t(const node_t& start, const node_t& n2);
    fire_t(const node_t& start, const line_t& l1, bool side);

    // for deep copy
    fire_t(const fire_t& rhs);
    fire_t& operator=(const fire_t& ifire);

    bool operator==(const fire_t& ifire) const;
    bool operator!=(const fire_t& ifire) const;


    virtual ~fire_t ();
    bool direction() const;
    node_t getsnode() const;

private:
    node_t startnode;
    bool direction_;
};

