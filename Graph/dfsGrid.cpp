// tested: https://open.kattis.com/problems/countingstars
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;
bool visited[105][105];
char grid[105][105];

int dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] != '#' and !visited[nx][ny])
            dfs(nx, ny);    
    }
    return 0;
}

int main() {
    optimizar_io
    int cases = 0;

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '#' and !visited[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << "Case " << ++cases << ": " << ans << "\n";
    }
    return 0;
}
