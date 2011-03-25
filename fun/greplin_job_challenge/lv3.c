#include <stdio.h>
#include <math.h>
#define TNUMB 22
double ia[] = {3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78,
               81, 92, 95, 97, 99};

double subsum(int round, int binary)
{
    int i,m;
    int result = 0;
    for (i = 0; i < round; i++) {
        m       = binary - (binary >> 1)*2;
        result += m * ia[i];
        binary  = (binary >> 1);
    }
    return result;
}

int main(int argc, const char *argv[])
{
    int i,j;
    int count = 0;
    for (i = 1; i < TNUMB; i++) {
        for (j = 0; j < pow(2,i); j++) {
            if (ia[i] == subsum(i,j))
                count++;
        }
    }
    printf(">> %d\n", count);
    return 0;
}
