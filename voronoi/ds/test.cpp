#include <iostream>
#include <vector>
#include <algorithm>
#include "node.h"
#include "line.h"
#include "fire.h"
#include "segment.h"

using namespace std;
int main(int argc, const char *argv[])
{
    rational<int> rn1(1,3);
    rational<int> rn2(1,7);

    // node test ======================================
    node_t n1;
    node_t n2(0,1);
    node_t n3(rn1,rn2); // copy-cons used to build n3
    node_t n4(n3);
    node_t n5;
    try
    {
        n5 = n1;
    }
    catch (nodeexception &en)
    {
        cout << en.message() << endl;
        n5 = node_t();
    }
    cout << n1 << "," 
        << n2 << "," 
        << n3 << "," 
        << n4 << "," 
        << n5 << endl;
    
    cout << "if n1==n2:" << (n1==n2) << endl;
    cout << "if n5==n4:" << (n5==n4) << endl;

    // line test ======================================
    line_t l1;
    line_t l2(n1,n2);
    line_t l3(n2,n3);

    rational<int> rn3(-18,8);
    line_t l4(false, rn3, n3);
    line_t l5;
    l5 = l4;
    line_t l6 = l4.normalline(n3);
    node_t nx = l6*l4;

    cout << l1  << ","
        << l2   << ","
        << l3   << ","
        << l4   << ","
        << l5   << ","
        << l6   << endl
        << "l6xl4 cross node:" << nx << endl
        << "cross node on the line l6? " << l6.ison(nx) << endl
        << "cross node on the line l4? " << l4.ison(nx) << endl
        << "other node on the line l4? " << l4.ison(n1) << endl
        << "null line getm():" ;
    
    try {
        cout << l1.getm() << endl;
    }
    catch(lineexception& el)
    {
        cout << el.message() << endl;
    }
        

    cout << "if l2==l3:" << (l3==l2) << endl;
    cout << "if l5==l4:" << (l5==l4) << endl;

   

    return 0;
}
