#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(vector<int> &nums, int start, vector<int>& result, vector<vector<int> >& allSets)
{
    for(int i=start; i<nums.size(); i++)
    {
        result.push_back(nums[i]);
        allSets.push_back(result);
        findSubsets(nums, i+1, result, allSets);
        result.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &nums)
{
    vector<vector<int> > allSets;
    vector<int> result;
    allSets.push_back(result);
    sort(nums.begin(), nums.end());
    findSubsets(nums, 0, result, allSets);
    return allSets;
}

void printArray(vector<vector<int> > &result)
{
    cout << "[";
    for (int i=0; i<result.size(); i++) {
        cout << "[";
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main(int argc, char* argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > res = subsets(nums);
    printArray(res);
}
