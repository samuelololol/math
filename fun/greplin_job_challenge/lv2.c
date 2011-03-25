#include <stdio.h>
#include <stdlib.h>

#define TEST_PATTERN 227000
#define PT_COUNT 600000
#define FIB_COUNT  500

int ptable[PT_COUNT];
long int ftable[FIB_COUNT];
int pdcurchk = 2;

// prime table generator
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

// return smallest prime divisor of num
// (check from: from)
long int pd(int from,long int* num)
{
    int i = from;
    while ((ptable[i])||(*num%i))
    {
        i++;
    }
    pdcurchk = i;
    *num /= i;
    return i;
}


int main(int argc, const char *argv[])
{
    fibgen(50);
    int arcf = arcfib(TEST_PATTERN);
    long int f = fib(arcf);
    pt_gen(f);
    while (ptable[f])            // prime: 0
    {                            // comb:  1
        printf("x = fib(%d) = %ld > 227000\n",arcf,f);
        arcf++;
        f = fib(arcf);
        pt_gen(f);
    }
    printf("x = fib(%d) = %ld > 227000, and is a prime\n",arcf,f);
    long int x = f + 1;
    long int tpd = 1;
    long int result = 0;
    printf("its primer divisors");
    while(x != 1)
    {
        tpd = pd(pdcurchk, &x);
        result += tpd;
        printf(", %ld",tpd);
    }

    printf("\nsum up result: %ld\n",result);
    return 0;
}
