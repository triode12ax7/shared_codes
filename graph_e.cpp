#include <iostream>
#include <vector>

using namespace std;

void dfs(int row, int col, int color, vector< string >& matrix, vector< vector< int > >& is_marked) {
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
        return;
    }
    if (matrix[row][col] == '.') {
        return;
    }
    if (is_marked[row][col] != 0) {
        return;
    }

    is_marked[row][col] = color;
    dfs(row - 1, col, color, matrix, is_marked);
    dfs(row + 1, col, color, matrix, is_marked);
    dfs(row, col - 1, color, matrix, is_marked);
    dfs(row, col + 1, color, matrix, is_marked);
}
int main() {
    int m, n;
    cin >> m >> n;
    vector< string > matrix(m);
    for (int i = 0; i < m; i++) {
        cin >> matrix[i];
    }

    vector< vector< int > > is_marked(m, vector< int >(n, 0));
    int color = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!is_marked[i][j] && matrix[i][j] == '#') {
                dfs(i, j, color, matrix, is_marked);
                color += 1;
            }
        }
    }

    cout << color - 1 << "\n";
}
