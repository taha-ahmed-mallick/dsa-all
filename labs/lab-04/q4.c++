#include <iostream>
#include <vector>
using namespace std;

bool dfs(const vector<vector<char>> &grid, vector<vector<bool>> &visited, size_t r, size_t c, size_t index, const string &word)
{
    if (index == word.size())
        return true;
    if (r >= grid.size() || c >= grid[0].size() || grid[r][c] != word[index] || visited[r][c])
        return false;
    visited[r][c] = true;
    bool found = dfs(grid, visited, r + 1, c, index + 1, word) ||
                 dfs(grid, visited, r - 1, c, index + 1, word) ||
                 dfs(grid, visited, r, c + 1, index + 1, word) ||
                 dfs(grid, visited, r, c - 1, index + 1, word);
    visited[r][c] = false;
    return found;
}

bool exist(const vector<vector<char>> &grid, const string &word)
{
    size_t rows = grid.size();
    size_t cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
            if (grid[r][c] == word[0] && dfs(grid, visited, r, c, 0, word))
                return true;
    }
    return false;
}

int main()
{
    size_t m, n;
    cout << "Enter the size of the grid:\n";
    cout << "Rows: ";
    cin >> m;
    cout << "Cols: ";
    cin >> n;
    vector<vector<char>> grid(m, vector<char>(n, '.'));
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            cin >> grid[i][j];
    string word;
    cout << "Enter the word to find: ";
    cin >> word;
    cout << "\nThe Grid:\n";
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl
         << "Does the word exist? " << (exist(grid, word) ? "Yes" : "No") << endl;
    return 0;
}