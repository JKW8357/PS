#include <bits/stdc++.h>
using namespace std;

bool check[75];
unordered_map<string, pair<int, int>> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; int w, d, p;
        cin >> s >> w >> d >> p;
        um[s] = { (w - 1) * 7 + d, p };
    }

    for (int i = 0; i < n; i++) {
        string s; int m;
        cin >> s >> m;
        auto& [date, p] = um[s];
        if (m >= p) check[date] = true;
    }

    int len = 0, mx = 0;
    for (int date = 0; date < 75; date++) {
        if (check[date]) len++;
        else {
            mx = max(mx, len);
            len = 0;
        }
    }

    cout << mx << '\n';
    return 0;
}