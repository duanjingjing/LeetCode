#include <iostream>
#include <vector>
#include <algorithm>
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

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue;
        solution.push_back(candidates[i]);
        combinationSumHelper(candidates, i+1, target-candidates[i], solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int> > result;
    if (candidates.size() <= 0) return result;

    sort(candidates.begin(), candidates.end());
    vector<int> solution;
    combinationSumHelper(candidates, 0, target, solution, result);
    return result;
}

void printArray(vector<int>& candidates)
{
    cout << "{";
    for (int i = 0; i < candidates.size(); i++) {
        cout << " " << candidates[i];
    }
    cout << "}";
}

void printMatrix(vector<vector<int> >& candidates)
{
    for (int i = 0; i < candidates.size(); i++) {
        cout << "[";
        for (int j = 0; j < candidates[i].size(); j++) {
            cout << " " << candidates[i][j];
        }
        cout << "]" << endl;
    }
}

void test(int a[], int len, int target)
{
    vector<int> v(a, a+len);
    cout << "Array = ";
    printArray(v);
    cout << "target = " << target << endl;

    vector<vector<int> > vv = combinationSum2(v, target);
    printMatrix(vv);
}

int main(int argc, char* argv[])
{
#define TEST(a, t) test(a, sizeof(a)/sizeof(int), t)
    int a[] = {4, 2, 3, 3, 5, 7};
    int target = 7;
    TEST(a, target);

}
