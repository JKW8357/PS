#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool vis[1 << 9];

int bfs(int st) {
    for (int i = 0; i < (1 << 9); i++) vis[i] = false;
    queue<pii> q;
    q.push({ st, 0 });
    vis[st] = true;
    
    while (!q.empty()) {
        auto [cur, cnt] = q.front(); q.pop();
        if (cur == 0 || cur == 511) return cnt;

        int nxt;
        for (int i = 0; i < 3; i++) {
            nxt = cur;
            for (int j = 0; j < 3; j++)
                nxt ^= (1 << (i * 3 + j));
            if (vis[nxt]) continue;
            q.push({ nxt, cnt + 1 });
            vis[nxt] = true;
        }

        for (int j = 0; j < 3; j++) {
            nxt = cur;
            for (int i = 0; i < 3; i++)
                nxt ^= (1 << (i * 3 + j));
            if (vis[nxt]) continue;
            q.push({ nxt, cnt + 1 });
            vis[nxt] = true;
        }

        nxt = cur;
        for (int i = 0; i < 3; i++)
            nxt ^= (1 << (i * 3 + i));
        if (vis[nxt]) continue;
        q.push({ nxt, cnt + 1 });
        vis[nxt] = true;

        nxt = cur;
        for (int i = 0; i < 3; i++)
            nxt ^= (1 << (i * 3 + (2 - i)));
        if (vis[nxt]) continue;
        q.push({ nxt, cnt + 1 });
        vis[nxt] = true;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int st = 0;
        for (int i = 8; i >= 0; i--) {
            char ch; cin >> ch;
            if (ch == 'H') st |= (1 << i);
        }
        cout << bfs(st) << '\n';
    }

    return 0;
}