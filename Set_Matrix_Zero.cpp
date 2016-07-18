#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 *Set Matrix Zeroes
 *Given a m*n, if an element is 0, set its entire row and col 0 0.
 *
 */
void setZeroes(vector<vector<int> >& matrix)
{
  
    bool* row = new bool[matrix.size()];
    bool* column = new bool[matrix[0].size()];

    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            if(matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }

    for(int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if(row[i] || column[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
