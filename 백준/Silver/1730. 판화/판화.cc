#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
string cmd;
char board[11][11];
unordered_map<char, pair<int, int>> dir;

void draw(int x, int y, char direction) {
    if (board[x][y] == '.' || board[x][y] == direction) board[x][y] = direction;
    else board[x][y] = '+';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> cmd;

    dir['U'] = { -1, 0 };
    dir['D'] = { 1, 0 };
    dir['L'] = { 0, -1 };
    dir['R'] = { 0, 1 };

    for (int i = 0; i < n; i++) fill(board[i], board[i] + n, '.');

    pair<int, int> cur = { 0, 0 };

    for (char c : cmd) {
        int nx = cur.X + dir[c].X;
        int ny = cur.Y + dir[c].Y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        draw(cur.X, cur.Y, (c == 'L' || c == 'R') ? '-' : '|');
        draw(nx, ny, (c == 'L' || c == 'R') ? '-' : '|');

        cur = { nx, ny };
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}