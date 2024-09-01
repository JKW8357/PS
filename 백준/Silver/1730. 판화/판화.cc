#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
string cmd;
char board[11][11];
unordered_map<char, pair<int, int>> dir;

void draw(int idx, int x, int y) {
    if (cmd[idx] == 'L' || cmd[idx] == 'R') {
        if (board[x][y] == '|') board[x][y] = '+';
        if (board[x][y] != '+' || board[x][y] == '.') board[x][y] = '-';
    }

    if (cmd[idx] == 'U' || cmd[idx] == 'D') {
        if (board[x][y] == '-') board[x][y] = '+';
        if (board[x][y] != '+' || board[x][y] == '.') board[x][y] = '|';
    }
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
    int size = cmd.size();

    for (int i = 0; i < size; i++) {
        int nx = cur.X + dir[cmd[i]].X;
        int ny = cur.Y + dir[cmd[i]].Y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        draw(i, cur.X, cur.Y);
        draw(i, nx, ny);

        cur = { nx, ny };
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}