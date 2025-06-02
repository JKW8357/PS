#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tup;

int n, m;
int srx, sry, sbx, sby;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[10];
int dis[10][10][10][10];

pii roll(int x, int y, int dir, int& cnt) {
    cnt = 0;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    while (board[nx][ny] != '#' && board[x][y] != 'O') {
        x = nx;
        y = ny;
        nx = x + dx[dir];
        ny = y + dy[dir];
        cnt++;
    }

    return { x, y };
}

tup move(int rx, int ry, int bx, int by, int dir) {
    int rc = 0, bc = 0;
    auto [nrx, nry] = roll(rx, ry, dir, rc);
    auto [nbx, nby] = roll(bx, by, dir, bc);

    if (board[nbx][nby] == 'O') return { nrx, nry, nbx, nby };
    if (nrx == nbx && nry == nby) {
        if (rc > bc) {
            nrx -= dx[dir];
            nry -= dy[dir];
        }
        else {
            nbx -= dx[dir];
            nby -= dy[dir];
        }
    }

    return { nrx, nry, nbx, nby };
}

int bfs(int srx, int sry, int sbx, int sby) {
    queue<tup> q;
    q.push({ srx, sry, sbx, sby });
    dis[srx][sry][sbx][sby] = 0;

    while (!q.empty()) {
        auto [rx, ry, bx, by] = q.front(); q.pop();
        int curTime = dis[rx][ry][bx][by];
        if (board[rx][ry] == 'O') return curTime;

        for (int dir = 0; dir < 4; dir++) {
            auto [nrx, nry, nbx, nby] = move(rx, ry, bx, by, dir);
            if (dis[nrx][nry][nbx][nby] != -1 || board[nbx][nby] == 'O') continue;
            q.push({ nrx, nry, nbx, nby });
            dis[nrx][nry][nbx][nby] = curTime + 1;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    fill(&dis[0][0][0][0], &dis[0][0][0][0] + 10000, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') { srx = i; sry = j; board[i][j] = '.'; }
            if (board[i][j] == 'B') { sbx = i; sby = j; board[i][j] = '.'; }
        }
    }

    int ans = bfs(srx, sry, sbx, sby);
    cout << ans << '\n';

    return 0;
}