#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> result;
    if (nums.size() > 0) {
        int start = nums[0], count = 0;
        for(vector<int>::size_type idx = 0; idx < nums.size(); idx++) {
            if(nums[idx] == (start+count)){
                count++;
            }
            else{
                char buf[1024];
                if(count == 1) snprintf(buf, sizeof(buf), "%d", start);
                else snprintf(buf, sizeof(buf), "%d->%d", start, start+count-1);
                result.push_back(buf);
                start = nums[idx];
                count = 1;
            }
        }

        char buf[1024];
        if(count == 1) snprintf(buf, sizeof(buf), "%d", start);
        else snprintf(buf, sizeof(buf), "%d->%d", start, start+count-1);
        result.push_back(buf);
    }
    return result;
}

int main(int argc, char* argv[])
{
    int num[] = {0,1,2,3,5,7,8};
    vector<int> nums(num, num+sizeof(num)/sizeof(int));

    vector<string> res = summaryRanges(nums);
    for(vector<string>::size_type idx = 0; idx != res.size(); idx++){
        cout << res[idx] << endl;
    }
}
