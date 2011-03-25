#include <iostream>
#include "prime.cpp"
using namespace std;
int curchk = 2;

//return smallest prime divisor of num                                         
//(check from: from)  
int pd(int from, int& num)
{
    int i = curchk;
    while ((ptable[i])||(num%i))
    {
        i++;
    }
    curchk = i;
    num /= i;
    return i;
}


int main(int argc, const char *argv[])
{
    int tt = 24;
    pt_gen(50);
    cout << pd(2,tt) << endl;
    cout << tt << endl;
    return 0;
}
