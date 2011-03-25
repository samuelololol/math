#include<iostream>
using namespace std;

#define PT_COUNT 600000

bool ptable[PT_COUNT];
int pt_gen(long int ct)
{
    ptable[0] = 1;
    ptable[1] = 1;
    ptable[2] = 0;

    long int i,j;
    for (i = 2; i < ct + 1; i++) {
        if (ptable[i] == 1)
            continue;
        for (j = 2; j*i < ct + 1; j++) {
            ptable[j*i] = 1;
        }
    }
    return 0;
}

