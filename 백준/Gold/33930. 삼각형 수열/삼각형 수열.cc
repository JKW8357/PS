#include <bits/stdc++.h>
using namespace std;

queue<int> color[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    if (n <= 3) {
        cout << (n == 1 ? 1 : -1) << '\n';
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        int cnt = n - i;
        for (int j = 0; j < cnt; ++j) color[i].push(cnt);
    }

    int cur = n - 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int idx = (i + j) % 3;
            if (color[idx].empty()) {
                for (int k = 0; k < cur; k++) color[idx].push(cur);
                cur--;
            }

            if (color[idx].empty()) {
                cout << color[(idx + 1) % 3].front() << ' ';
                break;
            }

            cout << color[idx].front() << ' ';
            color[idx].pop();
        }
        cout << '\n';
    }

    return 0;
}