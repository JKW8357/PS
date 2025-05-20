#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, t;
int cycle[1005];
vector<int> adj[1005];
int dis[1005][1005];

int bfs() {
    queue<pii> q;
    q.push({ 1, 0 });
    dis[1][0] = 0;

    while (!q.empty()) {
        auto [curV, modT] = q.front(); q.pop();
        int curD = dis[curV][modT];
        int nxtT = (modT + 1) % t;
        if (curV == n) return curD;
        if (curV == cycle[modT]) {
            int nxtV = cycle[nxtT];
            if (dis[nxtV][nxtT] != -1) continue;
            q.push({ nxtV, nxtT });
            dis[nxtV][nxtT] = curD + 1;
        }
        else {            
            for (int nxtV : adj[curV]) {
                if (dis[nxtV][nxtT] != -1) continue;
                q.push({ nxtV, nxtT });
                dis[nxtV][nxtT] = curD + 1;
            }
            if (dis[curV][nxtT] != -1) continue;
            q.push({ curV, nxtT });
            dis[curV][nxtT] = curD + 1;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 0; i < t; i++) cin >> cycle[i];
    for (int i = 1; i <= n; i++) fill(dis[i], dis[i] + t, -1);

    int ans = bfs();
    cout << ans << '\n';

    return 0;
}