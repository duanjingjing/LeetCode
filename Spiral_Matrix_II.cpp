#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > result(n, vector<int>(n, 0));
    int nlvl = n/2;
    int val=1;
    for(int i=0; i<nlvl; i++){
        int last=n-i-1;
        for(int j=i; j<last; j++){
            result[i][j]=val++;
        }
        for(int j=i; j<last; j++){
            result[j][last]=val++;
        }
        for(int j=last;j>i;j--){
            result[last][j]=val++;
        }
        for(int j=last;j>i;j--){
            result[j][i]=val++;
        }
    }

    if(n%2==1) result[n/2][n/2]=val;
    return result;
}

void printMatrix(vector<vector<int> >& result)
{
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            printf("%02d", result[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    int n=3;
    if(argc>=2) {
        n=atoi(argv[1]);
    }
    vector<vector<int> > result=generateMatrix(n);
    printMatrix(result);
    return 0;
}
