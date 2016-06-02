#include <iostream>
#include <map>
using namespace std;

/*
 *Idea:
 *  We can move the num to the place which the index is the num.
 *  
 *  for example, (considering the array is zero-based)
 *      1 => A[0], 2=>A[1], 3=>A[2] 
 *
 *  Then we can go through the array check the i+1==A[i], if not, just return i+1;
 *
 */


int firstMissingPositive_1(int A[], int n)
{
    if (n <= 0) return 1;
    int num;

    for (int i=0; i<n; i++){
        num=A[i];
        while(num>0 && num<n && A[num-1]!=num){
            swap(A[num-1], A[i]);
            num=A[i];
        }
    }

    for(int i=0; i<n; i++){
        if (A[i] != i+1){
            return i+1;
        }
    }

    return n+1;
}

void printArray(int A[], int n)
{
    cout << "[";
    for(int i=0; i<n; i++){
        cout << " "<<A[i];
    }
    cout << "]";
}

int main(int argc, char* argv[])
{
    int A[] = {3,4,-1,1};
    int B[] = {1,2,0};
    cout << firstMissingPositive_1(A, sizeof(A)/sizeof(int)) << endl;
    cout << firstMissingPositive_1(B, sizeof(B)/sizeof(int)) << endl;
}
