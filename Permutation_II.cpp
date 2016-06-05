#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find(vector<int>& nums, int index, int end, int target)
{
    for(int i=index; i<end; i++){
        if(nums[i]==target){
            return true;
        }
    }
    return false;
}

void permutation(vector<int>& nums, int index, vector<int>& solution, vector<vector<int> >& res)
{
    if (index == nums.size()){
        res.push_back(solution);
        return;
    }

    for(int i=index; i<nums.size(); i++){
        if(i==index || !find(nums, index, i, nums[i])){
            swap(nums[index], nums[i]);
            solution.push_back(nums[index]);
            permutation(nums, index+1, solution, res);
            solution.pop_back();
            swap(nums[index], nums[i]);
        }
    }
}

vector<vector<int> > permute(vector<int>& nums)
{
    vector<vector<int> > res;
    if(nums.size() <= 0) return res;
    vector<int> solution;
    permutation(nums, 0, solution, res);
    return res;
}

void printMatrix(const vector<vector<int> >& res)
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
    int A[] = {1,2,1};
    vector<int> vv(A, A+3);
    vector<vector<int> > res=permute(vv);
    printMatrix(res);
}
