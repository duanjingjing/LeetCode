#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minPathSum(vector<vector<int> >& grid)
{
    if(grid.empty()) return 0;
    vector<vector<int> > res(grid);

    for(int i=1; i<res[0].size(); i++) {
        res[0][i] += res[0][i-1];
    }

    for(int i=1; i<res.size(); i++) {
        res[i][0] += res[i-1][0];
    }

    for(int i=1; i<res.size(); i++) {
        for(int j=1; j<res[i].size(); j++) {
            res[i][j] = min(res[i-1][j], res[i][j-1])+val[i][j];
        }
    }
    return res[grid.size()-1][grid[0].size()-1];

}

