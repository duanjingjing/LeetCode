#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
{
    if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1)
        return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n, 1);
    for(int j=1; j<n; j++) {
        if(obstacleGrid[0][j]==1)
            dp[j]=0;
        else 
            dp[j] = dp[j-1];
    }

    for(int i=1; i<m; i++) {
        dp[0] = obstacleGrid[i][0] == 1?0 : dp[0];
        for(int j=1; j<n; i++) {
            dp[j] = obstacleGrid[i][j]==1?0:dp[j-1]+dp[j];
        }
    }
    return dp[n-1];
}
