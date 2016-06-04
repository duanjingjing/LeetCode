#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Ideal:
 * 采用贪心的算法，每次都从coverpos中选出下一步能够走最远的距离的index作为
 * 下一步
 */
int jump(int A[], int n)
{
    int steps = 0;
    int coverPos=0;

    for (int i = 0; i<n && i<=coverPos;)
    {
        if(A[i]==0) return -1;
        if(coverPos < A[i]+i) {
            coverPos = A[i]+i;
            steps++;
        }
        
        if(coverPos >= n-1){
            return steps;
        } 

        int nextPos=0;
        int maxDistance=0;
        for(int j = i+1; j <= coverPos; j++){
            if (A[j]+j > maxDistance){
                maxDistance = A[j]+j;
                nextPos = j;
            }
        }
        i = nextPos;
    }
    return steps;
}

int main(int argc, char* argv[])
{
    int A[] = {2,3,1,1,4};
    cout << jump(A, 5) << endl;
}
