#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*
 *we need think about the "n" is the negative number
 *we need more wisely deal with the following case
   
 *
 */
double pow(double x, int n)
{
    bool sign = false;
    unsigned int exp = n;
    if(n < 0){
        exp = -n;
        sign = true;
    }

    double result=1.0;
    while (exp) {
        if(exp & 1){
            result *= x;
        }
        exp >>= 1;
        x *= x;
    }
    return sign ? 1/result : result;
}

int main(int argc, char* argv[])
{
    cout << pow(2.0, 3)<<endl;
    cout << pow(2.0, -3)<<endl;
}

