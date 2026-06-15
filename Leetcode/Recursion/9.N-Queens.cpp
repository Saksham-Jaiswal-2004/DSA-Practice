#include <iostream>
#include <vector>

using namespace std;

vector<bool> col;
vector<bool> diag;
vector<bool> antiDiag;

void makeBoard(vector<vector<string>> &board, vector<string> &path, int n)
{
    if (path.size() == n)
    {
        board.push_back(path);
        return;
    }

    int row = path.size();

    for (int c = 0; c < n; c++)
    {
        int d = row - c + (n - 1);
        int ad = row + c;

        if (col[c] || diag[d] || antiDiag[ad])
            continue;

        string s(n, '.');
        s[c] = 'Q';

        path.push_back(s);
        col[c] = true;
        diag[d] = true;
        antiDiag[ad] = true;

        makeBoard(board, path, n);

        path.pop_back();
        col[c] = false;
        diag[d] = false;
        antiDiag[ad] = false;
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> board;
    vector<string> path;

    col.resize(n, false);
    diag.resize(2 * n - 1, false);
    antiDiag.resize(2 * n - 1, false);

    makeBoard(board, path, n);

    return board;
}

int main()
{
    int n = 4;

    cout << "N: " << n << endl;

    cout << "Final Placement: " << endl;
    for (vector<string> i : solveNQueens(n))
    {
        for (string j : i)
            cout << j << endl;

        cout << endl;
    }

    return 0;
}

// 51. N-Queens
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack
// each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
// both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]