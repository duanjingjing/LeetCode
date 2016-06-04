#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permutateHelper(vector<int>& num, int start, 
                    vector<vector<int> >& res, 
                    vector<int>& solution)
{
    if(start == num.size()) {
        res.push_back(solution);
        return ;
    }

    for(int i=start; i<num.size(); i++){
        swap(num[i], num[start]);
        solution.push_back(num[start]);
        permutateHelper(num, start+1, res, solution);
        solution.pop_back();
        swap(num[i], num[start]);
    }
}

vector<vector<int> > permutate(vector<int>& num)
{
    vector<vector<int> > res;
    if(num.size() == 0) return res;
    vector<int> solution;
    permutateHelper(num, 0, res, solution);
    return res;
}

void printMatrix(vector<vector<int> >& res)
{
    for(int i=0; i<res.size(); i++){
        cout << "[";
        for(int j=0; j<res[i].size(); j++){
            cout << " " << res[i][j];
        }
        cout << "]" << endl;
    }
}

int main(int argc, char* argv[])
{
    int A[]={1,2,3};
    vector<int> num(A, A+3);
    for (int i=0; i<num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;

    vector<vector<int> > res = permutate(num);
    printMatrix(res);
}
