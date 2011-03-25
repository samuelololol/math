#pragma once

#include <iostream>
#include <ostream>
#include "node.h"
#include "fire.h"

using std::ostream;
class segment_t : public line_t{
    //friend std::ostream& operator<<(std::ostream& os, const segment_t& r);

public:
    segment_t();
    segment_t(const node_t& in1, const node_t& in2);
    segment_t(const fire_t& in1, const node_t& end);
    
    //virtual ~segment_t();
    //segment_t(const segment_t& rhs);
    //segment_t& operator=(const segment_t& rhs);

    //bool operator==(const segment_t& isegment) const;
    //bool ontheline(const node_t& n) const;

private:
    node_t n1;
    node_t n2;
    node_t nm; // middle node
    fire_t f1;
    fire_t f2;
};
