#include <iostream>
#include <vector>
#include <string>
using namespace std;


//以board上的每个cell为出发点， 利用depth first search 向上下左右四个方向搜索匹配word
//搜索的时候要考虑board的边界， cell是否已经在DFS的路径上被用过, 以及cell上的值是否与word
//的当前字符匹配， 为了跟踪DFS的路径避免同一个cell被访问多次.使用一个visited矩阵来代表board
//上任意的cell(i,j)是否已经被访问过.
bool exist(vector<vector<char> >& board, string word)
{
    if (board.empty() || board[0].empty()) return false;

    vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++) {
            if (findWord(board, visited, i, j, word, 0)) return true;
        }
    }
    return false;
}

bool findWord(vector<vector<char> >& board, vector<vector<bool> >& visited, int row, int col,
                                                                       string& word, int index)
{
    if (index == word.size()) return true;

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col] || board[row][col] != word[index])
    {
        return false;
    }

    visited[row][col] = true;
    if (findWord(board, visited, row-1, col, word, index+1)) return true;
    if (findWord(board, visited, row+1, col, word, index+1)) return true;
    if (findWord(board, visited, row, col-1, word, index+1)) return true;
    if (findWord(board, visited, row, col+1, word, index+1)) return true;
    visited[row][col] = false;
    return false;
}


