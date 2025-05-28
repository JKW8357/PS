#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string word; cin >> word;
    int m = 1 + 4 * (int)word.size();
    vector<string> board(5, string(m, '.'));

    for (int j = 0; j < m; j++) {
        int mod = (j - 1) % 12;
        char c = (mod >= 8 && mod <= 12) || mod == 7 && j != m - 1 ? '*' : '#';
        if (j % 4 == 0) board[2][j] = c;
        else if (j % 2 == 1) board[1][j] = board[3][j] = c;
        else { board[0][j] = board[4][j] = c; board[2][j] = word[j / 4]; }
    }

    for (int i = 0; i < 5; i++) cout << board[i] << '\n';
    return 0;
}