#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    n--; m--;
    cout << (n == m ? (n - 1) * (n - 1) + 1 : min(n, m) * min(n, m)) << '\n';

    return 0;
}