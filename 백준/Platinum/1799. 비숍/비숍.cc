#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> board[2];
bool diag1[20];
bool diag2[20];
int res[2];

void solve(int idx, int cnt, int color) {
    if (idx == (int)board[color].size()) {
        res[color] = max(res[color], cnt);
        return;
    }

    solve(idx + 1, cnt, color);

    auto& [x, y] = board[color][idx];
    int d1 = x + y;
    int d2 = x - y + n - 1;
    if (!diag1[d1] && !diag2[d2]) {
        diag1[d1] = diag2[d2] = true;
        solve(idx + 1, cnt + 1, color);
        diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool canPlace; cin >> canPlace;
            if (!canPlace) continue;
            int color = (i + j) % 2;
            board[color].push_back({ i, j });
        }
    }

    solve(0, 0, 0);
    solve(0, 0, 1);
    int ans = res[0] + res[1];
    cout << ans << '\n';

    return 0;
}