#include <vector>
#include <iostream>
using namespace std;

//n=4 and k=2, a solution is
void getCombination(int n, int k, vector<int>& solution, vector<vector<int> >& result);

vector<vector<int> > combine(int n, int k)
{
    vector<int> solution;
    vector<vector<int> > result;
    getCombination(n, k, solution, result);
    return result;
}

void getCombination(int n, int k, vector<int>& solution, vector<vector<int> >& result)
{
    if (k == 0) {
        //sort to meet Leetcode requirement
        vector<int> v = solution;
        sort(v.begin(), v.end());
        result.push_back(v);
        return;
    }

    for (int i=n; i>0; i--)
    {
        solution.push_back(i);
        getCombination(i-1, k-1, solution, result);
        solution.pop_back();
    }
}

void printResult(vector<vector<int> >& result)
{
    for (int i=0; i<result.size(); i++)
    {
        cout << "{";
        for (int j=0; j<result[i].size(); j++)
        {
            cout << " "<< result[i][j];
        }
        cout << "}" << endl;
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int n = 4, k = 2;
    vector<vector<int> > r = combine(n, k);
    printResult(r);
}
