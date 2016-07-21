#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2 2 0 0 1 0 1 2
void sortColors(vector<int>& nums)
{
    int zero = 0, two = nums.size()-1;
    for(int i=0; i<=two; i++) {
        if(nums[i] == 0) {
            swap(nums[i], nums[zero]);
            zero++;
        }
        
        if (nums[i] == 2) {
            swap(nums[i], nums[two]);
            two--;
            i--;
        }
    }
}

void printArray(int a[], int n)
{
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

