#include <iostream>
#include <stdio.h>
using namespace std;

int sqrt(int x) {
    if(x <= 1) return x;
    int start=0, end=x;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(x/mid == mid) return mid;
        else if(x/mid < mid) end = mid-1;
        else start = mid+1;
    }
    return end;
}


int main(int argc, char* argv[])
{
    int n = 2;
    if(argc > 1) {
        n = atoi(argv[1]);
    }

    cout << "sqrt(" << n << ")=" << sqrt(n) << endl;
    return 0;
}
