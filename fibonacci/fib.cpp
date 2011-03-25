#include <iostream>
using namespace std;
#define FIB_COUNT  500
long int ftable[FIB_COUNT];

// fib table generator
int fibgen(int ct){
    ftable[0] = 0;
    ftable[1] = 1;
    ftable[2] = 1;
    int i;
    for (i = 3; i < ct + 1; i++) {
        ftable[i] = ftable[i-1] + ftable[i-2];
    }
    return 0;
}

// fib(num)
int fib(int num){
    if (ftable[num] == 0){
        int i;
        for (i = 3; i < num + 1; i++) {
            if (ftable[i] != 0)
                continue;
            ftable[i] = ftable[i-1] + ftable[i-2];
        }
    }
    return ftable[num];
}

// arc-fib(): mim grater than 
int arcfib(long int num)
{
    int i = 0;
    while (ftable[i]<num) {
        i++;
    }
    return i;
}

int main(int argc, const char *argv[])
{
    fibgen(50);
    cout << arcfib(227000) << endl;
    return 0;
}
