#include <bits/stdc++.h>
using namespace std;

int stones[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, e;
    cin >> n >> s >> e;
    if (s > e) swap(s, e);
    for (int i = 1; i <= n; i++) cin >> stones[i];
    int k; cin >> k;

    int mn = e - s + 1;
    int mx = 0;
    for (int i = s; i >= 1; i--) {
        mx += stones[i];
        if (stones[i] == 1) break;
    }
    for (int i = s + 1; i <= e - 1; i++) mx += stones[i];
    for (int i = e; i <= n; i++) {
        mx += stones[i];
        if (stones[i] == 1) break;
    }

    cout << (int)(mn <= k && k <= mx) << '\n';
    return 0;
}