class Solution {

public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int rowValid[10] = {0}; //用于判断某一行,对于行来说这个数组可以重复使用
        int columnValid[9][10] = {0}; //用于判断某一列是否合法
        int subBoardValid[9][10] = {0}; //用于判断某一个九
    }
};
