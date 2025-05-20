#include <bits/stdc++.h>
using namespace std;

queue<int> color[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) color[0].push(n);
    for (int i = 0; i < n - 1; i++) color[1].push(n - 1);
    for (int i = 0; i < n - 2; i++) color[2].push(n - 2);
    int cur = n - 3, cnt = n - 3;

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int idx = (i + j) % 3;
            if (color[idx].empty()) {
                for (int k = 0; k < cur; k++) color[idx].push(cur);
                cur--;
            }
            if (i == n - 1 && j == i && color[idx].empty()) {
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