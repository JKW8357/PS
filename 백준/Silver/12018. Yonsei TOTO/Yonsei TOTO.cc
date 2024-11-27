#include <bits/stdc++.h>
using namespace std;

int lecture[105];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (n--) {
        int p, l;
        cin >> p >> l;
        for (int i = 0; i < p; i++) cin >> lecture[i];

        if (p < l) pq.push(1);
        else {
            sort(lecture, lecture + p, greater<int>());
            pq.push(lecture[l - 1]);
        }
    }

    int ans = 0;
    while (!pq.empty() && m - pq.top() >= 0) {
        m -= pq.top();
        pq.pop(); ans++;
    }
    cout << ans << '\n';

    return 0;
}