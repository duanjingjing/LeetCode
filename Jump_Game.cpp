#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canJump(vector<int>& nums)
{
    if(nums.size()<=1) return true;
    int coverPos=0;
    for(int i=0; i<nums.size();){
        if(nums[i]+i>=nums.size()-1) return true;
        if(nums[i] == 0) return false;
        coverPos=nums[i]+i;
        int maxDistance=0;
        int nextPos=0;
        for(int j=i+1; j<=coverPos; j++) {
            if(nums[j]+j>maxDistance) {
                maxDistance=nums[j]+j;
                nextPos=j;
            }
        }
        i=nextPos;
    }
    return true;
}

int main(int argc, char* argv[])
{
    int A0[]={2,3,1,1,4};
    int A1[]={3,2,1,0,4};
    vector<int> nums(A0, A0+5);
    vector<int> pnum(A1, A1+5);

    cout << canJump(nums) << endl;
    cout << canJump(pnum) << endl;
}
