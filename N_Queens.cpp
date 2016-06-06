#include <iostream>
#include <vector>
#include <string>
using namespace std;

//函数声明
void helper(vector<int>& state, int row, vector<vector<string> >& res);
bool isValid(vector<int>& state, int row, int col);
int abs(int n);

vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string> > res;
    vector<int> state(n, -1);
    helper(state, 0, res);
    return res;
}

void helper(vector<int>& state, int row, vector<vector<string> >& res)
{
    //放置第row行的皇后
    int n = state.size();
    if (row == n)
    {
        vector<string> tmp(n, string(n,'.'));
        for(int i=0; i<n; i++){
            tmp[i][state[i]]='Q';
        }
        res.push_back(tmp);
        return;
    }

    for(int col=0; col<n; col++){
        if(isValid(state, row, col)){
            state[row] = col;
            helper(state, row+1, res);
            state[row] = -1;
        }
    }
}

bool isValid(vector<int>& state, int row, int col)
{
    for(int i=0; i<row; i++){
        if(state[i] == col || abs(row-i) == abs(col-state[i])) 
            return false;
    }
    return true;
}

int abs(int n){
    return n>0?n:-n;
}

void printMatrix(vector<vector<string> >& res)
{
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << endl;
        } 
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    int n=4;
    if(argc >= 2) {
       n = atoi(argv[1]); 
    }

    vector<vector<string> > res = solveNQueens(n);
    printMatrix(res);
}
