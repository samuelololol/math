#include "segment.h"

segment_t::segment_t():
    line_t(),
    n1(),n2(),nm(),
    f1(),f2(){}

segment_t::segment_t(const node_t& in1, const node_t& in2):
    line_t(in1,in2),
    n1(in1),n2(in2),
    f1(n1,n2),f2(n2,n1)
{}

