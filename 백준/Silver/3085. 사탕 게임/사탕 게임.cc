#include <bits/stdc++.h>
using namespace std;

int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[55];

int calcCnt(int x, int y, char color) {
    int res = 0;
        
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (board[i][y] == color) res = max(res, ++cnt);
        else cnt = 0;
    }

    cnt = 0;
    for (int j = 0; j < n; j++) {
        if (board[x][j] == color) res = max(res, ++cnt);
        else cnt = 0;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                swap(board[x][y], board[nx][ny]);
                ans = max(ans, calcCnt(x, y, board[x][y]));
                swap(board[x][y], board[nx][ny]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}