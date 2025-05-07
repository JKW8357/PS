#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int st = 1, en = 1;
    int sum = 1, cnt = 0;

    while (st <= n) {
        if (sum == n) cnt++;
        if (sum >= n) sum -= st++;
        else sum += ++en;
    }

    cout << cnt << '\n';
    return 0;
}