#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

unordered_map<char, pair<int, int>> dir;
char board[11][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string cmd;
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

        if (cmd[i] == 'L' || cmd[i] == 'R') {
            if (board[cur.X][cur.Y] == '|') board[cur.X][cur.Y] = '+';
            if (board[cur.X][cur.Y] != '+' || board[cur.X][cur.Y] == '.') board[cur.X][cur.Y] = '-';
        }

        if (cmd[i] == 'U' || cmd[i] == 'D') {
            if (board[cur.X][cur.Y] == '-') board[cur.X][cur.Y] = '+';
            if (board[cur.X][cur.Y] != '+' || board[cur.X][cur.Y] == '.') board[cur.X][cur.Y] = '|';
        }

        if (cmd[i] == 'L' || cmd[i] == 'R') {
            if (board[nx][ny] == '|') board[nx][ny] = '+';
            if (board[nx][ny] != '+' || board[nx][ny] == '.') board[nx][ny] = '-';
        }

        if (cmd[i] == 'U' || cmd[i] == 'D') {
            if (board[nx][ny] == '-') board[nx][ny] = '+';
            if(board[nx][ny] != '+' || board[nx][ny] == '.') board[nx][ny] = '|';
        }

        cur = { nx, ny };
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}