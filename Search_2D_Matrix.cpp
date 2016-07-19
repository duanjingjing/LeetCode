#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    int row = matrix.size();
    int col = row>0 ? matrix[0].size() : 0;

    int len = row*col;
    int low = 0, high = len-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        int r = mid/col;
        int c = mid%col;

        int n = matrix[r][n];
        if (n == target) return true;
        else if(n < target) low = mid+1;
        else high = mid-1;
    }

    return false;
}

