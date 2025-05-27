#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
int A, B, C;
int a, b, c;
int sum;
pii cur;
string s;

vector<vector<char>> vis(2005, vector<char>(2005, ' '));
vector<vector<pii>> p(2005, vector<pii>(2005, { -1, -1 }));
string track;

pii bfs(int A, int B) {
    queue<pair<int, int>> q;
    q.push({ A, B });
    vis[A][B] = true;

    while (!q.empty()) {
        auto [curA, curB] = q.front(); q.pop();
        int curC = sum - curA - curB;
        if (curA == curB && curB == curC) return { curA, curB };
        int nxtA, nxtB, nxtC;

        nxtA = curA + a, nxtB = curB, nxtC = curC - a;
        if (min({ nxtA, nxtB, nxtC }) > 0 && max({ nxtA, nxtB, nxtC }) < 2 * n && vis[nxtA][nxtB] == ' ') {
            q.push({ nxtA, nxtB });
            vis[nxtA][nxtB] = 'A';
            p[nxtA][nxtB] = { curA, curB };
        }

        nxtA = curA - b, nxtB = curB + b, nxtC = curC;
        if (min({ nxtA, nxtB, nxtC }) > 0 && max({ nxtA, nxtB, nxtC }) < 2 * n && vis[nxtA][nxtB] == ' ') {
            q.push({ nxtA, nxtB });
            vis[nxtA][nxtB] = 'B';
            p[nxtA][nxtB] = { curA, curB };
        }

        nxtA = curA, nxtB = curB - c, nxtC = curC + c;
        if (min({ nxtA, nxtB, nxtC }) > 0 && max({ nxtA, nxtB, nxtC }) < 2 * n && vis[nxtA][nxtB] == ' ') {
            q.push({ nxtA, nxtB });
            vis[nxtA][nxtB] = 'C';
            p[nxtA][nxtB] = { curA, curB };
        }
    }

    return { -1, -1 };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> A >> B >> C;
    cin >> a >> b >> c;
    sum = A + B + C;

    auto [curA, curB] = bfs(A, B);
    if (curA == -1 && curB == -1) {
        cout << -1 << '\n';
        return 0;
    }

    while (p[curA][curB] != make_pair(-1, -1)) {
        track += vis[curA][curB];
        tie(curA, curB) = p[curA][curB];
    }

    reverse(track.begin(), track.end());
    cout << track.size() << '\n' << track << '\n';

    return 0;
}