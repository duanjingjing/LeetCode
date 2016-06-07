#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
 *m和n可以不同，一层一层来处理.对于第i层来说,最后一行为lastRow=m-1-i, 最后一列为lastCol=n-1-i.
 * 层数为min(m,n)来决定
 *2.当min(m,n)为奇数时，最后一层为一行或者一列，需要特殊处理
 *
 */
vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    vector<int> ret;
    if (matrix.empty() || matrix[0].empty()) return ret;
    int m = matrix.size();
    int n = matrix[0].size();
    int level = (min(m,n)+1)/2;

    for (int i=0; i<level; i++){
        int lastRow = m-1-i;
        int lastCol = n-1-i;
        if(lastRow==i) {
            for(int j=i;j<=lastCol; j++){
                ret.push_back(matrix[i][j]);
            }
        }
        else if (lastCol==i){
            for (int j=i; j<=lastRow; j++){
                ret.push_back(matrix[j][i]);
            }
        }
        else{
            for (int j=i; j<lastCol; j++){
                ret.push_back(matrix[i][j]);
            }                
            for (int j=i; j<lastRow; j++) {
                ret.push_back(matrix[j][lastCol]);               
            }
            for (int j=lastCol; j>i; j--){
                ret.push_back(matrix[lastRow][j]);
            }
            for (int j=lastRow; j>i; j--) {
                ret.push_back(matrix[j][i]);
            }
        }
    }
    return ret;
}

vector<vector<int> > createMatrix(int n, int m)
{
    vector<vector<int> > vv;
    int cnt=1;
    for (int i=0; i<n; i++) {
        vector<int> v;
        for(int j=0; j<m; j++) {
            v.push_back(cnt++);
        }
        vv.push_back(v);
    }
    return vv;
}

void printArray(vector<int>& v)
{
    cout << "[";
    for(int j=0; j<v.size(); j++){
        printf("%02d", v[j]);
    }
    cout << "]"<<endl;
}

void printMatrix(vector<vector<int> >& v)
{
    for (int i=0; i<v.size(); i++){
        printArray(v[i]);
    }
    cout << endl;
}

int main(int argc, char* argv[])  {
    int n=3,m=3;
    if(argc >= 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    vector<vector<int> > matrix=createMatrix(n, m);
    printMatrix(matrix);
    vector<int> v = spiralOrder(matrix);
    printArray(v);
    return 0;
}
