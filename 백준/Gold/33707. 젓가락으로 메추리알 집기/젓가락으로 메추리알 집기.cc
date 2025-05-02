#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = i % 2 + 1; j <= m; j += 2) {
            cout << '?' << ' ' << i << ' ' << j << '\n'; cout << flush;
            int ans; cin >> ans;
            if (ans == 1) return 0;
        }
    }

    return 0;
}