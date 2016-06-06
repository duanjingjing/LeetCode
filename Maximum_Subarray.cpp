#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Max(int a, int b)
{
    return a>b?a:b;
}

int maxSubArray(vector<int>& nums)
{
    int sum=0;
    int max=0x80000000;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        max = Max(sum, max);
        if(sum < 0){
            sum = 0;
        }
    }
    return max;
}

int main(int argc, char* argv[])
{
    int num[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(num, num+9);
    cout << maxSubArray(nums)<<endl;
    return 0;
}
