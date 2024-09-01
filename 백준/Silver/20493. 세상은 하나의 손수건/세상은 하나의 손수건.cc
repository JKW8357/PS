#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
pair<int, int> cur = { 0, 0 };

int cur_time[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    
    int dir = 0;
    for (int i = 1; i <= n; i++) {
        string turn;
        cin >> cur_time[i] >> turn;

        int straight = cur_time[i] - cur_time[i - 1];
        int nx = cur.X + dx[dir] * straight;
        int ny = cur.Y + dy[dir] * straight;

        if (turn == "left") dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;

        cur = { nx, ny };
    }

    cur.X += dx[dir] * (t - cur_time[n]);
    cur.Y += dy[dir] * (t - cur_time[n]);
    cout << cur.X << ' ' << cur.Y << '\n';

    return 0;
}