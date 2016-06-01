#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int start, int target, 
                          vector<int>& solution,
                          vector<vector<int> >& result)
{
    if (target < 0) return;
    if (target == 0) {
        result.push_back(solution);
        return;
    }

    for(int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1]) {
            continue;
        }
        solution.push_back(candidates[i]);
        combinationSumHelper(candidates, i, target-candidates[i], solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int> > result;
    if (candidates.size() <= 0) return result;

    sort(candidates.begin(), candidates.end());
    vector<int> solution;
    combinationSumHelper(candidates, 0, target, solution, result);
    return result;
}

void printMatrix(vector<vector<int> > result) {
     for(int i = 0; i < result.size(); i++) {
         cout << "[";
         for (int j = 0; j < result[i].size(); j++) {
             cout << " " << result[i][j];
         }
         cout << "]" << endl;
     }
}

void printArray(vector<int>& result)
{
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int a[] = {3, 3, 2, 4, 5, 7};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    int target = 7;
    cout << "Array = " ;
    printArray(v);

    vector<vector<int> > vv = combinationSum(v, target);
    printMatrix(vv);

    return 0;
}
