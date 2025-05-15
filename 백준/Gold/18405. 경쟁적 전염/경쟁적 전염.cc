#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> tup;

int n, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[205][205];
bool vis[205][205];
vector<tup> virus;

int bfs(int es, int ex, int ey) {
    queue<tup> q;
    for (auto& v : virus) q.push(v);

    while (!q.empty()) {
        auto [s, id, x, y] = q.front(); q.pop();
        if (s == es) break;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny]) continue;
            board[nx][ny] = id;
            q.push({ s + 1, id, nx, ny });
            vis[nx][ny] = true;
        }
    }

    return board[ex][ey];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                virus.push_back({ 0, board[i][j], i, j });
                vis[i][j] = true;
            }
        }
    }

    sort(virus.begin(), virus.end());

    int s, x, y;
    cin >> s >> x >> y;
    cout << bfs(s, x, y) << '\n';

    return 0;
}