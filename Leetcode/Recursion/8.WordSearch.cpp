#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index, vector<vector<bool>> &visited)
{

    if (index == word.size())
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;

    if (visited[i][j] || board[i][j] != word[index])
        return false;

    visited[i][j] = true;

    bool found = dfs(board, word, i + 1, j, index + 1, visited) || dfs(board, word, i - 1, j, index + 1, visited) || dfs(board, word, i, j + 1, index + 1, visited) || dfs(board, word, i, j - 1, index + 1, visited);

    visited[i][j] = false;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(board, word, i, j, 0, visited))
            return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> data = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    cout << "Grid" << endl;
    for (vector<char> i : data)
    {
        for (char j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "Word: " << word << endl;
    cout << "Does Exist: " << bool(exist(data, word)) << endl;

    return 0;
}

// 79. Word Search
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally
// or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false